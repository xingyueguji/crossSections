//#include "TCutG.h"
#include "src/readReport.cpp"
#include "src/getCharge.cpp"
#include "src/getHMSCharge.cpp"
//#include "src/fpCuts.cpp"

double fixRange(TH2F *h, double max=0.0){
  if(max==0)max= h->GetMaximum();
  double min=1E-9;
  h->GetZaxis()->SetRangeUser(min, max);
  return max;

}
void format(TString s1, TString s2,TCanvas *c){

  double x1=.1;
  double x2=.3;
  double y1=.92;
  double y2=.98;

  TPaveText *tx1=new TPaveText(x1,y1,x2,y2,"NDC");
  tx1->SetBorderSize(1);
  c->cd(1);
  gPad->SetLogz();
  tx1->AddText("Monte Carlo");
  tx1->Draw();
  c->cd(2);
  gPad->SetLogz();
  TPaveText *tx2=new TPaveText(x1,y1,x2,y2,"NDC");
  tx2->SetBorderSize(1);
  tx2->AddText("Data - Dummy");
  tx2->Draw();
  c->cd(3);
  gPad->SetLogz();
  TPaveText *tx3=new TPaveText(x1,y1,x2,y2,"NDC");
  tx3->SetBorderSize(1);
  tx3->AddText("Data + Dummy");
  tx3->Draw();
  c->cd(4);
  gPad->SetLogz();
  TPaveText *tx4=new TPaveText(x1,y1,x2,y2,"NDC");
  tx4->SetBorderSize(1);
  tx4->AddText("Dummy");
  tx4->Draw();

  TPaveText *tx5=new TPaveText(.7,.83,.93,y2,"NDC");
  tx5->SetBorderSize(1);
  tx5->AddText(s1);
  tx5->AddText(s2);
  tx5->Draw();
}

