// Updated by Abdollah Mohammadi (KSU)  [18 May 2015]
// abdollah.mohammadi@cern.ch

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "ggAnalysis/ggNtuplizer/interface/ggNtuplizer.h"

using namespace std;

// (local) variables associated with tree branches
Int_t          nBoostedTau_;

// decay mode discriminators



//Tau Id & Isolation
vector<bool>   boostedTaupfTausDiscriminationByDecayModeFinding_;
vector<bool>   boostedTaupfTausDiscriminationByDecayModeFindingNewDMs_;

vector<bool>   boostedTauByMVA6VLooseElectronRejection_;
vector<bool>   boostedTauByMVA6LooseElectronRejection_;
vector<bool>   boostedTauByMVA6MediumElectronRejection_;
vector<bool>   boostedTauByMVA6TightElectronRejection_;
vector<bool>   boostedTauByMVA6VTightElectronRejection_;

vector<bool>   boostedTauByLooseMuonRejection3_;
vector<bool>   boostedTauByTightMuonRejection3_;

vector<bool>   boostedTauByLooseCombinedIsolationDeltaBetaCorr3Hits_;
vector<bool>   boostedTauByMediumCombinedIsolationDeltaBetaCorr3Hits_;
vector<bool>   boostedTauByTightCombinedIsolationDeltaBetaCorr3Hits_;
vector<float>   boostedTauCombinedIsolationDeltaBetaCorrRaw3Hits_;

vector<float>        boostedTauByIsolationMVArun2v1DBnewDMwLTraw_;
vector<float>        boostedTauByIsolationMVArun2v1DBoldDMwLTraw_;
vector<float>        boostedTauByIsolationMVArun2v1PWnewDMwLTraw_;
vector<float>        boostedTauByIsolationMVArun2v1PWoldDMwLTraw_;
vector<bool>        boostedTauByVTightIsolationMVArun2v1DBnewDMwLT_;
vector<bool>        boostedTauByVTightIsolationMVArun2v1DBoldDMwLT_;
vector<bool>        boostedTauByVTightIsolationMVArun2v1PWnewDMwLT_;
vector<bool>        boostedTauByVTightIsolationMVArun2v1PWoldDMwLT_;
vector<bool>        boostedTauByTightIsolationMVArun2v1DBnewDMwLT_;
vector<bool>        boostedTauByTightIsolationMVArun2v1DBoldDMwLT_;
vector<bool>        boostedTauByTightIsolationMVArun2v1PWnewDMwLT_;
vector<bool>        boostedTauByTightIsolationMVArun2v1PWoldDMwLT_;
vector<bool>        boostedTauByMediumIsolationMVArun2v1DBnewDMwLT_;
vector<bool>        boostedTauByMediumIsolationMVArun2v1DBoldDMwLT_;
vector<bool>        boostedTauByMediumIsolationMVArun2v1PWnewDMwLT_;
vector<bool>        boostedTauByMediumIsolationMVArun2v1PWoldDMwLT_;
vector<bool>        boostedTauByLooseIsolationMVArun2v1DBnewDMwLT_;
vector<bool>        boostedTauByLooseIsolationMVArun2v1DBoldDMwLT_;
vector<bool>        boostedTauByLooseIsolationMVArun2v1PWnewDMwLT_;
vector<bool>        boostedTauByLooseIsolationMVArun2v1PWoldDMwLT_;
vector<bool>        boostedTauByVLooseIsolationMVArun2v1DBnewDMwLT_;
vector<bool>        boostedTauByVLooseIsolationMVArun2v1DBoldDMwLT_;
vector<bool>        boostedTauByVLooseIsolationMVArun2v1PWnewDMwLT_;
vector<bool>        boostedTauByVLooseIsolationMVArun2v1PWoldDMwLT_;

// rerun boostedTau ID
vector<float>        boostedTauByIsolationMVArun2v2DBoldDMwLTraw_;
vector<bool>        boostedTauByVTightIsolationMVArun2v2DBoldDMwLT_;
vector<bool>        boostedTauByTightIsolationMVArun2v2DBoldDMwLT_;
vector<bool>        boostedTauByMediumIsolationMVArun2v2DBoldDMwLT_;
vector<bool>        boostedTauByLooseIsolationMVArun2v2DBoldDMwLT_;
vector<bool>        boostedTauByVLooseIsolationMVArun2v2DBoldDMwLT_;

