#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "ggAnalysis/ggNtuplizer/interface/ggNtuplizer.h"
#include "ggAnalysis/ggNtuplizer/interface/GenParticleParentage.h"


using namespace std;

Int_t metFilters_;
float genMET_;
float genMETPhi_;
float pfMET_;
float pfMETPhi_;
float pfMET_T1JERUp_;
float pfMET_T1JERDo_;
float pfMET_T1JESUp_;
float pfMET_T1JESDo_;
float pfMET_T1MESUp_;
float pfMET_T1MESDo_;
float pfMET_T1EESUp_;
float pfMET_T1EESDo_;
float pfMET_T1PESUp_;
float pfMET_T1PESDo_;
float pfMET_T1TESUp_;
float pfMET_T1TESDo_;
float pfMET_T1UESUp_;
float pfMET_T1UESDo_;
float pfMET_T1TxyPhi_;
float pfMET_T1TxyPt_;
float pfMETPhi_T1JESUp_;
float pfMETPhi_T1JESDo_;
float pfMETPhi_T1UESUp_;
float pfMETPhi_T1UESDo_;
float pfmetcorr_ex_UESUp, pfmetcorr_ey_UESUp, pfmetcorr_ex_UESDown, pfmetcorr_ey_UESDown, pfmetcorr_ex_JESUp, pfmetcorr_ey_JESUp, pfmetcorr_ex_JESDown, pfmetcorr_ey_JESDown;
TLorentzVector  MET, MET_UESUp, MET_UESDown, MET_JESUp, MET_JESDown;
float genpX, genpY, vispX, vispY;
float met_UESUp, met_UESDown, met_JESUp, met_JESDown, metphi_UESUp, metphi_UESDown, metphi_JESUp, metphi_JESDown;
float met_px, met_py, pfmetcorr_ex, pfmetcorr_ey, met, metphi;





