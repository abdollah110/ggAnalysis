from CRABClient.UserUtilities import config
#from WMCore.Configuration import Configuration
#config = Configuration()
config=config()
config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'Data'
config.section_('JobType')
config.JobType.psetName = 'run_data2018_102X.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['ggtree_data.root']
#config.JobType.inputFiles = ['Fall17_17Nov2017BCDEF_V6_DATA.db','Fall17_17Nov2017_V6_MC.db']
config.JobType.maxMemoryMB = 4000
config.JobType.allowUndistributedCMSSW = True
config.JobType.sendExternalFolder = True
config.JobType.allowUndistributedCMSSW = True
config.section_('Data')
config.Data.unitsPerJob = 30
config.Data.splitting = 'LumiBased'
#config.Data.lumiMask = 'Cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt'
config.Data.lumiMask = 'Cert_314472-325175_13TeV_PromptReco_Collisions18_JSON.txt'
config.Data.runRange = '314472-325175'
config.Data.outLFNDirBase = '/store/user/abdollah/BoostedH/2018/Data/'
#config.Data.outLFNDirBase = '/store/group/lpcggntuples/ggNtuples/13TeV/BoostH/2018/Data'
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
    config.General.workArea = 'Data_2018_v2'

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

#    "/Tau/Run2018A-17Sep2018-v1/MINIAOD",
#    "/Tau/Run2018B-17Sep2018-v1/MINIAOD",
#    "/Tau/Run2018C-17Sep2018-v1/MINIAOD",
#    "/Tau/Run2018D-PromptReco-v2/MINIAOD"

#    "/JetHT/Run2018A-17Sep2018-v1/MINIAOD",
#    "/JetHT/Run2018B-17Sep2018-v1/MINIAOD",
#    "/JetHT/Run2018C-17Sep2018-v1/MINIAOD",
#    "/JetHT/Run2018D-PromptReco-v2/MINIAOD"


        "/SingleMuon/Run2018A-17Sep2018-v2/MINIAOD",
        "/SingleMuon/Run2018B-17Sep2018-v1/MINIAOD",
        "/SingleMuon/Run2018C-17Sep2018-v1/MINIAOD",
        "/SingleMuon/Run2018D-PromptReco-v2/MINIAOD",

#       "/EGamma/Run2018A-17Sep2018-v2/MINIAOD",
#       "/EGamma/Run2018B-17Sep2018-v1/MINIAOD",
#       "/EGamma/Run2018C-17Sep2018-v1/MINIAOD",
#       "/EGamma/Run2018D-PromptReco-v2/MINIAOD",

    ]


    for sample in samples:
      name = sample[1:].replace('/MINIAOD', '').replace('/', '_')
      print '\t name of sample is {}'.format(name)
      config.General.requestName = name
      config.Data.inputDataset = sample
      submit(config)