//Tau Kinematics
vector<float> boostedTauEta_;
vector<float> boostedTauPhi_;
vector<float> boostedTauPt_;
vector<float> boostedTauEt_;
vector<float> boostedTauCharge_;
vector<int>   boostedTauDecayMode_;
vector<float> boostedTauP_;
vector<float> boostedTauPx_;
vector<float> boostedTauPy_;
vector<float> boostedTauPz_;
vector<float> boostedTauVz_;
vector<float> boostedTauEnergy_;
vector<float> boostedTauMass_;
vector<float> boostedTauDxy_;
vector<float> boostedTauZImpact_;

//Tau Ingredients
vector<float> boostedTauChargedIsoPtSum_;
vector<float> boostedTauNeutralIsoPtSum_;
vector<float> boostedTauPuCorrPtSum_;
vector<int> boostedTauNumSignalPFChargedHadrCands_;
vector<int> boostedTauNumSignalPFNeutrHadrCands_;
vector<int> boostedTauNumSignalPFGammaCands_;
vector<int> boostedTauNumSignalPFCands_;
vector<int> boostedTauNumIsolationPFChargedHadrCands_;
vector<int> boostedTauNumIsolationPFNeutrHadrCands_;
vector<int> boostedTauNumIsolationPFGammaCands_;
vector<int> boostedTauNumIsolationPFCands_;
vector<bool>  boostedTauLeadChargedHadronExists_;
vector<float> boostedTauLeadChargedHadronEta_;
vector<float> boostedTauLeadChargedHadronPhi_;
vector<float> boostedTauLeadChargedHadronPt_;
vector<float> boostedTauneutralIsoPtSumWeight_;
vector<float> boostedTaufootprintCorrection_;
vector<float> boostedTauphotonPtSumOutsideSignalCone_;
vector<float> boostedTaudz_;
vector<float> boostedTaudxy_;