void ggNtuplizer::branchesMET(TTree* tree) {

  if (doGenParticles_) {
    tree->Branch("genMET",      &genMET_);
    tree->Branch("genMETPhi",   &genMETPhi_);
  }
  tree->Branch("metFilters",       &metFilters_);
  tree->Branch("pfMET",            &pfMET_);
  tree->Branch("pfMETPhi",         &pfMETPhi_);
//  tree->Branch("pfMET_T1JERUp",    &pfMET_T1JERUp_);
//  tree->Branch("pfMET_T1JERDo",    &pfMET_T1JERDo_);
  /*
  tree->Branch("pfMET_T1MESUp",    &pfMET_T1MESUp_);
  tree->Branch("pfMET_T1MESDo",    &pfMET_T1MESDo_);
  tree->Branch("pfMET_T1EESUp",    &pfMET_T1EESUp_);
  tree->Branch("pfMET_T1EESDo",    &pfMET_T1EESDo_);
  tree->Branch("pfMET_T1PESUp",    &pfMET_T1PESUp_);
  tree->Branch("pfMET_T1PESDo",    &pfMET_T1PESDo_);
  tree->Branch("pfMET_T1TESUp",    &pfMET_T1TESUp_);
  tree->Branch("pfMET_T1TESDo",    &pfMET_T1TESDo_);
  */
  tree->Branch("pfMET_T1JESUp",    &pfMET_T1JESUp_);
  tree->Branch("pfMET_T1JESDo",    &pfMET_T1JESDo_);
  tree->Branch("pfMET_T1UESUp",    &pfMET_T1UESUp_);
  tree->Branch("pfMET_T1UESDo",    &pfMET_T1UESDo_);
  tree->Branch("pfMETPhi_T1JESUp", &pfMETPhi_T1JESUp_);
  tree->Branch("pfMETPhi_T1JESDo", &pfMETPhi_T1JESDo_);
  tree->Branch("pfMETPhi_T1UESUp", &pfMETPhi_T1UESUp_);
  tree->Branch("pfMETPhi_T1UESDo", &pfMETPhi_T1UESDo_);
  
  // Systematics
  tree->Branch("met_JESUp", &met_JESUp, "met_JESUp/F");
  tree->Branch("met_JESDown", &met_JESDown, "met_JESDown/F");
  tree->Branch("met_UESUp", &met_UESUp, "met_UESUp/F");
  tree->Branch("met_UESDown", &met_UESDown, "met_UESDown/F");
  tree->Branch("metphi_JESUp", &metphi_JESUp, "metphi_JESUp/F");
  tree->Branch("metphi_JESDown", &metphi_JESDown, "metphi_JESDown/F");
  tree->Branch("metphi_UESUp", &metphi_UESUp, "metphi_UESUp/F");
  tree->Branch("metphi_UESDown", &metphi_UESDown, "metphi_UESDown/F");
  
  tree->Branch("pfmetcorr_ex_UESUp"                       , &pfmetcorr_ex_UESUp                       , "pfmetcorr_ex_UESUp/F");
  tree->Branch("pfmetcorr_ey_UESUp"                       , &pfmetcorr_ey_UESUp                       , "pfmetcorr_ey_UESUp/F");
  tree->Branch("pfmetcorr_ex_UESDown"                     , &pfmetcorr_ex_UESDown                     , "pfmetcorr_ex_UESDown/F");
  tree->Branch("pfmetcorr_ey_UESDown"                     , &pfmetcorr_ey_UESDown                     , "pfmetcorr_ey_UESDown/F");
  tree->Branch("pfmetcorr_ex_JESUp"                       , &pfmetcorr_ex_JESUp                       , "pfmetcorr_ex_JESUp/F");
  tree->Branch("pfmetcorr_ey_JESUp"                       , &pfmetcorr_ey_JESUp                       , "pfmetcorr_ey_JESUp/F");
  tree->Branch("pfmetcorr_ex_JESDown"                     , &pfmetcorr_ex_JESDown                     , "pfmetcorr_ex_JESDown/F");
  tree->Branch("pfmetcorr_ey_JESDown"                     , &pfmetcorr_ey_JESDown                     , "pfmetcorr_ey_JESDown/F");






}

