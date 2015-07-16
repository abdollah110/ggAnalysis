import FWCore.ParameterSet.Config as cms

process = cms.Process('ggKit')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc')
process.load("Configuration.StandardSequences.MagneticField_cff")

#process.Tracer = cms.Service("Tracer")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5000) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
        #'file:/data4/cmkuo/testfiles/8CEEB179-5527-E511-BFA8-02163E01420D.root' # miniAOD
        #'file:/data4/cmkuo/testfiles/GJet_pt_15to6000_13TeV_Spring15_Asympt50ns_MCRUN2_74_V9A-v3.root'
        #'file:/data4/cmkuo/testfiles/DYJetsToLL_M50_13TeV_Spring15_Asympt50ns_MCRUN2_74_V9A-v3.root'
        #'file:/data4/cmkuo/testfiles/WJetsToLNu_13TeV_Spring15_Asympt25ns_MCRUN2_74_V9-v1.root'
        'file:/data4/cmkuo/testfiles/TTJets_amcatnloFXFX-pythia813TeV_Asympt25ns_MCRUN2_74_V9-v1.root'
        #'file:/data4/cmkuo/testfiles/WZ_13TeV_Spring15_Asympt25ns_MCRUN2_74_V9-v1.root'
        #'/store/mc/RunIISpring15DR74/WminusH_HToZZTo4L_M125_13TeV_powheg-minlo-HWJ_JHUgen_pythia8/AODSIM/Asympt25ns_MCRUN2_74_V9-v2/70000/04AFB8D8-900C-E511-8FA1-3417EBE6471A.root'
        ))

#process.load("PhysicsTools.PatAlgos.patSequences_cff")

process.load( "PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff" )
process.load( "PhysicsTools.PatAlgos.selectionLayer1.selectedPatCandidates_cff" )

#from PhysicsTools.PatAlgos.tools.cmsswVersionTools import *
#from PhysicsTools.PatAlgos.tools.coreTools import *
#runOnData( process, outputModules = [] )
#removeMCMatching(process, names=['All'], outputModules=[])

process.TFileService = cms.Service("TFileService", fileName = cms.string('ggtree_mc.root'))

#####VID framework####################
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
# turn on VID producer, indicate data format  to be
# DataFormat.AOD or DataFormat.MiniAOD, as appropriate 

useAOD = True

if useAOD == True :
    dataFormat = DataFormat.AOD
    process.load("ggAnalysis.ggNtuplizer.ggNtuplizer_cfi")
    from JMEAnalysis.JetToolbox.jetToolbox_cff import *
    jetToolbox( process, 'ak4', 'ak4PFJetsCHS', 'out', miniAOD= False, addSoftDrop=True, addSoftDropSubjets=True, addNsub=True )
    jetToolbox( process, 'ak8', 'ak8PFJetsCHS', 'out', miniAOD= False, addSoftDrop=True, addSoftDropSubjets=True, addNsub=True )


else :
    dataFormat = DataFormat.MiniAOD
    process.load("ggAnalysis.ggNtuplizer.ggNtuplizer_miniAOD_cfi")

process.ggNtuplizer.isAOD=cms.bool(useAOD)
process.ggNtuplizer.doGenParticles=cms.bool(True)
process.ggNtuplizer.dumpSubJets=cms.bool(True)
process.ggNtuplizer.dumpJets=cms.bool(True)
process.ggNtuplizer.dumpTaus=cms.bool(True)

switchOnVIDElectronIdProducer(process, dataFormat)
switchOnVIDPhotonIdProducer(process, dataFormat)

# define which IDs we want to produce
my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_PHYS14_PU20bx25_V2_cff',
                 'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV60_cff',
                 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_PHYS14_PU20bx25_nonTrig_V1_cff']

#add them to the VID producer
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)
    
my_phoid_modules = ['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_PHYS14_PU20bx25_V2_cff',
                    'RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Spring15_50ns_nonTrig_V0_cff']

#add them to the VID producer
for idmod in my_phoid_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection)

process.p = cms.Path(
    ###process.egmGsfElectronIDSequence
    # process.mvaTrigV050nsCSA14
    # + process.mvaTrigV025nsCSA14
    # + process.mvaNonTrigV050nsCSA14
    # + process.mvaNonTrigV025nsCSA14
    # + process.mvaNonTrigV025nsPHYS14 
#    process.patDefaultSequence *
    process.egmGsfElectronIDSequence 
    * process.egmPhotonIDSequence 
    * process.ggNtuplizer
    )


#print process.dumpPython()