void ggNtuplizer::branchesBoostedTaus(TTree* tree)
{
    
    
    
    
    tree->Branch("nBoostedTau", &nBoostedTau_);
    
    //Tau Id & Isolation
    tree->Branch("boostedTaupfTausDiscriminationByDecayModeFinding", &boostedTaupfTausDiscriminationByDecayModeFinding_);
    tree->Branch("boostedTaupfTausDiscriminationByDecayModeFindingNewDMs", &boostedTaupfTausDiscriminationByDecayModeFindingNewDMs_);
    
    tree->Branch("boostedTauByMVA6VLooseElectronRejection", &boostedTauByMVA6VLooseElectronRejection_);
    tree->Branch("boostedTauByMVA6LooseElectronRejection", &boostedTauByMVA6LooseElectronRejection_);
    tree->Branch("boostedTauByMVA6MediumElectronRejection", &boostedTauByMVA6MediumElectronRejection_);
    tree->Branch("boostedTauByMVA6TightElectronRejection", &boostedTauByMVA6TightElectronRejection_);
    tree->Branch("boostedTauByMVA6VTightElectronRejection", &boostedTauByMVA6VTightElectronRejection_);
    
    tree->Branch("boostedTauByLooseMuonRejection3", &boostedTauByLooseMuonRejection3_);
    tree->Branch("boostedTauByTightMuonRejection3", &boostedTauByTightMuonRejection3_);
    
    tree->Branch("boostedTauByLooseCombinedIsolationDeltaBetaCorr3Hits", &boostedTauByLooseCombinedIsolationDeltaBetaCorr3Hits_);
    tree->Branch("boostedTauByMediumCombinedIsolationDeltaBetaCorr3Hits", &boostedTauByMediumCombinedIsolationDeltaBetaCorr3Hits_);
    tree->Branch("boostedTauByTightCombinedIsolationDeltaBetaCorr3Hits", &boostedTauByTightCombinedIsolationDeltaBetaCorr3Hits_);
    tree->Branch("boostedTauCombinedIsolationDeltaBetaCorrRaw3Hits", &boostedTauCombinedIsolationDeltaBetaCorrRaw3Hits_);
    
    tree->Branch("boostedTauByIsolationMVArun2v1DBnewDMwLTraw", &boostedTauByIsolationMVArun2v1DBnewDMwLTraw_);
    tree->Branch("boostedTauByIsolationMVArun2v1DBoldDMwLTraw", &boostedTauByIsolationMVArun2v1DBoldDMwLTraw_);
    tree->Branch("boostedTauByIsolationMVArun2v1PWnewDMwLTraw", &boostedTauByIsolationMVArun2v1PWnewDMwLTraw_);
    tree->Branch("boostedTauByIsolationMVArun2v1PWoldDMwLTraw", &boostedTauByIsolationMVArun2v1PWoldDMwLTraw_);
    tree->Branch("boostedTauByVTightIsolationMVArun2v1DBnewDMwLT", &boostedTauByVTightIsolationMVArun2v1DBnewDMwLT_);
    tree->Branch("boostedTauByVTightIsolationMVArun2v1DBoldDMwLT", &boostedTauByVTightIsolationMVArun2v1DBoldDMwLT_);
    tree->Branch("boostedTauByVTightIsolationMVArun2v1PWnewDMwLT", &boostedTauByVTightIsolationMVArun2v1PWnewDMwLT_);
    tree->Branch("boostedTauByVTightIsolationMVArun2v1PWoldDMwLT", &boostedTauByVTightIsolationMVArun2v1PWoldDMwLT_);
    tree->Branch("boostedTauByTightIsolationMVArun2v1DBnewDMwLT", &boostedTauByTightIsolationMVArun2v1DBnewDMwLT_);
    tree->Branch("boostedTauByTightIsolationMVArun2v1DBoldDMwLT", &boostedTauByTightIsolationMVArun2v1DBoldDMwLT_);
    tree->Branch("boostedTauByTightIsolationMVArun2v1PWnewDMwLT", &boostedTauByTightIsolationMVArun2v1PWnewDMwLT_);
    tree->Branch("boostedTauByTightIsolationMVArun2v1PWoldDMwLT", &boostedTauByTightIsolationMVArun2v1PWoldDMwLT_);
    tree->Branch("boostedTauByMediumIsolationMVArun2v1DBnewDMwLT", &boostedTauByMediumIsolationMVArun2v1DBnewDMwLT_);
    tree->Branch("boostedTauByMediumIsolationMVArun2v1DBoldDMwLT", &boostedTauByMediumIsolationMVArun2v1DBoldDMwLT_);
    tree->Branch("boostedTauByMediumIsolationMVArun2v1PWnewDMwLT", &boostedTauByMediumIsolationMVArun2v1PWnewDMwLT_);
    tree->Branch("boostedTauByMediumIsolationMVArun2v1PWoldDMwLT", &boostedTauByMediumIsolationMVArun2v1PWoldDMwLT_);
    tree->Branch("boostedTauByLooseIsolationMVArun2v1DBnewDMwLT", &boostedTauByLooseIsolationMVArun2v1DBnewDMwLT_);
    tree->Branch("boostedTauByLooseIsolationMVArun2v1DBoldDMwLT", &boostedTauByLooseIsolationMVArun2v1DBoldDMwLT_);
    tree->Branch("boostedTauByLooseIsolationMVArun2v1PWnewDMwLT", &boostedTauByLooseIsolationMVArun2v1PWnewDMwLT_);
    tree->Branch("boostedTauByLooseIsolationMVArun2v1PWoldDMwLT", &boostedTauByLooseIsolationMVArun2v1PWoldDMwLT_);
    tree->Branch("boostedTauByVLooseIsolationMVArun2v1DBnewDMwLT", &boostedTauByVLooseIsolationMVArun2v1DBnewDMwLT_);
    tree->Branch("boostedTauByVLooseIsolationMVArun2v1DBoldDMwLT", &boostedTauByVLooseIsolationMVArun2v1DBoldDMwLT_);
    tree->Branch("boostedTauByVLooseIsolationMVArun2v1PWnewDMwLT", &boostedTauByVLooseIsolationMVArun2v1PWnewDMwLT_);
    tree->Branch("boostedTauByVLooseIsolationMVArun2v1PWoldDMwLT", &boostedTauByVLooseIsolationMVArun2v1PWoldDMwLT_);

    // rerun boostedTau ID
    tree->Branch("boostedTauByIsolationMVArun2v2DBoldDMwLTraw", &boostedTauByIsolationMVArun2v2DBoldDMwLTraw_);
    tree->Branch("boostedTauByVTightIsolationMVArun2v2DBoldDMwLT", &boostedTauByVTightIsolationMVArun2v2DBoldDMwLT_);
    tree->Branch("boostedTauByTightIsolationMVArun2v2DBoldDMwLT", &boostedTauByTightIsolationMVArun2v2DBoldDMwLT_);
    tree->Branch("boostedTauByMediumIsolationMVArun2v2DBoldDMwLT", &boostedTauByMediumIsolationMVArun2v2DBoldDMwLT_);
    tree->Branch("boostedTauByLooseIsolationMVArun2v2DBoldDMwLT", &boostedTauByLooseIsolationMVArun2v2DBoldDMwLT_);
    tree->Branch("boostedTauByVLooseIsolationMVArun2v2DBoldDMwLT", &boostedTauByVLooseIsolationMVArun2v2DBoldDMwLT_);
    
    //Tau Kinematics
    tree->Branch("boostedTauEta"  ,&boostedTauEta_);
    tree->Branch("boostedTauPhi"  ,&boostedTauPhi_);
    tree->Branch("boostedTauPt"  ,&boostedTauPt_);
    tree->Branch("boostedTauEt"  ,&boostedTauEt_);
    tree->Branch("boostedTauCharge"  ,&boostedTauCharge_);
    tree->Branch("boostedTauP"  ,&boostedTauP_);
    tree->Branch("boostedTauPx"  ,&boostedTauPx_);
    tree->Branch("boostedTauPy"  ,&boostedTauPy_);
    tree->Branch("boostedTauPz"  ,&boostedTauPz_);
    tree->Branch("boostedTauVz"  ,&boostedTauVz_);
    tree->Branch("boostedTauEnergy"  ,&boostedTauEnergy_);
    tree->Branch("boostedTauMass"  ,&boostedTauMass_);
    tree->Branch("boostedTauDxy"  ,&boostedTauDxy_);
    tree->Branch("boostedTauZImpact"  ,&boostedTauZImpact_);
    
    // Tau Ingredients
    tree->Branch("boostedTauDecayMode"  ,&boostedTauDecayMode_);
    tree->Branch("boostedTauLeadChargedHadronExists"  ,&boostedTauLeadChargedHadronExists_);
    tree->Branch("boostedTauLeadChargedHadronEta"  ,&boostedTauLeadChargedHadronEta_);
    tree->Branch("boostedTauLeadChargedHadronPhi"  ,&boostedTauLeadChargedHadronPhi_);
    tree->Branch("boostedTauLeadChargedHadronPt"  ,&boostedTauLeadChargedHadronPt_);
    tree->Branch("boostedTauChargedIsoPtSum"  ,&boostedTauChargedIsoPtSum_);
    tree->Branch("boostedTauNeutralIsoPtSum"  ,&boostedTauNeutralIsoPtSum_);
    tree->Branch("boostedTauPuCorrPtSum"  ,&boostedTauPuCorrPtSum_);
    tree->Branch("boostedTauNumSignalPFChargedHadrCands"  ,&boostedTauNumSignalPFChargedHadrCands_);
    tree->Branch("boostedTauNumSignalPFNeutrHadrCands"  ,&boostedTauNumSignalPFNeutrHadrCands_);
    tree->Branch("boostedTauNumSignalPFGammaCands"  ,&boostedTauNumSignalPFGammaCands_);
    tree->Branch("boostedTauNumSignalPFCands"  ,&boostedTauNumSignalPFCands_);
    tree->Branch("boostedTauNumIsolationPFChargedHadrCands"  ,&boostedTauNumIsolationPFChargedHadrCands_);
    tree->Branch("boostedTauNumIsolationPFNeutrHadrCands"  ,&boostedTauNumIsolationPFNeutrHadrCands_);
    tree->Branch("boostedTauNumIsolationPFGammaCands"  ,&boostedTauNumIsolationPFGammaCands_);
    tree->Branch("boostedTauNumIsolationPFCands"  ,&boostedTauNumIsolationPFCands_);
    
    
    tree->Branch("boostedTaufootprintCorrection"  ,&boostedTaufootprintCorrection_);
    tree->Branch("boostedTauphotonPtSumOutsideSignalCone"  ,&boostedTauphotonPtSumOutsideSignalCone_);
    tree->Branch("boostedTaudz"  ,&boostedTaudz_);
    tree->Branch("boostedTaudxy"  ,&boostedTaudxy_);
    
    
}