void optics(string tgt="h",string angle="21", string mom="4p0",string spec="hms",   bool rebin=false){

TCutG *c_h_xpVyp = new TCutG("C_H_XPVYP",13);
c_h_xpVyp->SetVarX("xp_fp vs yp_fp");
c_h_xpVyp->SetVarY("");
c_h_xpVyp->SetTitle("Graph");
c_h_xpVyp->SetFillStyle(1000);
c_h_xpVyp->SetPoint(0,-0.00520833,0.054803);
c_h_xpVyp->SetPoint(1,0.003125,0.054803);
c_h_xpVyp->SetPoint(2,0.00388258,0.0394089);
c_h_xpVyp->SetPoint(3,0.0220644,-0.0187808);
c_h_xpVyp->SetPoint(4,0.0220644,-0.0332512);
c_h_xpVyp->SetPoint(5,0.0172348,-0.044335);
c_h_xpVyp->SetPoint(6,0.00681818,-0.0477217);
c_h_xpVyp->SetPoint(7,-0.0105114,-0.0471059);
c_h_xpVyp->SetPoint(8,-0.0222538,-0.0344828);
c_h_xpVyp->SetPoint(9,-0.0222538,-0.0141626);
c_h_xpVyp->SetPoint(10,-0.0063447,0.0372537);
c_h_xpVyp->SetPoint(11,-0.00464015,0.054803);
c_h_xpVyp->SetPoint(12,-0.00520833,0.054803);
   
TCutG *c_h_xVxp = new TCutG("C_H_XVXP",6);
c_h_xVxp->SetVarX("x_fp vs x_fp");
c_h_xVxp->SetVarY("");
c_h_xVxp->SetTitle("Graph");
c_h_xVxp->SetFillStyle(1000);
c_h_xVxp->SetPoint(0,-0.00252525,-18.3498);
c_h_xVxp->SetPoint(1,0.0571338,21.1823);
c_h_xVxp->SetPoint(2,0.0126263,41.0099);
c_h_xVxp->SetPoint(3,-0.0520833,-32.5123);
c_h_xVxp->SetPoint(4,-0.00189394,-18.2266);
c_h_xVxp->SetPoint(5,-0.00252525,-18.3498);
   
TCutG *c_h_xVy = new TCutG("C_H_XVY",17);
c_h_xVy->SetVarX("x_fp vs y_fp");
c_h_xVy->SetVarY("");
c_h_xVy->SetTitle("Graph");
c_h_xVy->SetFillStyle(1000);
c_h_xVy->SetPoint(0,-5.87121,-1.60099);
c_h_xVy->SetPoint(1,-22.5379,27.0936);
c_h_xVy->SetPoint(2,-18.6237,36.0837);
c_h_xVy->SetPoint(3,-6.31313,39.2857);
c_h_xVy->SetPoint(4,5.17677,39.1626);
c_h_xVy->SetPoint(5,20.7071,35.3448);
c_h_xVy->SetPoint(6,5.42929,-0.738916);
c_h_xVy->SetPoint(7,4.67172,-1.84729);
c_h_xVy->SetPoint(8,14.2677,-20.4434);
c_h_xVy->SetPoint(9,15.7828,-27.4631);
c_h_xVy->SetPoint(10,11.3636,-30.4187);
c_h_xVy->SetPoint(11,-4.86111,-30.2956);
c_h_xVy->SetPoint(12,-14.2045,-26.4778);
c_h_xVy->SetPoint(13,-16.0985,-19.335);
c_h_xVy->SetPoint(14,-5.74495,-1.72414);
c_h_xVy->SetPoint(15,-5.80808,-1.47783);
c_h_xVy->SetPoint(16,-5.87121,-1.60099);
   
TCutG *c_h_ypVy = new TCutG("C_H_YPVY",8);
c_h_ypVy->SetVarX("yp_fp vs y_fp");
c_h_ypVy->SetVarY("");
c_h_ypVy->SetTitle("Graph");
c_h_ypVy->SetFillStyle(1000);
c_h_ypVy->SetPoint(0,-22.2222,-0.00295567);
c_h_ypVy->SetPoint(1,18.1187,0.0256773);
c_h_ypVy->SetPoint(2,5.49242,0.0044335);
c_h_ypVy->SetPoint(3,21.7803,0.00277094);
c_h_ypVy->SetPoint(4,-17.4874,-0.0254926);
c_h_ypVy->SetPoint(5,-5.74495,-0.00387931);
c_h_ypVy->SetPoint(6,-22.2222,-0.00314039);
c_h_ypVy->SetPoint(7,-22.2222,-0.00295567);
   
TCutG *c_s_xpVyp = new TCutG("C_S_XPVYP",13);
c_s_xpVyp->SetVarX("xp_fp vs yp_fp");
c_s_xpVyp->SetVarY("");
c_s_xpVyp->SetTitle("Graph");
c_s_xpVyp->SetFillStyle(1000);
c_s_xpVyp->SetPoint(0,0.0426136,-0.0187808);
c_s_xpVyp->SetPoint(1,0.00227273,0.0788177);
c_s_xpVyp->SetPoint(2,-0.00785985,0.0788177);
c_s_xpVyp->SetPoint(3,-0.009375,0.0597291);
c_s_xpVyp->SetPoint(4,-0.0419508,-0.0184729);
c_s_xpVyp->SetPoint(5,-0.0442235,-0.0434113);
c_s_xpVyp->SetPoint(6,-0.0262311,-0.0769704);
c_s_xpVyp->SetPoint(7,0.025947,-0.0763547);
c_s_xpVyp->SetPoint(8,0.0449811,-0.0508005);
c_s_xpVyp->SetPoint(9,0.0448864,-0.0224754);
c_s_xpVyp->SetPoint(10,0.0427083,-0.0187808);
c_s_xpVyp->SetPoint(11,0.0427083,-0.0187808);
c_s_xpVyp->SetPoint(12,0.0426136,-0.0187808);
   
TCutG *c_s_xVxp = new TCutG("C_S_XVXP",7);
c_s_xVxp->SetVarX("x_fp vs x_fp");
c_s_xVxp->SetVarY("");
c_s_xVxp->SetTitle("Graph");
c_s_xVxp->SetFillStyle(1000);
c_s_xVxp->SetPoint(0,0.000789141,-11.2069);
c_s_xVxp->SetPoint(1,0.0825442,18.7192);
c_s_xVxp->SetPoint(2,0.045928,37.8079);
c_s_xVxp->SetPoint(3,-0.0336174,-0.738916);
c_s_xVxp->SetPoint(4,-0.0789141,-29.3103);
c_s_xVxp->SetPoint(5,0.00157828,-10.9606);
c_s_xVxp->SetPoint(6,0.000789141,-11.2069);
   
TCutG *c_s_xVy = new TCutG("C_S_XVY",15);
c_s_xVy->SetVarX("x_fp vs y_fp");
c_s_xVy->SetVarY("");
c_s_xVy->SetTitle("Graph");
c_s_xVy->SetFillStyle(1000);
c_s_xVy->SetPoint(0,-28.851,30.0493);
c_s_xVy->SetPoint(1,-12.1212,36.9458);
c_s_xVy->SetPoint(2,1.26263,36.9458);
c_s_xVy->SetPoint(3,19.5076,27.5862);
c_s_xVy->SetPoint(4,3.91414,6.7734);
c_s_xVy->SetPoint(5,31.3763,-15.8867);
c_s_xVy->SetPoint(6,28.6616,-23.6453);
c_s_xVy->SetPoint(7,21.2753,-28.202);
c_s_xVy->SetPoint(8,-19.1288,-28.202);
c_s_xVy->SetPoint(9,-27.4621,-22.5369);
c_s_xVy->SetPoint(10,-28.1566,-15.2709);
c_s_xVy->SetPoint(11,-5.93434,6.28079);
c_s_xVy->SetPoint(12,-28.346,26.4778);
c_s_xVy->SetPoint(13,-28.7879,30.1724);
c_s_xVy->SetPoint(14,-28.851,30.0493);
   
TCutG *c_s_ypVy = new TCutG("C_S_YPVY",9);
c_s_ypVy->SetVarX("yp_fp vs y_fp");
c_s_ypVy->SetVarY("");
c_s_ypVy->SetTitle("Graph");
c_s_ypVy->SetFillStyle(1000);
c_s_ypVy->SetPoint(0,31.1869,0.0478448);
c_s_ypVy->SetPoint(1,-30.4924,-0.00942118);
c_s_ypVy->SetPoint(2,-6.56566,-0.00609606);
c_s_ypVy->SetPoint(3,-31.1237,-0.0452586);
c_s_ypVy->SetPoint(4,19.1919,-0.00184729);
c_s_ypVy->SetPoint(5,4.79798,0.00184729);
c_s_ypVy->SetPoint(6,33.2071,0.0482143);
c_s_ypVy->SetPoint(7,30.7449,0.0478448);
c_s_ypVy->SetPoint(8,31.1869,0.0478448);

  //  gStyle->SetOptStat(0);
  gStyle->SetOptStat(0);
  gStyle->SetTitleX(.35);
  gStyle->SetTitleY(.98);
  gStyle->SetTitleH(.06);
  gStyle->SetTitleW(.3);
  gStyle->SetTitleBorderSize(1);
  string kin=tgt+angle+"deg"+mom; 
  TString kinInfo1=spec+"  target: "+tgt;
  TString kinInfo2=angle+"deg.  "+mom+ " GeV";
  cout << "Kinematic is : "<<kin<<endl;
  Int_t DRAW=1;
  bool scale_em=true;
  //  rebin=false;
  //gROOT->ForceStyle();

  //*****MC Histograms*****
  TFile *fm=new TFile(Form("mcWtOut/pass65/%s_mcWt%s.root",spec.c_str(),kin.c_str()));
  if(!fm->IsOpen())return;
  TH2F *hm_xVy=(TH2F*)fm->Get("mc_xVy");
  TH2F *hm_xpVyp=(TH2F*)fm->Get("mc_xpVyp");
  TH2F *hm_xVxp=(TH2F*)fm->Get("mc_xVxp");
  TH2F *hm_ypVy=(TH2F*)fm->Get("mc_ypVy");
  TH2F *hm_yptarVytar=(TH2F*)fm->Get("mc_yptarVytar");

 //****Data Histograms***** 
 TFile *fd=new TFile(Form("dataYieldOut/pass55/%s_dataYield_%s.root",spec.c_str(),kin.c_str()));
 if(!fd->IsOpen())return;
 TH1F *hdd=(TH1F*)fd->Get("hdd");
 TH2F *hd_xVy=(TH2F*)fd->Get("xVy");
 TH2F *hd_xpVyp=(TH2F*)fd->Get("xpVyp");
 TH2F *hd_xVxp=(TH2F*)fd->Get("xVxp");
 TH2F *hd_ypVy=(TH2F*)fd->Get("ypVy");
 TH2F *hd_yptarVytar=(TH2F*)fd->Get("yptarVytar");
 TH2F *hBoilCorr=(TH2F*)fd->Get("hBoilCorr");
 hBoilCorr->Divide(hdd);
 double densityCorr=hBoilCorr->GetBinContent(30);
 cout << " The boiling factor is "<<densityCorr<<endl;

 //=============================
 // Charge Normalize data yields
 //=============================
 Float_t charge=0;
 if(spec=="shms")charge=getCharge(tgt,angle,mom);
 if(spec=="hms")charge=getHMSCharge(kin);
 cout << "The Charge is: "<<charge<<endl;

 charge=charge;
 hd_xVy->Scale(1./charge);
 hd_xpVyp->Scale(1./charge);
 hd_xVxp->Scale(1./charge);
 hd_ypVy->Scale(1./charge);
 hd_yptarVytar->Scale(1./charge);


 // Clone data histos to subtract dummy
 TH2F *hs_xVy=(TH2F*)hd_xVy->Clone();
 TH2F *hs_xpVyp=(TH2F*)hd_xpVyp->Clone();
 TH2F *hs_xVxp=(TH2F*)hd_xVxp->Clone();
 TH2F *hs_ypVy=(TH2F*)hd_ypVy->Clone();
 TH2F *hs_yptarVytar=(TH2F*)hd_yptarVytar->Clone();

 hs_xVy->SetName("hs_xVy");
 hs_xVy->SetName("hs_xpVyp");
 hs_xVy->SetName("hs_xVxp");
 hs_xVy->SetName("hs_ypVy");
 hs_xVy->SetName("hs_yptarVytar");

 //=============================
 // Dummy normalized data yields
 //=============================
   Float_t charged=0;
   if(spec=="hms")
     {
       if(kin=="h21deg3p3"||kin=="d21deg3p3"){
	 charged+=readReport(1641,"BCM4C charge");
       }
       if(kin=="h21deg4p0"||kin=="d21deg4p0"){
	 charged+=readReport(1628,"BCM4C charge");
	 charged+=readReport(1629,"BCM4C charge");
       }
       if(kin=="h21deg4p5"||kin=="d21deg4p5"){
	 charged+=readReport(1609,"BCM4C charge");
	 charged+=readReport(1610,"BCM4C charge");
       }
       if(kin=="h21deg5p1"||kin=="d21deg5p1"){
	 charged+=readReport(1596,"BCM4C charge");
       }
       if(kin=="h21deg5p7"||kin=="d21deg5p7"){
	 charged+=readReport(1573,"BCM4C charge");
       }
     }
   if(spec=="shms")charged=getCharge("al",angle,mom);

   TH2F *he_xVy, *he_xpVyp, *he_xVxp, *he_ypVy, *he_yptarVytar;
 if(tgt!="c")
   {
     string dummyFile="al"+angle+"deg"+mom+"_"+tgt; 
     TFile *fdum=new TFile(Form("dataYieldOut/pass55/%s_dataYield_%s.root",spec.c_str(),dummyFile.c_str()));;
     if(!fdum->IsOpen())return;

     he_xVy=(TH2F*)fdum->Get("xVy");
     he_xpVyp=(TH2F*)fdum->Get("xpVyp");
     he_xVxp=(TH2F*)fdum->Get("xVxp");
     he_ypVy=(TH2F*)fdum->Get("ypVy");
     he_yptarVytar=(TH2F*)fdum->Get("yptarVytar");
     he_xVy->SetName("he_xVy");
     he_xVy->SetName("he_xpVyp");
     he_xVy->SetName("he_xVxp");
     he_xVy->SetName("he_ypVy");
     he_xVy->SetName("he_yptarVytar");

   }
 
 he_xVy->Scale(1./charged);
 he_xpVyp->Scale(1./charged);
 he_xVxp->Scale(1./charged);
 he_ypVy->Scale(1./charged);
 he_yptarVytar->Scale(1./charged);

 // Dummy subtraction
 hs_xVy->Add(he_xVy,-1);
 hs_xpVyp->Add(he_xpVyp,-1);
 hs_xVxp->Add(he_xVxp,-1);
 hs_ypVy->Add(he_ypVy,-1);
 hs_yptarVytar->Add(he_yptarVytar,-1);

 hs_xVy->Scale(1./densityCorr);
 hs_xpVyp->Scale(1./densityCorr);
 hs_xVxp->Scale(1./densityCorr);
 hs_ypVy->Scale(1./densityCorr);
 hs_yptarVytar->Scale(1./densityCorr);
 double m1=fixRange(hm_xVy);
 double m2= fixRange(hm_xpVyp);
 double m3= fixRange(hm_xVxp);
 double m4= fixRange(hm_ypVy);
 double m5= fixRange(hs_yptarVytar);
 fixRange(hs_xVy,m1);
 fixRange(hs_xpVyp,m2);
 fixRange(hs_xVxp,m3);
 fixRange(hs_ypVy,m4);
 fixRange(hs_yptarVytar,m5);
 fixRange(hd_xVy,m1);
 fixRange(hd_xpVyp,m2);
 fixRange(hd_xVxp,m3);
 fixRange(hd_ypVy,m4);
 fixRange(hs_yptarVytar,m5);
 fixRange(he_xVy,m1);
 fixRange(he_xpVyp,m2);
 fixRange(he_xVxp,m3);
 fixRange(he_ypVy,m4);
 fixRange(hs_yptarVytar,m5);


 TCanvas *c1=new TCanvas();
 c1->Divide(2,2);
 c1->cd(1);
 hm_xVy->Draw("COLZ");
 if(spec=="shms")c_s_xVy->Draw("same");
 if(spec=="hms")c_h_xVy->Draw("same");
 c1->cd(2);
 hs_xVy->Draw("COLZ");
 if(spec=="shms")c_s_xVy->Draw("same");
 if(spec=="hms")c_h_xVy->Draw("same");
 c1->cd(3);
 hd_xVy->Draw("COLZ");
 if(spec=="shms")c_s_xVy->Draw("same");
 if(spec=="hms")c_h_xVy->Draw("same");
 c1->cd(4);
 he_xVy->Draw("COLZ");
 if(spec=="shms")c_s_xVy->Draw("same");
 if(spec=="hms")c_h_xVy->Draw("same");
 format(kinInfo1,kinInfo2,c1);
 c1->SaveAs(Form("OpticsOut/pass306/%s_optics_c1__%s.pdf",spec.c_str(),kin.c_str()));

 TCanvas *c2=new TCanvas();
 c2->Divide(2,2);
 c2->cd(1);
 hm_xpVyp->Draw("COLZ");
 if(spec=="shms")c_s_xpVyp->Draw("same");
 if(spec=="hms")c_h_xpVyp->Draw("same");
 c2->cd(2);
 hs_xpVyp->Draw("COLZ");
 if(spec=="shms")c_s_xpVyp->Draw("same");
 if(spec=="hms")c_h_xpVyp->Draw("same");
 c2->cd(3);
 hd_xpVyp->Draw("COLZ");
 if(spec=="shms")c_s_xpVyp->Draw("same");
 if(spec=="hms")c_h_xpVyp->Draw("same");
 c2->cd(4);
 he_xpVyp->Draw("COLZ");
 if(spec=="shms")c_s_xpVyp->Draw("same");
 if(spec=="hms")c_h_xpVyp->Draw("same");
 format(kinInfo1,kinInfo2,c2);
 c2->SaveAs(Form("OpticsOut/pass306/%s_optics_c2_%s.pdf",spec.c_str(),kin.c_str()));

 TCanvas *c3=new TCanvas();
 c3->Divide(2,2);
 c3->cd(1);
 hm_xVxp->Draw("COLZ");
 if(spec=="shms")c_s_xVxp->Draw("same");
 if(spec=="hms")c_h_xVxp->Draw("same");
 c3->cd(2);
 hs_xVxp->Draw("COLZ");
 if(spec=="shms")c_s_xVxp->Draw("same");
 if(spec=="hms")c_h_xVxp->Draw("same");
 c3->cd(3);
 hd_xVxp->Draw("COLZ");
 if(spec=="shms")c_s_xVxp->Draw("same");
 if(spec=="hms")c_h_xVxp->Draw("same");
 c3->cd(4);
 he_xVxp->Draw("COLZ");
 if(spec=="shms")c_s_xVxp->Draw("same");
 if(spec=="hms")c_h_xVxp->Draw("same");
 format(kinInfo1,kinInfo2,c3);
 c3->SaveAs(Form("OpticsOut/pass306/%s_optics_c3_%s.pdf",spec.c_str(),kin.c_str()));

 TCanvas *c4=new TCanvas();
 c4->Divide(2,2);
 c4->cd(1);
 hm_ypVy->Draw("COLZ");
 if(spec=="shms")c_s_ypVy->Draw("same");
 if(spec=="hms")c_h_ypVy->Draw("same");
 c4->cd(2);
 hs_ypVy->Draw("COLZ");
 if(spec=="shms")c_s_ypVy->Draw("same");
 if(spec=="hms")c_h_ypVy->Draw("same"); c4->cd(3);
 hd_ypVy->Draw("COLZ");
 if(spec=="shms")c_s_ypVy->Draw("same");
 if(spec=="hms")c_h_ypVy->Draw("same");
 c4->cd(4);
 he_ypVy->Draw("COLZ");
 if(spec=="shms")c_s_ypVy->Draw("same");
 if(spec=="hms")c_h_ypVy->Draw("same");
 format(kinInfo1,kinInfo2,c4);
 c4->SaveAs(Form("OpticsOut/pass306/%s_optics_c4_%s.pdf",spec.c_str(),kin.c_str()));
 
 TCanvas *c5=new TCanvas();
 c5->Divide(2,2);
 c5->cd(1);
 hm_yptarVytar->Draw("COLZ");
 c5->cd(2);
 hs_yptarVytar->Draw("COLZ");
 c5->cd(3);
 hd_yptarVytar->Draw("COLZ");
 c5->cd(4);
 he_yptarVytar->Draw("COLZ");
 format(kinInfo1,kinInfo2,c5);
 c5->SaveAs(Form("OpticsOut/pass306/%s_optics_c5_%s.pdf",spec.c_str(),kin.c_str()));
 


 return;
}
