from CRABClient.UserUtilities import config
# getUsernameFromSiteDB
#from WMCore.Configuration import Configuration
#config = Configuration()
config=config()
config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'MC_BG'
config.section_('JobType')
config.JobType.psetName = 'run_mc2018_102X.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ["ggtree_mc.root"]
#config.JobType.inputFiles = ['Fall17_17Nov2017BCDEF_V6_DATA.db','Fall17_17Nov2017_V6_MC.db']
#config.JobType.maxMemoryMB = 2500
config.JobType.sendExternalFolder = True
config.JobType.allowUndistributedCMSSW = True
config.section_('Data')
#config.Data.unitsPerJob = 1
#config.Data.inputDBS = 'phys03'
#config.Data.splitting = 'FileBased'
config.Data.splitting = 'Automatic'
#config.Data.outLFNDirBase = '/store/user/abdollah/BoostedH/2018_v1/MC/'
config.Data.outLFNDirBase = '/eos/uscms/store/group/lpcggntuples/ggNtuples/13TeV/BoostH/2018/MC'
config.Data.allowNonValidInputDataset = True
#config.Data.ignoreLocality= True
config.section_('User')
config.section_('Site')
#config.Site.whitelist = ['T1_US_FNAL']
config.Site.storageSite = 'T3_US_FNALLPC'
#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#/eos/uscms/store/group/lpcggntuples/ggNtuples/13TeV/mc/
#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'MC_2018_v3'

    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException as hte:
            print "Failed submitting task: %s" % (hte.headers)
        except ClientException as cle:
            print "Failed submitting task: %s" % (cle)

    #############################################################################################
    ## From now on that's what users should modify: this is the a-la-CRAB2 configuration part. ##
    #############################################################################################

#Samples_test= [
#
#    ["JJH0PMToTauTauPlusZeroJets", "/JJH0PMToTauTauPlusZeroJets_Filtered_M125_TuneCP5_13TeV-mcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"]
#    ]

Samples= [
   
        

#["JJH0PMToTauTauPlusZeroJets", "/JJH0PMToTauTauPlusZeroJets_Filtered_M125_TuneCP5_13TeV-mcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["JJH0PMToTauTauPlusOneJets", "/JJH0PMToTauTauPlusOneJets_Filtered_M125_TuneCP5_13TeV-mcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],


["JJH0PMToTauTauPlusTwoJets", "/JJH0PMToTauTauPlusTwoJets_Filtered_M125_TuneCP5_13TeV-mcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],

# DY PtBins

["DYJetsToLL_Pt-50To100", "/DYJetsToLL_Pt-50To100_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],

#["DYJetsToLL_Pt-100To250", "/DYJetsToLL_Pt-100To250_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["DYJetsToLL_Pt-250To400", "/DYJetsToLL_Pt-250To400_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["DYJetsToLL_Pt-400To650", "/DYJetsToLL_Pt-400To650_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["DYJetsToLL_Pt-650ToInf", "/DYJetsToLL_Pt-650ToInf_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],


# WJet ptBins

#["WJetsToLNu_Pt-50To100", "/WJetsToLNu_Pt-50To100_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["WJetsToLNu_Pt-100To250", "/WJetsToLNu_Pt-100To250_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["WJetsToLNu_Pt-250To400", "/WJetsToLNu_Pt-250To400_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#
#
#["WJetsToLNu_Pt-400To600", "/WJetsToLNu_Pt-400To600_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],


#["WJetsToLNu_Pt-600ToInf", "/WJetsToLNu_Pt-600ToInf_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/MINIAODSIM"],
    


# Higgs Powheg


#["ZHToTauTau_M125", "/ZHToTauTau_M125_13TeV_powheg_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/MINIAODSIM"],
#
#["WplusHToTauTau_M125", "/WplusHToTauTau_M125_13TeV_powheg_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/MINIAODSIM"],
#
#["WminusHToTauTau_M125", "/WminusHToTauTau_M125_13TeV_powheg_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/MINIAODSIM"],
#
#["VBFHToTauTau_M125", "/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/MINIAODSIM"],

#["GluGluHToTauTau_M125", "/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/MINIAODSIM"],




#### TT

#["TTToHadronic_v1", "/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#["TTToHadronic_v2", "/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext2-v2/MINIAODSIM"],
#
#["TTToSemiLeptonic_v1", "/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],
#["TTToSemiLeptonic_v2", "/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext3-v2/MINIAODSIM"],
#
#["TTTo2L2Nu", "/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"],





          



          



#['Tbar-tchan','/ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#['T-tchan','/ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
['Tbar-tW','/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/MINIAODSIM'],
['T-tW','/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/MINIAODSIM'],


          
#
#
#
#['VV2l2nu', '/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#####    'WW1l1nu2q' , 'WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1'], Buggy
#['WZ1l1nu2q_v1', '/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#['WZ1l1nu2q_v2', '/WZTo1L1Nu2Q_13TeV_TuneCP5_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2/MINIAODSIM'],
#['WZ1l3nu' , '/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#['WZ2l2q' , '/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#['WZ3l1nu_v1', '/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#['WZ3l1nu_v2', '/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2/MINIAODSIM'],
#['ZZ2l2q_v1' ,'/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],
#['ZZ2l2q_v2' ,'/ZZTo2L2Q_13TeV_TuneCP5_amcatnloFXFX_madspin_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2/MINIAODSIM'],
#['ZZ4l', '/ZZTo4L_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'],

]



for sam in Samples:
#for sam in Samples_test:
    print sam[0], sam[1]
    config.General.requestName = sam[0]
    config.Data.inputDataset = sam[1]
    submit(config)
    
