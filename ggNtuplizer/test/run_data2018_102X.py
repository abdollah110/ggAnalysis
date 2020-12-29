import FWCore.ParameterSet.Config as cms

process = cms.Process('ggKit')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
#process.load("Configuration.Geometry.GeometryIdeal_cff" )
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff" )
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_v11', '') #2018ABC
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_Prompt_v14', '') #2018D

#process.Tracer = cms.Service("Tracer")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
#        'file:/data4/cmkuo/testfiles/DoubleMuon_Run2018C_17Sep2018.root'
        '/store/data/Run2018B/SingleMuon/MINIAOD/17Sep2018-v1/00000/006BBA14-C3C6-FA42-ADEF-35D43DA86202.root'
        #'file:/data4/cmkuo/testfiles/DoubleMuon_Run2018D_PR.root'
        )
                            )

#process.load("PhysicsTools.PatAlgos.patSequences_cff")

process.load( "PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff" )
process.load( "PhysicsTools.PatAlgos.triggerLayer1.triggerProducer_cff" )
process.load( "PhysicsTools.PatAlgos.selectionLayer1.selectedPatCandidates_cff" )

### fix a bug in the ECAL-Tracker momentum combination when applying the scale and smearing
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process,
                       runVID=True,
                       era='2018-Prompt',
                       eleIDModules=['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Fall17_94X_V2_cff',
                                     'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV70_cff',
                                     'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_iso_V2_cff',
                                     'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_noIso_V2_cff'],
                       phoIDModules=['RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Fall17_94X_V2_cff',
                                     'RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V2_cff']
                       )

#from PhysicsTools.PatAlgos.tools.cmsswVersionTools import *
from PhysicsTools.PatAlgos.tools.coreTools import *
runOnData( process,  names=['Photons', 'Electrons','Muons','Taus','Jets'], outputModules = [] )
#runOnData( process, outputModules = [] )
#removeMCMatching(process, names=['All'], outputModules=[])

process.TFileService = cms.Service("TFileService", fileName = cms.string('ggtree_data.root'))

### update JEC
process.load("PhysicsTools.PatAlgos.producersLayer1.jetUpdater_cff")
process.jetCorrFactors = process.updatedPatJetCorrFactors.clone(
    src = cms.InputTag("slimmedJets"),
    levels = ['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual'],
    payload = 'AK4PFchs') 

process.slimmedJetsJEC = process.updatedPatJets.clone(
    jetSource = cms.InputTag("slimmedJets"),
    jetCorrFactorsSource = cms.VInputTag(cms.InputTag("jetCorrFactors"))
    )

### reduce effect of high eta EE noise on the PF MET measurement
from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD
runMetCorAndUncFromMiniAOD (
        process,
        isData = True, # false for MC
        fixEE2017 = True,
        fixEE2017Params = {'userawPt': True, 'ptThreshold':50.0, 'minEtaThreshold':2.65, 'maxEtaThreshold': 3.139} ,
        postfix = "ModifiedMET"
)

process.load("ggAnalysis.ggNtuplizer.ggNtuplizer_miniAOD_cfi")
process.ggNtuplizer.year=cms.int32(2018)
process.ggNtuplizer.doGenParticles=cms.bool(False)
process.ggNtuplizer.dumpPFPhotons=cms.bool(False)
process.ggNtuplizer.dumpHFElectrons=cms.bool(False)
process.ggNtuplizer.dumpJets=cms.bool(True)
process.ggNtuplizer.dumpAK8Jets=cms.bool(True)
process.ggNtuplizer.dumpSoftDrop= cms.bool(False)
process.ggNtuplizer.dumpTaus=cms.bool(False)
process.ggNtuplizer.dumpBoostedTaus=cms.bool(True)
process.ggNtuplizer.ak4JetSrc=cms.InputTag("slimmedJetsJEC")
process.ggNtuplizer.pfMETLabel=cms.InputTag("slimmedMETsModifiedMET")
process.ggNtuplizer.addFilterInfoMINIAOD=cms.bool(True)
process.load("ggAnalysis.ggNtuplizer.ggMETFilters_cff")

