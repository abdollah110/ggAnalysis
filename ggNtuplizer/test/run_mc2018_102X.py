import FWCore.ParameterSet.Config as cms

process = cms.Process('ggKit')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
#process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '102X_upgrade2018_realistic_v18')

#process.Tracer = cms.Service("Tracer")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
#        'file:/data4/cmkuo/testfiles/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIAutumn18MiniAOD.root'
    '/store/mc/RunIIAutumn18MiniAOD/GluGluHToTauTau_M125_13TeV_powheg_pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v2/100000/0367CE5C-D121-5748-93D3-528A4B1DFDA5.root'
        ))

#process.load("PhysicsTools.PatAlgos.patSequences_cff")

process.load( "PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff" )
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

process.TFileService = cms.Service("TFileService", fileName = cms.string('ggtree_mc.root'))

### update JEC
process.load("PhysicsTools.PatAlgos.producersLayer1.jetUpdater_cff")
process.jetCorrFactors = process.updatedPatJetCorrFactors.clone(
    src = cms.InputTag("slimmedJets"),
    levels = ['L1FastJet', 'L2Relative', 'L3Absolute'],
    payload = 'AK4PFchs') 

process.slimmedJetsJEC = process.updatedPatJets.clone(
    jetSource = cms.InputTag("slimmedJets"),
    jetCorrFactorsSource = cms.VInputTag(cms.InputTag("jetCorrFactors"))
    )

### reduce effect of high eta EE noise on the PF MET measurement
from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD
runMetCorAndUncFromMiniAOD (
        process,
        isData = False, # false for MC
        fixEE2017 = True,
        fixEE2017Params = {'userawPt': True, 'ptThreshold':50.0, 'minEtaThreshold':2.65, 'maxEtaThreshold': 3.139} ,
        postfix = "ModifiedMET"
)

# random generator for jet smearing
process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
                                                   ggNtuplizer  = cms.PSet(
        initialSeed = cms.untracked.uint32(201678),
        engineName = cms.untracked.string('TRandom3')
        )
                                                   )

process.load("ggAnalysis.ggNtuplizer.ggNtuplizer_miniAOD_cfi")
process.ggNtuplizer.year=cms.int32(2018)
process.ggNtuplizer.doGenParticles=cms.bool(True)
process.ggNtuplizer.runL1ECALPrefire=cms.bool(False)
process.ggNtuplizer.dumpPFPhotons=cms.bool(False)
process.ggNtuplizer.dumpHFElectrons=cms.bool(False)
process.ggNtuplizer.dumpJets=cms.bool(True)
process.ggNtuplizer.dumpAK8Jets=cms.bool(False)
process.ggNtuplizer.dumpSoftDrop= cms.bool(False)
process.ggNtuplizer.dumpTaus=cms.bool(False)
process.ggNtuplizer.dumpBoostedTaus=cms.bool(True)
process.ggNtuplizer.triggerEvent=cms.InputTag("slimmedPatTrigger", "", "PAT")
process.ggNtuplizer.ak4JetSrc=cms.InputTag("slimmedJetsJEC")
process.ggNtuplizer.pfMETLabel=cms.InputTag("slimmedMETsModifiedMET")
process.ggNtuplizer.TypeIPFMET_RootFile=cms.string("HTT-utilities/RecoilCorrections/data/TypeI-PFMet_Run2018.root")
process.ggNtuplizer.MetSys_RootFile=cms.string("HTT-utilities/RecoilCorrections/data/PFMEtSys_2017.root")
    
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
    process.jetCorrFactors *
    process.slimmedJetsJEC *
    process.ca8PFJetsCHSprunedForBoostedTausPAT *
    getattr(process, "cleanedSlimmedTausBoosted") *
    process.rerunMvaIsolationBoostSequence *
    getattr(process,updatedBoostedTauName) *
    process.ggNtuplizer
    )

#print process.dumpPython()
