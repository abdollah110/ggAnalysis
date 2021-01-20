from CRABClient.UserUtilities import config
#from WMCore.Configuration import Configuration
#config = Configuration()
config=config()
config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'Data'
config.section_('JobType')
config.JobType.psetName = 'run_data2017_94X.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['ggtree_data.root']
config.JobType.inputFiles = ['Fall17_17Nov2017BCDEF_V6_DATA.db','Fall17_17Nov2017_V6_MC.db']
config.JobType.maxMemoryMB = 4000
config.JobType.allowUndistributedCMSSW = True
config.JobType.sendExternalFolder = True
config.JobType.allowUndistributedCMSSW = True
config.section_('Data')
config.Data.unitsPerJob = 30
config.Data.splitting = 'LumiBased'
config.Data.lumiMask = 'Cert_294927-306462_13TeV_EOY2017ReReco_Collisions17_JSON.txt' 
config.Data.runRange = '294927-306462'
config.Data.outLFNDirBase = '/store/user/abdollah/BoostedH/2017/Data/'
#config.Data.outLFNDirBase = '/store/group/lpcggntuples/ggNtuples/13TeV/BoostH/2017/Data'
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
    config.General.workArea = 'Data_2017_v5'

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
    
#        "/Tau/Run2017B-31Mar2018-v1/MINIAOD",
#        "/Tau/Run2017C-31Mar2018-v1/MINIAOD",
#        "/Tau/Run2017D-31Mar2018-v1/MINIAOD",
#        "/Tau/Run2017E-31Mar2018-v1/MINIAOD",
#        "/Tau/Run2017F-31Mar2018-v1/MINIAOD",

#        "/JetHT/Run2017B-31Mar2018-v1/MINIAOD",
#        "/JetHT/Run2017C-31Mar2018-v1/MINIAOD",
#        "/JetHT/Run2017D-31Mar2018-v1/MINIAOD",
#        "/JetHT/Run2017E-31Mar2018-v1/MINIAOD",
#        "/JetHT/Run2017F-31Mar2018-v1/MINIAOD",


#        "/SingleMuon/Run2017B-31Mar2018-v1/MINIAOD",
#        "/SingleMuon/Run2017C-31Mar2018-v1/MINIAOD",
#        "/SingleMuon/Run2017D-31Mar2018-v1/MINIAOD",
#        "/SingleMuon/Run2017E-31Mar2018-v1/MINIAOD",
#        "/SingleMuon/Run2017F-31Mar2018-v1/MINIAOD",
#
        "/SingleElectron/Run2017B-31Mar2018-v1/MINIAOD",
        "/SingleElectron/Run2017C-31Mar2018-v1/MINIAOD",
        "/SingleElectron/Run2017D-31Mar2018-v1/MINIAOD",
        "/SingleElectron/Run2017E-31Mar2018-v1/MINIAOD",
        "/SingleElectron/Run2017F-31Mar2018-v1/MINIAOD"

#        "/HTMHT/Run2017B-31Mar2018-v1/MINIAOD",
#        "/HTMHT/Run2017C-31Mar2018-v1/MINIAOD",
#        "/HTMHT/Run2017D-31Mar2018-v1/MINIAOD",
#        "/HTMHT/Run2017E-31Mar2018-v1/MINIAOD",
#        "/HTMHT/Run2017F-31Mar2018-v1/MINIAOD",



    ]


    for sample in samples:
      name = sample[1:].replace('/MINIAOD', '').replace('/', '_')
      print '\t name of sample is {}'.format(name)
      config.General.requestName = name
      config.Data.inputDataset = sample
      submit(config)