void ggNtuplizer::fillBoostedTaus(const edm::Event& e)
{
    
    // Tau Id & Isolation
    
    boostedTaupfTausDiscriminationByDecayModeFinding_.clear();
    boostedTaupfTausDiscriminationByDecayModeFindingNewDMs_.clear();
    
    boostedTauByMVA6VLooseElectronRejection_.clear();
    boostedTauByMVA6LooseElectronRejection_.clear();
    boostedTauByMVA6MediumElectronRejection_.clear();
    boostedTauByMVA6TightElectronRejection_.clear();
    boostedTauByMVA6VTightElectronRejection_.clear();
    
    boostedTauByLooseMuonRejection3_.clear();
    boostedTauByTightMuonRejection3_.clear();

    boostedTauByLooseCombinedIsolationDeltaBetaCorr3Hits_.clear();
    boostedTauByMediumCombinedIsolationDeltaBetaCorr3Hits_.clear();
    boostedTauByTightCombinedIsolationDeltaBetaCorr3Hits_.clear();
    boostedTauCombinedIsolationDeltaBetaCorrRaw3Hits_.clear();
    
    boostedTauByIsolationMVArun2v1DBnewDMwLTraw_.clear();
    boostedTauByIsolationMVArun2v1DBoldDMwLTraw_.clear();
    boostedTauByIsolationMVArun2v1PWnewDMwLTraw_.clear();
    boostedTauByIsolationMVArun2v1PWoldDMwLTraw_.clear();
    boostedTauByVTightIsolationMVArun2v1DBnewDMwLT_.clear();
    boostedTauByVTightIsolationMVArun2v1DBoldDMwLT_.clear();
    boostedTauByVTightIsolationMVArun2v1PWnewDMwLT_.clear();
    boostedTauByVTightIsolationMVArun2v1PWoldDMwLT_.clear();
    boostedTauByTightIsolationMVArun2v1DBnewDMwLT_.clear();
    boostedTauByTightIsolationMVArun2v1DBoldDMwLT_.clear();
    boostedTauByTightIsolationMVArun2v1PWnewDMwLT_.clear();
    boostedTauByTightIsolationMVArun2v1PWoldDMwLT_.clear();
    boostedTauByMediumIsolationMVArun2v1DBnewDMwLT_.clear();
    boostedTauByMediumIsolationMVArun2v1DBoldDMwLT_.clear();
    boostedTauByMediumIsolationMVArun2v1PWnewDMwLT_.clear();
    boostedTauByMediumIsolationMVArun2v1PWoldDMwLT_.clear();
    boostedTauByLooseIsolationMVArun2v1DBnewDMwLT_.clear();
    boostedTauByLooseIsolationMVArun2v1DBoldDMwLT_.clear();
    boostedTauByLooseIsolationMVArun2v1PWnewDMwLT_.clear();
    boostedTauByLooseIsolationMVArun2v1PWoldDMwLT_.clear();
    boostedTauByVLooseIsolationMVArun2v1DBnewDMwLT_.clear();
    boostedTauByVLooseIsolationMVArun2v1DBoldDMwLT_.clear();
    boostedTauByVLooseIsolationMVArun2v1PWnewDMwLT_.clear();
    boostedTauByVLooseIsolationMVArun2v1PWoldDMwLT_.clear();

    boostedTauByIsolationMVArun2v2DBoldDMwLTraw_.clear();
    boostedTauByVTightIsolationMVArun2v2DBoldDMwLT_.clear();
    boostedTauByTightIsolationMVArun2v2DBoldDMwLT_.clear();
    boostedTauByMediumIsolationMVArun2v2DBoldDMwLT_.clear();
    boostedTauByLooseIsolationMVArun2v2DBoldDMwLT_.clear();
    boostedTauByVLooseIsolationMVArun2v2DBoldDMwLT_.clear();
    
    //Tau Kinematics
    boostedTauEta_.clear();
    boostedTauPhi_.clear();
    boostedTauPt_.clear();
    boostedTauEt_.clear();
    boostedTauCharge_.clear();
    boostedTauP_.clear();
    boostedTauPx_.clear();
    boostedTauPy_.clear();
    boostedTauPz_.clear();
    boostedTauVz_.clear();
    boostedTauEnergy_.clear();
    boostedTauMass_.clear();
    boostedTauDxy_.clear();
    boostedTauZImpact_.clear();
    
    // Tau Ingredients
    boostedTauDecayMode_.clear();
    boostedTauLeadChargedHadronExists_.clear();
    boostedTauLeadChargedHadronEta_.clear();
    boostedTauLeadChargedHadronPhi_.clear();
    boostedTauLeadChargedHadronPt_.clear();
    boostedTauChargedIsoPtSum_.clear();
    boostedTauNeutralIsoPtSum_.clear();
    boostedTauPuCorrPtSum_.clear();
    boostedTauNumSignalPFChargedHadrCands_.clear();
    boostedTauNumSignalPFNeutrHadrCands_.clear();
    boostedTauNumSignalPFGammaCands_.clear();
    boostedTauNumSignalPFCands_.clear();
    boostedTauNumIsolationPFChargedHadrCands_.clear();
    boostedTauNumIsolationPFNeutrHadrCands_.clear();
    boostedTauNumIsolationPFGammaCands_.clear();
    boostedTauNumIsolationPFCands_.clear();
    
    boostedTauneutralIsoPtSumWeight_.clear();
    boostedTaufootprintCorrection_.clear();
    boostedTauphotonPtSumOutsideSignalCone_.clear();
    boostedTaudz_.clear();
    boostedTaudxy_.clear();
    
    
    nBoostedTau_ = 0;
    
    edm::Handle<vector<pat::Tau> > boostedTauHandle, boostedTauHandle_v2;
    e.getByToken(boostedTauCollection_, boostedTauHandle);
    e.getByToken(boostedTauCollection_v2_, boostedTauHandle_v2);
    
    if (!boostedTauHandle.isValid()) {
        edm::LogWarning("ggNtuplizer") << "no pat::Tau in event";
        return;
    }

    // if (!boostedTauHandle_v2.isValid()) {
    //   edm::LogWarning("ggNtuplizer") << "rerun boostedTau ID missing";
    //   return;
    // }
    
    //startTaus Lvdp
    for(vector<pat::Tau>::const_iterator itau = boostedTauHandle->begin(); itau != boostedTauHandle->end(); ++itau) {
        
        // Tau Id & Isolation
        boostedTaupfTausDiscriminationByDecayModeFinding_.push_back(itau->tauID("decayModeFinding"));
        boostedTaupfTausDiscriminationByDecayModeFindingNewDMs_.push_back(itau->tauID("decayModeFindingNewDMs"));
        
        boostedTauByMVA6VLooseElectronRejection_.push_back(itau->tauID("againstElectronVLooseMVA6"));
        boostedTauByMVA6LooseElectronRejection_.push_back(itau->tauID("againstElectronLooseMVA6"));
        boostedTauByMVA6MediumElectronRejection_.push_back(itau->tauID("againstElectronMediumMVA6"));
        boostedTauByMVA6TightElectronRejection_.push_back(itau->tauID("againstElectronTightMVA6"));
        boostedTauByMVA6VTightElectronRejection_.push_back(itau->tauID("againstElectronVTightMVA6"));
        
        boostedTauByLooseMuonRejection3_.push_back(itau->tauID("againstMuonLoose3"));
        boostedTauByTightMuonRejection3_.push_back(itau->tauID("againstMuonTight3"));
        
        boostedTauByLooseCombinedIsolationDeltaBetaCorr3Hits_.push_back(itau->tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits"));
        boostedTauByMediumCombinedIsolationDeltaBetaCorr3Hits_.push_back(itau->tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits"));
        boostedTauByTightCombinedIsolationDeltaBetaCorr3Hits_.push_back(itau->tauID("byTightCombinedIsolationDeltaBetaCorr3Hits"));
        boostedTauCombinedIsolationDeltaBetaCorrRaw3Hits_.push_back(itau->tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits"));
        
        boostedTauByIsolationMVArun2v1DBnewDMwLTraw_.push_back(itau->tauID("byIsolationMVArun2v1DBnewDMwLTraw"));
        boostedTauByIsolationMVArun2v1DBoldDMwLTraw_.push_back(itau->tauID("byIsolationMVArun2v1DBoldDMwLTraw"));
        boostedTauByIsolationMVArun2v1PWnewDMwLTraw_.push_back(itau->tauID("byIsolationMVArun2v1PWnewDMwLTraw"));
        boostedTauByIsolationMVArun2v1PWoldDMwLTraw_.push_back(itau->tauID("byIsolationMVArun2v1PWoldDMwLTraw"));
        boostedTauByVLooseIsolationMVArun2v1DBnewDMwLT_.push_back(itau->tauID("byVLooseIsolationMVArun2v1DBnewDMwLT"));
        boostedTauByVLooseIsolationMVArun2v1DBoldDMwLT_.push_back(itau->tauID("byVLooseIsolationMVArun2v1DBoldDMwLT"));
        boostedTauByVLooseIsolationMVArun2v1PWnewDMwLT_.push_back(itau->tauID("byVLooseIsolationMVArun2v1PWnewDMwLT"));
        boostedTauByVLooseIsolationMVArun2v1PWoldDMwLT_.push_back(itau->tauID("byVLooseIsolationMVArun2v1PWoldDMwLT"));
        boostedTauByLooseIsolationMVArun2v1DBnewDMwLT_.push_back(itau->tauID("byLooseIsolationMVArun2v1DBnewDMwLT"));
        boostedTauByLooseIsolationMVArun2v1DBoldDMwLT_.push_back(itau->tauID("byLooseIsolationMVArun2v1DBoldDMwLT"));
        boostedTauByLooseIsolationMVArun2v1PWnewDMwLT_.push_back(itau->tauID("byLooseIsolationMVArun2v1PWnewDMwLT"));
        boostedTauByLooseIsolationMVArun2v1PWoldDMwLT_.push_back(itau->tauID("byLooseIsolationMVArun2v1PWoldDMwLT"));
        boostedTauByMediumIsolationMVArun2v1DBnewDMwLT_.push_back(itau->tauID("byMediumIsolationMVArun2v1DBnewDMwLT"));
        boostedTauByMediumIsolationMVArun2v1DBoldDMwLT_.push_back(itau->tauID("byMediumIsolationMVArun2v1DBoldDMwLT"));
        boostedTauByMediumIsolationMVArun2v1PWnewDMwLT_.push_back(itau->tauID("byMediumIsolationMVArun2v1PWnewDMwLT"));
        boostedTauByMediumIsolationMVArun2v1PWoldDMwLT_.push_back(itau->tauID("byMediumIsolationMVArun2v1PWoldDMwLT"));
        boostedTauByTightIsolationMVArun2v1DBnewDMwLT_.push_back(itau->tauID("byTightIsolationMVArun2v1DBnewDMwLT"));
        boostedTauByTightIsolationMVArun2v1DBoldDMwLT_.push_back(itau->tauID("byTightIsolationMVArun2v1DBoldDMwLT"));
        boostedTauByTightIsolationMVArun2v1PWnewDMwLT_.push_back(itau->tauID("byTightIsolationMVArun2v1PWnewDMwLT"));
        boostedTauByTightIsolationMVArun2v1PWoldDMwLT_.push_back(itau->tauID("byTightIsolationMVArun2v1PWoldDMwLT"));
        boostedTauByVTightIsolationMVArun2v1DBnewDMwLT_.push_back(itau->tauID("byVTightIsolationMVArun2v1DBnewDMwLT"));
        boostedTauByVTightIsolationMVArun2v1DBoldDMwLT_.push_back(itau->tauID("byVTightIsolationMVArun2v1DBoldDMwLT"));
        boostedTauByVTightIsolationMVArun2v1PWnewDMwLT_.push_back(itau->tauID("byVTightIsolationMVArun2v1PWnewDMwLT"));
        boostedTauByVTightIsolationMVArun2v1PWoldDMwLT_.push_back(itau->tauID("byVTightIsolationMVArun2v1PWoldDMwLT"));
    
        
        //Tau Kinematics
        boostedTauEta_.push_back(itau->eta());
        boostedTauPhi_.push_back(itau->phi());
        boostedTauPt_.push_back(itau->pt());
        boostedTauEt_.push_back(itau->et());
        boostedTauCharge_.push_back(itau->charge());
        boostedTauP_.push_back(itau->p() );
        boostedTauPx_.push_back(itau->px() );
        boostedTauPy_.push_back(itau->py() );
        boostedTauPz_.push_back(itau->pz() );
        boostedTauVz_.push_back(itau->vz() );
        boostedTauEnergy_.push_back(itau->energy() );
        boostedTauMass_.push_back(itau->mass());
        boostedTauDxy_.push_back(itau->dxy() );
        boostedTauZImpact_.push_back(itau->vertex().z() + 130./tan(itau->theta()));
        
        
        // Tau Ingredients
        boostedTauDecayMode_.push_back(itau->decayMode());
        boostedTauChargedIsoPtSum_.push_back(itau->tauID("chargedIsoPtSum") );
        boostedTauNeutralIsoPtSum_.push_back(itau->tauID("neutralIsoPtSum")  );
        boostedTauPuCorrPtSum_.push_back(itau->tauID("puCorrPtSum")  );
        boostedTauneutralIsoPtSumWeight_.push_back(itau->tauID("neutralIsoPtSumWeight"));
        boostedTaufootprintCorrection_.push_back(itau->tauID("footprintCorrection"));
        boostedTauphotonPtSumOutsideSignalCone_.push_back(itau->tauID("photonPtSumOutsideSignalCone"));
        
        boostedTauNumSignalPFChargedHadrCands_.push_back(itau->signalChargedHadrCands().size());
        boostedTauNumSignalPFNeutrHadrCands_.push_back(itau->signalNeutrHadrCands().size());
        boostedTauNumSignalPFGammaCands_.push_back(itau->signalGammaCands().size());
        boostedTauNumSignalPFCands_.push_back(itau->signalCands().size());
        
        boostedTauNumIsolationPFChargedHadrCands_.push_back(itau->isolationChargedHadrCands().size());
        boostedTauNumIsolationPFNeutrHadrCands_.push_back(itau->isolationNeutrHadrCands().size());
        boostedTauNumIsolationPFGammaCands_.push_back(itau->isolationGammaCands().size());
        boostedTauNumIsolationPFCands_.push_back(itau->isolationCands().size());
        
        edm::Handle<reco::VertexCollection> vertexs;
        e.getByToken(vtxLabel_, vertexs);
        
        if (vertexs->size()>0) {
            pat::PackedCandidate const* packedLeadTauCand = dynamic_cast<pat::PackedCandidate const*>(itau->leadChargedHadrCand().get());
            boostedTaudz_.push_back(packedLeadTauCand->dz());
            boostedTaudxy_.push_back(packedLeadTauCand->dxy());
            boostedTauLeadChargedHadronExists_.push_back(true);
            boostedTauLeadChargedHadronEta_.push_back(packedLeadTauCand->eta());
            boostedTauLeadChargedHadronPhi_.push_back(packedLeadTauCand->phi());
            boostedTauLeadChargedHadronPt_.push_back(packedLeadTauCand->pt());
        }
        
        
        
        
        ++nBoostedTau_;
        
    } // loop over tau candidates

    // for(vector<pat::Tau>::const_iterator itau = boostedTauHandle_v2->begin(); itau != boostedTauHandle_v2->end(); ++itau) {
    //     boostedTauByIsolationMVArun2v2DBoldDMwLTraw_.push_back(itau->tauID("byIsolationMVArun2017v2DBoldDMwLTraw2017"));
    //     boostedTauByVTightIsolationMVArun2v2DBoldDMwLT_.push_back(itau->tauID("byVTightIsolationMVArun2017v2DBoldDMwLT2017"));
    //     boostedTauByTightIsolationMVArun2v2DBoldDMwLT_.push_back(itau->tauID("byTightIsolationMVArun2017v2DBoldDMwLT2017"));
    //     boostedTauByMediumIsolationMVArun2v2DBoldDMwLT_.push_back(itau->tauID("byMediumIsolationMVArun2017v2DBoldDMwLT2017"));
    //     boostedTauByLooseIsolationMVArun2v2DBoldDMwLT_.push_back(itau->tauID("byLooseIsolationMVArun2017v2DBoldDMwLT2017"));
    //     boostedTauByVLooseIsolationMVArun2v2DBoldDMwLT_.push_back(itau->tauID("byVLooseIsolationMVArun2017v2DBoldDMwLT2017"));
    // }
    
}