void ggNtuplizer::fillMET(const edm::Event& e, const edm::EventSetup& es, const RecoilCorrector recoilPFMetCorrector) {
//void ggNtuplizer::fillMET(const edm::Event& e, const edm::EventSetup& es) {

//    // use this RooT file when correcting Type I PF MET
//    // RecoilCorrector recoilPFMetCorrector("HTT-utilities/RecoilCorrections/data/TypeIPFMET_2016BCD.root"); // Type I PF MET 2016
//     RecoilCorrector recoilPFMetCorrector("HTT-utilities/RecoilCorrections/data/Type1_PFMET_2017.root"); // Type I PF MET 2017
//    //RecoilCorrector recoilPFMetCorrector("HTT-utilities/RecoilCorrections/data/TypeI-PFMet_Run2018.root"); // Type I PF MET 2018


    //=========================================================================================================
    //  for recoil correction
    //=========================================================================================================
    //check boson pt, ...
    edm::Handle<vector<reco::GenParticle> > genParticlesHandle;
    e.getByToken(genParticlesCollection_, genParticlesHandle);
    
    if (!genParticlesHandle.isValid()) {
        edm::LogWarning("ggNtuplizer") << "no reco::GenParticles in event";
        return;
    }
    
//     genpX = -10;
//     genpY= -10;
//     vispX= -10;
//     vispY= -10;
    Int_t recoil = 0;
    
    reco::Candidate::LorentzVector visVec;
    reco::Candidate::LorentzVector withInvisVec;
    
    for (vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
                
        bool fromHardProcessFinalState = ip->fromHardProcessFinalState();
        bool isDirectHardProcessTauDecayProduct = ip->statusFlags().isDirectHardProcessTauDecayProduct();
        bool isMuon = false;
        bool isElectron = false;
        bool isNeutrino = false;
        int pdgId = fabs( ip->pdgId() );
        if (pdgId == 11) isElectron = true;
        if (pdgId == 13) isMuon = true;
        if (pdgId == 12) isNeutrino = true;
        if (pdgId == 14) isNeutrino = true;
        if (pdgId == 16) isNeutrino = true;
        if ((fromHardProcessFinalState && (isMuon || isElectron || isNeutrino)) || isDirectHardProcessTauDecayProduct) {
            withInvisVec += ip->p4();}
        if ((fromHardProcessFinalState && (isMuon || isElectron)) || (isDirectHardProcessTauDecayProduct && !isNeutrino)) {
            visVec += ip->p4();}
        
        if (    ip->pdgId()  == 23 && ip->isHardProcess()) recoil=2;
        if (    abs(ip->pdgId()) == 24 && ip->isHardProcess()) recoil=1;
        if (    ip->pdgId()  == 25 && ip->isHardProcess()) recoil=2;
        
    }
    
    genpX= visVec.px();
    genpY= visVec.py();
    vispX= withInvisVec.px();
    vispY= withInvisVec.py();
        
    edm::Handle<edm::View<pat::Jet> > jetHandle;
    e.getByToken(jetsAK4Label_, jetHandle);
    
    int njet=0;
    
    for (edm::View<pat::Jet>::const_iterator iJet = jetHandle->begin(); iJet != jetHandle->end(); ++iJet) {
        
        if (iJet->pt() < 30) continue;
        if (fabs(iJet->eta()) > 4.7) continue;
        if (iJet->pt() < 50 && fabs(iJet->eta()) > 2.65 &&  fabs(iJet->eta()) < 3.139   ) continue;
        
        
        //jet PF Loose ID
        double NHF      = iJet->neutralHadronEnergyFraction();
        double NEMF     = iJet->neutralEmEnergyFraction();
        double NumConst = iJet->chargedMultiplicity()+iJet->neutralMultiplicity();
        double CHF      = iJet->chargedHadronEnergyFraction();
        double CHM      = iJet->chargedMultiplicity();
        double CEMF     = iJet->chargedEmEnergyFraction();
        double NNP      = iJet->neutralMultiplicity();
        
        
        bool looseJetID = false;
        if (fabs(iJet->eta()) <= 2.7) {
            looseJetID = (NHF<0.99 && NEMF<0.99 && NumConst>1) && ((fabs(iJet->eta())<=2.4 && CHF>0 && CHM>0 && CEMF<0.99) || fabs(iJet->eta())>2.4);
        } else if (fabs(iJet->eta()) <= 3.0) {
            looseJetID = (NEMF>0.01 && NHF<0.98 && NNP>2);
        } else {
            looseJetID = (NEMF<0.90 && NNP>10);
        }
        if (! looseJetID) continue;
        
        njet++;
        //           dR(lepton,jet) > 0.5.  I have skiped this requirement, instead i subtract my njet with 2 to account the two leptons that have been tagged as lepton
    }
    
//    int jetVeto30 = std::max(njet-2,0);
    
    //=========================================================================================================

  metFilters_ = 0;


  if (addFilterInfoMINIAOD_) {
    string filterNamesToCheck[9] = {
      "Flag_HBHENoiseFilter",
      "Flag_HBHENoiseIsoFilter", 
      "Flag_globalSuperTightHalo2016Filter",
      "Flag_goodVertices",
      "Flag_eeBadScFilter",
      "Flag_EcalDeadCellTriggerPrimitiveFilter",
      "Flag_BadPFMuonFilter",
      "Flag_ecalBadCalibFilter",
      "Flag_BadChargedCandidateFilter"
    };

    edm::Handle<edm::TriggerResults> patFilterResultsHandle;
    e.getByToken(patTrgResultsLabel_, patFilterResultsHandle);
    edm::TriggerResults const& patFilterResults = *patFilterResultsHandle;
    
    auto&& filterNames = e.triggerNames(patFilterResults);

    // === the following lines allow us to find the filters stored in the event ! ===
    /*
    edm::TriggerNames const& triggerNames = e.triggerNames(patFilterResults);
    for ( edm::TriggerNames::Strings::const_iterator triggerName = triggerNames.triggerNames().begin();
	  triggerName != triggerNames.triggerNames().end(); ++triggerName ) {
      int triggerId = triggerNames.triggerIndex(*triggerName);
      if ( triggerId >= 0 && triggerId < (int)triggerNames.size() ) {
	std::string triggerDecision = ( patFilterResultsHandle->accept(triggerId) ) ? "passed" : "failed";
	  
	std::cout << " triggerName = " << (*triggerName) << " " << triggerDecision << std::endl;
      }
    }
    */

    for (unsigned iF = 0; iF < 9; ++iF) {
      unsigned index = filterNames.triggerIndex(filterNamesToCheck[iF]);
      if ( index == filterNames.size() ) 
	      LogDebug("METFilters") << filterNamesToCheck[iF] << " is missing, exiting";
            else {
	      if ( !patFilterResults.accept(index) ) {
	        metFilters_ += pow(2, iF+1);
	      }
      }
    }
  } 
  
  edm::Handle<edm::View<pat::MET> > pfMETHandle;
  e.getByToken(pfMETlabel_, pfMETHandle);

  genMET_    = -99;
  genMETPhi_ = -99;
  pfMET_     = -99;
  pfMETPhi_  = -99;

  if (pfMETHandle.isValid()) {
    const pat::MET *pfMET = 0;
    pfMET     = &(pfMETHandle->front());
    pfMET_    = pfMET->et();
    pfMETPhi_ = pfMET->phi();
    
    // Type1MET uncertainties =======================================
//    pfMET_T1JERUp_ = pfMET->shiftedPt(pat::MET::JetResUp);
//    pfMET_T1JERDo_ = pfMET->shiftedPt(pat::MET::JetResDown);
    /*
      pfMET_T1MESUp_ = pfMET->shiftedPt(pat::MET::MuonEnUp);
      pfMET_T1MESDo_ = pfMET->shiftedPt(pat::MET::MuonEnDown);
      pfMET_T1EESUp_ = pfMET->shiftedPt(pat::MET::ElectronEnUp);
      pfMET_T1EESDo_ = pfMET->shiftedPt(pat::MET::ElectronEnDown);
      pfMET_T1PESUp_ = pfMET->shiftedPt(pat::MET::PhotonEnUp);
      pfMET_T1PESDo_ = pfMET->shiftedPt(pat::MET::PhotonEnDown);
      pfMET_T1TESUp_ = pfMET->shiftedPt(pat::MET::TauEnUp);
      pfMET_T1TESDo_ = pfMET->shiftedPt(pat::MET::TauEnDown);
    */

    pfMET_T1JESUp_ = pfMET->shiftedPt(pat::MET::JetEnUp);
    pfMET_T1JESDo_ = pfMET->shiftedPt(pat::MET::JetEnDown);
    pfMETPhi_T1JESUp_ = pfMET->shiftedPhi(pat::MET::JetEnUp);
    pfMETPhi_T1JESDo_ = pfMET->shiftedPhi(pat::MET::JetEnDown);
        
    pfMET_T1UESUp_ = pfMET->shiftedPt(pat::MET::UnclusteredEnUp);
    pfMET_T1UESDo_ = pfMET->shiftedPt(pat::MET::UnclusteredEnDown);
    pfMETPhi_T1UESUp_ = pfMET->shiftedPhi(pat::MET::UnclusteredEnUp);
    pfMETPhi_T1UESDo_ = pfMET->shiftedPhi(pat::MET::UnclusteredEnDown);
    
    if (!e.isRealData()) {
      genMET_    = pfMET->genMET()->et();
      genMETPhi_ = pfMET->genMET()->phi();
    }

  } 


    MET.SetPtEtaPhiM(pfMET_, 0, pfMETPhi_, 0);
    
    MET_UESUp.SetPtEtaPhiM(pfMET_T1UESUp_, 0, pfMETPhi_T1UESUp_, 0);
    MET_UESDown.SetPtEtaPhiM(pfMET_T1UESDo_, 0, pfMETPhi_T1UESDo_, 0);
    
    MET_JESUp.SetPtEtaPhiM(pfMET_T1JESUp_, 0, pfMETPhi_T1JESUp_, 0);
    MET_JESDown.SetPtEtaPhiM(pfMET_T1JESDo_, 0, pfMETPhi_T1JESDo_, 0);
    
    pfmetcorr_ex = MET.Px();
    pfmetcorr_ey = MET.Py();
    pfmetcorr_ex_UESUp = MET_UESUp.Px();
    pfmetcorr_ey_UESUp = MET_UESUp.Py();
    pfmetcorr_ex_UESDown = MET_UESDown.Px();
    pfmetcorr_ey_UESDown = MET_UESDown.Py();
    pfmetcorr_ex_JESUp = MET_JESUp.Px();
    pfmetcorr_ey_JESUp = MET_JESUp.Py();
    pfmetcorr_ex_JESDown = MET_JESDown.Px();
    pfmetcorr_ey_JESDown = MET_JESDown.Py();
    
    cout <<"\n\t\trecoil = "<<recoil<< "\n";

//    if (recoil == 1) {
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET.Px(),            // uncorrected type I pf met px (float)
//                                                     MET.Py(),            // uncorrected type I pf met py (float)
//                                                     genpX,               // generator Z/W/Higgs px (float)
//                                                     genpY,               // generator Z/W/Higgs py (float)
//                                                     vispX,               // generator visible Z/W/Higgs px (float)
//                                                     vispY,               // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30 + 1,       // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex,        // corrected type I pf met px (float)
//                                                     pfmetcorr_ey);       // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_JESUp.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_JESUp.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                // generator Z/W/Higgs px (float)
//                                                     genpY,                // generator Z/W/Higgs py (float)
//                                                     vispX,                // generator visible Z/W/Higgs px (float)
//                                                     vispY,                // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30 + 1,        // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_JESUp,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_JESUp);  // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_UESUp.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_UESUp.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                // generator Z/W/Higgs px (float)
//                                                     genpY,                // generator Z/W/Higgs py (float)
//                                                     vispX,                // generator visible Z/W/Higgs px (float)
//                                                     vispY,                // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30 + 1,        // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_UESUp,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_UESUp);  // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_JESDown.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_JESDown.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                  // generator Z/W/Higgs px (float)
//                                                     genpY,                  // generator Z/W/Higgs py (float)
//                                                     vispX,                  // generator visible Z/W/Higgs px (float)
//                                                     vispY,                  // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30 + 1,          // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_JESDown,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_JESDown);  // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_UESDown.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_UESDown.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                  // generator Z/W/Higgs px (float)
//                                                     genpY,                  // generator Z/W/Higgs py (float)
//                                                     vispX,                  // generator visible Z/W/Higgs px (float)
//                                                     vispY,                  // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30 + 1,          // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_UESDown,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_UESDown);  // corrected type I pf met py (float)
//
//    } else if (recoil == 2) {
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET.Px(),            // uncorrected type I pf met px (float)
//                                                     MET.Py(),            // uncorrected type I pf met py (float)
//                                                     genpX,               // generator Z/W/Higgs px (float)
//                                                     genpY,               // generator Z/W/Higgs py (float)
//                                                     vispX,               // generator visible Z/W/Higgs px (float)
//                                                     vispY,               // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30,       // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex,        // corrected type I pf met px (float)
//                                                     pfmetcorr_ey);       // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_JESUp.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_JESUp.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                // generator Z/W/Higgs px (float)
//                                                     genpY,                // generator Z/W/Higgs py (float)
//                                                     vispX,                // generator visible Z/W/Higgs px (float)
//                                                     vispY,                // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30,            // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_JESUp,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_JESUp);  // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_UESUp.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_UESUp.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                // generator Z/W/Higgs px (float)
//                                                     genpY,                // generator Z/W/Higgs py (float)
//                                                     vispX,                // generator visible Z/W/Higgs px (float)
//                                                     vispY,                // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30,            // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_UESUp,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_UESUp);  // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_JESDown.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_JESDown.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                  // generator Z/W/Higgs px (float)
//                                                     genpY,                  // generator Z/W/Higgs py (float)
//                                                     vispX,                  // generator visible Z/W/Higgs px (float)
//                                                     vispY,                  // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30,              // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_JESDown,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_JESDown);  // corrected type I pf met py (float)
//
//        recoilPFMetCorrector.CorrectByMeanResolution(
//                                                     MET_UESDown.Px(),       // uncorrected type I pf met px (float)
//                                                     MET_UESDown.Py(),       // uncorrected type I pf met py (float)
//                                                     genpX,                  // generator Z/W/Higgs px (float)
//                                                     genpY,                  // generator Z/W/Higgs py (float)
//                                                     vispX,                  // generator visible Z/W/Higgs px (float)
//                                                     vispY,                  // generator visible Z/W/Higgs py (float)
//                                                     jetVeto30,              // number of jets (hadronic jet multiplicity) (int)
//                                                     pfmetcorr_ex_UESDown,   // corrected type I pf met px (float)
//                                                     pfmetcorr_ey_UESDown);  // corrected type I pf met py (float)
//    }
//
//    MET.SetPxPyPzE(pfmetcorr_ex, pfmetcorr_ey, 0, sqrt(pfmetcorr_ex * pfmetcorr_ex + pfmetcorr_ey * pfmetcorr_ey));
//    MET_UESUp.SetPxPyPzE(pfmetcorr_ex_UESUp, pfmetcorr_ey_UESUp, 0, sqrt(pfmetcorr_ex_UESUp * pfmetcorr_ex_UESUp + pfmetcorr_ey_UESUp * pfmetcorr_ey_UESUp));
//    MET_UESDown.SetPxPyPzE(pfmetcorr_ex_UESDown, pfmetcorr_ey_UESDown, 0, sqrt(pfmetcorr_ex_UESDown * pfmetcorr_ex_UESDown + pfmetcorr_ey_UESDown * pfmetcorr_ey_UESDown));
//    MET_JESUp.SetPxPyPzE(pfmetcorr_ex_JESUp, pfmetcorr_ey_JESUp, 0, sqrt(pfmetcorr_ex_JESUp * pfmetcorr_ex_JESUp + pfmetcorr_ey_JESUp * pfmetcorr_ey_JESUp));
//    MET_JESDown.SetPxPyPzE(pfmetcorr_ex_JESDown, pfmetcorr_ey_JESDown, 0, sqrt(pfmetcorr_ex_JESDown * pfmetcorr_ex_JESDown + pfmetcorr_ey_JESDown * pfmetcorr_ey_JESDown));
    
    met = MET.Pt();
    metphi = MET.Phi();
    met_px = MET.Px();
    met_py = MET.Py();
    
    met_JESUp = MET_JESUp.Pt();
    met_JESDown = MET_JESDown.Pt();
    met_UESUp = MET_UESUp.Pt();
    met_UESDown = MET_UESDown.Pt();
    metphi_JESUp = MET_JESUp.Phi();
    metphi_JESDown = MET_JESDown.Phi();
    metphi_UESUp = MET_UESUp.Phi();
    metphi_UESDown = MET_UESDown.Phi();
    
    
    
    
    
    


}