process.cleanedMu = cms.EDProducer("PATMuonCleanerBySegments",
                                   src = cms.InputTag("slimmedMuons"),
                                   preselection = cms.string("track.isNonnull"),
                                   passthrough = cms.string("isGlobalMuon && numberOfMatches >= 2"),
                                   fractionOfSharedSegments = cms.double(0.499))

########################################################################################
# A new boostedTau collection is made here and the overlap is removed
########################################################################################
from RecoTauTag.Configuration.boostedHPSPFTaus_cff import ca8PFJetsCHSprunedForBoostedTaus
process.ca8PFJetsCHSprunedForBoostedTausPAT = ca8PFJetsCHSprunedForBoostedTaus.clone(
                        src=cms.InputTag("packedPFCandidates"),
                        jetCollInstanceName = cms.string('subJetsForSeedingBoostedTausPAT')
                )
cleanedBoostedTau = cms.EDProducer("PATBoostedTauCleaner",
   src = cms.InputTag('slimmedTausBoosted'),
   pfcands = cms.InputTag('packedPFCandidates'),
   vtxLabel= cms.InputTag('offlineSlimmedPrimaryVertices'),
   ca8JetSrc = cms.InputTag('ca8PFJetsCHSprunedForBoostedTausPAT','subJetsForSeedingBoostedTausPAT'),
   removeOverLap = cms.bool(True),
   )
setattr(process, "cleanedSlimmedTausBoosted", cleanedBoostedTau)


########################################################################################
# Rerun boostedTau Id
########################################################################################
from RecoTauTag.RecoTau.TauDiscriminatorTools import noPrediscriminants
process.load('RecoTauTag.Configuration.loadRecoTauTagMVAsFromPrepDB_cfi')
from RecoTauTag.RecoTau.PATTauDiscriminationByMVAIsolationRun2_cff import *
#anti-electron
from RecoTauTag.RecoTau.PATTauDiscriminationAgainstElectronMVA6_cfi import *

updatedBoostedTauName = "slimmedBoostedTausNewID" #name of pat::Tau collection with new tau-Ids
import RecoTauTag.RecoTau.tools.runBoostedTauIdMVA as tauIdConfig
#import BoostTau.BoostAnalyzer.runBoostedTauIdMVA as tauIdConfig
boostedTauIdEmbedder = tauIdConfig.BoostedTauIDEmbedder(process, cms, debug = False,
                    updatedTauName = updatedBoostedTauName,
                    PATTauProducer = cms.InputTag('cleanedSlimmedTausBoosted'),
                    srcChargedIsoPtSum = cms.string('chargedIsoPtSumNoOverLap'),
                    srcNeutralIsoPtSum = cms.string('neutralIsoPtSumNoOverLap'),
                    toKeep = [
#                                "2017v2", "dR0p32017v2", "newDM2017v2", #classic MVAIso tau-Ids
#                               "deepTau2017v1", #deepTau Tau-Ids
#                               "DPFTau_2016_v0", #D[eep]PF[low] Tau-Id
                                "2017v2","deepTau2017v1","againstEle2018"
                               ])
boostedTauIdEmbedder.runTauID()

########################################################################################

process.p = cms.Path(
    process.fullPatMetSequenceModifiedMET *
    process.egammaPostRecoSeq *
    process.cleanedMu *
    process.ggMETFiltersSequence *
    process.jetCorrFactors *
    process.slimmedJetsJEC *
    process.ca8PFJetsCHSprunedForBoostedTausPAT *
    getattr(process, "cleanedSlimmedTausBoosted") *
    process.rerunMvaIsolationBoostSequence *
    getattr(process,updatedBoostedTauName) *
    process.ggNtuplizer
    )

#print process.dumpPython()
