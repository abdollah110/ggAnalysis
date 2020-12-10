from CRABClient.UserUtilities import config
#from WMCore.Configuration import Configuration
#config = Configuration()
config=config()
config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'Data'
config.section_('JobType')
config.JobType.psetName = 'run_data2016_94X.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['ggtree_data.root']
#config.JobType.inputFiles = ['Fall17_17Nov2017BCDEF_V6_DATA.db','Fall17_17Nov2017_V6_MC.db']
#config.JobType.maxMemoryMB = 3000
config.JobType.allowUndistributedCMSSW = True
config.JobType.sendExternalFolder = True
config.JobType.allowUndistributedCMSSW = True
config.section_('Data')
config.Data.unitsPerJob = 30
config.Data.splitting = 'LumiBased'
config.Data.lumiMask = 'Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.runRange = '271036-284044'
config.Data.outLFNDirBase = '/store/group/lpcggntuples/ggNtuples/13TeV/BoostH/2016/Data'
#config.Data.useParent = True
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC'


if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'Data_2016_v1'

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

    samples = [
    
    "/SingleMuon/Run2016B-17Jul2018_ver1-v1/MINIAOD",
    "/SingleMuon/Run2016B-17Jul2018_ver2-v1/MINIAOD",
    "/SingleMuon/Run2016C-17Jul2018-v1/MINIAOD",
    "/SingleMuon/Run2016D-17Jul2018-v1/MINIAOD",
    "/SingleMuon/Run2016E-17Jul2018-v1/MINIAOD",
    "/SingleMuon/Run2016F-17Jul2018-v1/MINIAOD",
    "/SingleMuon/Run2016G-17Jul2018-v1/MINIAOD",
    "/SingleMuon/Run2016H-17Jul2018-v1/MINIAOD",

    "/SingleElectron/Run2016B-17Jul2018_ver1-v1/MINIAOD",
    "/SingleElectron/Run2016B-17Jul2018_ver2-v1/MINIAOD",
    "/SingleElectron/Run2016C-17Jul2018-v1/MINIAOD",
    "/SingleElectron/Run2016D-17Jul2018-v1/MINIAOD",
    "/SingleElectron/Run2016E-17Jul2018-v1/MINIAOD",
    "/SingleElectron/Run2016F-17Jul2018-v1/MINIAOD",
    "/SingleElectron/Run2016G-17Jul2018-v1/MINIAOD",
    "/SingleElectron/Run2016H-17Jul2018-v1/MINIAOD",

#    "/Tau/Run2016B-17Jul2018_ver1-v1/MINIAOD",
#    "/Tau/Run2016B-17Jul2018_ver2-v1/MINIAOD",
#    "/Tau/Run2016C-17Jul2018-v1/MINIAOD",
#    "/Tau/Run2016D-17Jul2018-v1/MINIAOD",
#    "/Tau/Run2016E-17Jul2018-v1/MINIAOD",
#    "/Tau/Run2016F-17Jul2018-v1/MINIAOD",
#    "/Tau/Run2016G-17Jul2018-v1/MINIAOD",
#    "/Tau/Run2016H-17Jul2018-v1/MINIAOD",
    
    ]


    for sample in samples:
      name = sample[1:].replace('/MINIAOD', '').replace('/', '_')
      print '\t name of sample is {}'.format(name)
      config.General.requestName = name
      config.Data.inputDataset = sample
      submit(config)

