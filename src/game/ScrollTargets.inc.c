#include <PR/ultratypes.h>
#include "sm64.h"
#include "types.h"

//Q. Why does this exist instead of just directly referencing VBs?
//A. Because gcc is dumb and will seg fault if you reference a VB by abstracting it through a bparam
//instead of directly refencing it, causing this horrible shit.
extern Vtx VB_ccm_1_0xe03f240[];
extern Vtx VB_ccm_1_0xe057f70[];
extern Vtx VB_castle_inside_1_0xe01c540[];
extern Vtx VB_castle_inside_1_0xe0248a0[];
extern Vtx VB_castle_inside_1_0xe024da0[];
extern Vtx VB_castle_inside_1_0xe026240[];
extern Vtx VB_castle_inside_1_0xe0169f0[];
extern Vtx VB_castle_inside_1_0xe01c5a0[];
extern Vtx VB_castle_inside_1_0xe024900[];
extern Vtx VB_castle_inside_1_0xe024f20[];
extern Vtx VB_castle_inside_1_0xe0262a0[];
extern Vtx VB_castle_inside_1_0xe031550[];
extern Vtx VB_castle_inside_1_0xe0317d0[];
extern Vtx VB_castle_inside_1_0xe0319b0[];
extern Vtx VB_castle_inside_3_0xe033d30[];
extern Vtx VB_castle_inside_3_0xe055b70[];
extern Vtx VB_castle_inside_3_0xe056cc0[];
extern Vtx VB_castle_inside_3_0xe03f6a0[];
extern Vtx VB_castle_inside_3_0xe04fda0[];
extern Vtx VB_hmc_1_0xe060fc0[];
extern Vtx VB_hmc_1_0xe06d900[];
extern Vtx VB_ssl_1_0xe030370[];
extern Vtx VB_ssl_1_0xe05b990[];
extern Vtx VB_ssl_1_0xe07dfe0[];
extern Vtx VB_ssl_1_0xe087880[];
extern Vtx VB_ssl_1_0xe0895c0[];
extern Vtx VB_bob_1_0xe04a3e0[];
extern Vtx VB_bob_1_0xe0758f0[];
extern Vtx VB_bob_1_0xe09d0b0[];
extern Vtx VB_sl_1_0xe045460[];
extern Vtx VB_sl_1_0xe048d00[];
extern Vtx VB_sl_1_0xe04c840[];
extern Vtx VB_sl_1_0xe058a00[];
extern Vtx VB_sl_1_0xe0663e0[];
extern Vtx VB_sl_1_0xe0a3b30[];
extern Vtx VB_sl_1_0xe067800[];
extern Vtx VB_sl_1_0xe0a3090[];
extern Vtx VB_wdw_1_0xe052e60[];
extern Vtx VB_wdw_1_0xe057fc0[];
extern Vtx VB_wdw_1_0xe075e10[];
extern Vtx VB_jrb_1_0xe039d60[];
extern Vtx VB_jrb_1_0xe0402b0[];
extern Vtx VB_jrb_1_0xe041120[];
extern Vtx VB_jrb_1_0xe047fb0[];
extern Vtx VB_jrb_1_0xe053ad0[];
extern Vtx VB_thi_1_0xe04cfd0[];
extern Vtx VB_thi_1_0xe054690[];
extern Vtx VB_thi_1_0xe055b60[];
extern Vtx VB_thi_1_0xe059cf0[];
extern Vtx VB_thi_1_0xe0b66f0[];
extern Vtx VB_thi_1_0xe0c4ea0[];
extern Vtx VB_thi_1_0xe0c8340[];
extern Vtx VB_thi_1_0xe0c8510[];
extern Vtx VB_thi_1_0xe0c8630[];
extern Vtx VB_thi_1_0xe0d5c10[];
extern Vtx VB_thi_1_0xe0dacc0[];
extern Vtx VB_thi_1_0xe0e0440[];
extern Vtx VB_thi_1_0xe0e0a20[];
extern Vtx VB_thi_1_0xe0e4380[];
extern Vtx VB_thi_1_0xe0e43e0[];
extern Vtx VB_thi_1_0xe0e44f0[];
extern Vtx VB_thi_1_0xe0e45c0[];
extern Vtx VB_rr_1_0xe03af60[];
extern Vtx VB_rr_1_0xe043450[];
extern Vtx VB_rr_1_0xe043930[];
extern Vtx VB_rr_1_0xe043e10[];
extern Vtx VB_rr_1_0xe0442f0[];
extern Vtx VB_rr_1_0xe0447d0[];
extern Vtx VB_rr_1_0xe044cb0[];
extern Vtx VB_rr_1_0xe045190[];
extern Vtx VB_rr_1_0xe045670[];
extern Vtx VB_rr_1_0xe045b50[];
extern Vtx VB_rr_1_0xe046030[];
extern Vtx VB_rr_1_0xe046510[];
extern Vtx VB_rr_1_0xe0469f0[];
extern Vtx VB_rr_1_0xe046ed0[];
extern Vtx VB_rr_1_0xe0473b0[];
extern Vtx VB_rr_1_0xe047890[];
extern Vtx VB_rr_1_0xe047d70[];
extern Vtx VB_rr_1_0xe048250[];
extern Vtx VB_rr_1_0xe048730[];
extern Vtx VB_rr_1_0xe063b80[];
extern Vtx VB_rr_1_0xe072750[];
extern Vtx VB_rr_1_0xe078f20[];
extern Vtx VB_rr_1_0xe06cbe0[];
extern Vtx VB_rr_2_0xe00c820[];
extern Vtx VB_rr_2_0xe017bf0[];
extern Vtx VB_rr_2_0xe01ab00[];
extern Vtx VB_rr_2_0xe01ae00[];
extern Vtx VB_rr_2_0xe01af80[];
extern Vtx VB_rr_2_0xe01b3a0[];
extern Vtx VB_rr_2_0xe01b9a0[];
extern Vtx VB_rr_2_0xe01c0c0[];
extern Vtx VB_rr_2_0xe01cde0[];
extern Vtx VB_rr_2_0xe020cb0[];
extern Vtx VB_rr_2_0xe026350[];
extern Vtx VB_rr_2_0xe0273d0[];
extern Vtx VB_rr_2_0xe028810[];
extern Vtx VB_rr_2_0xe028db0[];
extern Vtx VB_rr_2_0xe0294d0[];
extern Vtx VB_rr_2_0xe029a70[];
extern Vtx VB_rr_2_0xe02a190[];
extern Vtx VB_rr_2_0xe02b3f0[];
extern Vtx VB_castle_grounds_1_0xe0625c0[];
extern Vtx VB_castle_grounds_1_0xe065830[];
extern Vtx VB_castle_grounds_1_0xe08ef30[];
extern Vtx VB_castle_grounds_1_0xe0b0a40[];
extern Vtx VB_castle_grounds_1_0xe0b52a0[];
extern Vtx VB_castle_grounds_1_0xe0ba640[];
extern Vtx VB_castle_grounds_1_0xe0bc8c0[];
extern Vtx VB_castle_grounds_1_0xe0bd700[];
extern Vtx VB_castle_grounds_1_0xe0bd880[];
extern Vtx VB_castle_grounds_1_0xe0bd940[];
extern Vtx VB_castle_grounds_1_0xe0bab80[];
extern Vtx VB_castle_grounds_2_0xe0415b0[];
extern Vtx VB_castle_grounds_2_0xe0498f0[];
extern Vtx VB_castle_grounds_2_0xe04bff0[];
extern Vtx VB_castle_grounds_2_0xe051e00[];
extern Vtx VB_castle_grounds_2_0xe04c4c0[];
extern Vtx VB_castle_grounds_2_0xe052040[];
extern Vtx VB_castle_grounds_2_0xe053680[];
extern Vtx VB_castle_grounds_3_0xe005020[];
extern Vtx VB_castle_grounds_3_0xe00dd50[];
extern Vtx VB_castle_grounds_3_0xe0058f0[];
extern Vtx VB_castle_grounds_3_0xe00e4d0[];
extern Vtx VB_castle_grounds_3_0xe015fa0[];
extern Vtx VB_castle_grounds_3_0xe018f70[];
extern Vtx VB_vcutm_1_0xe032530[];
extern Vtx VB_vcutm_1_0xe050630[];
extern Vtx VB_vcutm_1_0xe0506b0[];
extern Vtx VB_vcutm_1_0xe051090[];
extern Vtx VB_vcutm_1_0xe051110[];
extern Vtx VB_vcutm_1_0xe054790[];
extern Vtx VB_vcutm_1_0xe054810[];
extern Vtx VB_vcutm_1_0xe055e70[];
extern Vtx VB_vcutm_1_0xe055ef0[];
extern Vtx VB_vcutm_1_0xe07dda0[];
extern Vtx VB_vcutm_1_0xe083400[];
extern Vtx VB_vcutm_1_0xe083640[];
extern Vtx VB_vcutm_1_0xe083aa0[];
extern Vtx VB_vcutm_1_0xe083f00[];
extern Vtx VB_vcutm_1_0xe0860a0[];
extern Vtx VB_vcutm_1_0xe08f210[];
extern Vtx VB_vcutm_1_0xe08f290[];
extern Vtx VB_vcutm_1_0xe094010[];
extern Vtx VB_vcutm_1_0xe095c00[];
extern Vtx VB_vcutm_1_0xe095d20[];
extern Vtx VB_vcutm_1_0xe095e40[];
extern Vtx VB_vcutm_1_0xe095f60[];
extern Vtx VB_vcutm_1_0xe096640[];
extern Vtx VB_vcutm_1_0xe0966c0[];
extern Vtx VB_vcutm_1_0xe0967e0[];
extern Vtx VB_vcutm_1_0xe096900[];
extern Vtx VB_sa_1_0xe026cb0[];
extern Vtx VB_sa_1_0xe038800[];
extern Vtx VB_sa_1_0xe049be0[];
extern Vtx VB_sa_1_0xe04af80[];
extern Vtx VB_sa_1_0xe06fd40[];
extern Vtx VB_sa_1_0xe04c7d0[];
extern Vtx VB_sa_1_0xe056380[];
extern Vtx VB_sa_1_0xe0639f0[];
extern Vtx VB_sa_1_0xe06d000[];
extern Vtx VB_lll_1_0xe03ed50[];
extern Vtx VB_lll_1_0xe03f1b0[];
extern Vtx VB_lll_1_0xe0558e0[];
extern Vtx VB_lll_1_0xe0a4050[];
extern Vtx VB_lll_1_0xe0b27b0[];
extern Vtx VB_lll_1_0xe06f2a0[];
extern Vtx VB_lll_1_0xe0a4010[];
extern Vtx VB_ddd_1_0xe0384e0[];
extern Vtx VB_ddd_1_0xe0385c0[];
extern Vtx VB_ddd_1_0xe04c9c0[];
extern Vtx VB_ddd_1_0xe0599b0[];
extern Vtx VB_ddd_1_0xe059d80[];
extern Vtx VB_ddd_1_0xe05c7e0[];
extern Vtx VB_ddd_1_0xe061520[];
extern Vtx VB_ddd_1_0xe063cf0[];
extern Vtx VB_ddd_2_0xe005490[];
extern Vtx VB_wf_1_0xe07a520[];
extern Vtx VB_wf_1_0xe0eb6e0[];
extern Vtx VB_wf_1_0xe0eb0e0[];
extern Vtx VB_ending_3_0xe00b020[];
extern Vtx VB_ending_3_0xe00c120[];
extern Vtx VB_ending_3_0xe00e560[];
extern Vtx VB_ending_3_0xe00fb00[];
extern Vtx VB_ending_3_0xe010f80[];
extern Vtx VB_ending_3_0xe0168d0[];
extern Vtx VB_ending_3_0xe018d00[];
extern Vtx VB_ending_4_0xe013d10[];
extern Vtx VB_ending_4_0xe0202a0[];
extern Vtx VB_ending_7_0xe005a90[];
extern Vtx VB_castle_courtyard_1_0xe03fcd0[];
extern Vtx VB_castle_courtyard_1_0xe043210[];
extern Vtx VB_castle_courtyard_1_0xe046750[];
extern Vtx VB_castle_courtyard_1_0xe049c90[];
extern Vtx VB_castle_courtyard_1_0xe04d1d0[];
extern Vtx VB_castle_courtyard_1_0xe050710[];
extern Vtx VB_castle_courtyard_1_0xe053c50[];
extern Vtx VB_castle_courtyard_1_0xe057190[];
extern Vtx VB_castle_courtyard_1_0xe05a6d0[];
extern Vtx VB_castle_courtyard_1_0xe05dc10[];
extern Vtx VB_castle_courtyard_1_0xe061150[];
extern Vtx VB_castle_courtyard_1_0xe064690[];
extern Vtx VB_castle_courtyard_1_0xe067bd0[];
extern Vtx VB_castle_courtyard_1_0xe06b110[];
extern Vtx VB_castle_courtyard_1_0xe06e650[];
extern Vtx VB_castle_courtyard_1_0xe03fd30[];
extern Vtx VB_castle_courtyard_1_0xe03fed0[];
extern Vtx VB_castle_courtyard_1_0xe0400b0[];
extern Vtx VB_castle_courtyard_1_0xe040290[];
extern Vtx VB_castle_courtyard_1_0xe040470[];
extern Vtx VB_castle_courtyard_1_0xe043270[];
extern Vtx VB_castle_courtyard_1_0xe043410[];
extern Vtx VB_castle_courtyard_1_0xe0435f0[];
extern Vtx VB_castle_courtyard_1_0xe0437d0[];
extern Vtx VB_castle_courtyard_1_0xe0439b0[];
extern Vtx VB_castle_courtyard_1_0xe0467b0[];
extern Vtx VB_castle_courtyard_1_0xe046950[];
extern Vtx VB_castle_courtyard_1_0xe046b30[];
extern Vtx VB_castle_courtyard_1_0xe046d10[];
extern Vtx VB_castle_courtyard_1_0xe046ef0[];
extern Vtx VB_castle_courtyard_1_0xe049cf0[];
extern Vtx VB_castle_courtyard_1_0xe049e90[];
extern Vtx VB_castle_courtyard_1_0xe04a070[];
extern Vtx VB_castle_courtyard_1_0xe04a250[];
extern Vtx VB_castle_courtyard_1_0xe04a430[];
extern Vtx VB_castle_courtyard_1_0xe04d230[];
extern Vtx VB_castle_courtyard_1_0xe04d3d0[];
extern Vtx VB_castle_courtyard_1_0xe04d5b0[];
extern Vtx VB_castle_courtyard_1_0xe04d790[];
extern Vtx VB_castle_courtyard_1_0xe04d970[];
extern Vtx VB_castle_courtyard_1_0xe050770[];
extern Vtx VB_castle_courtyard_1_0xe050910[];
extern Vtx VB_castle_courtyard_1_0xe050af0[];
extern Vtx VB_castle_courtyard_1_0xe050cd0[];
extern Vtx VB_castle_courtyard_1_0xe050eb0[];
extern Vtx VB_castle_courtyard_1_0xe053cb0[];
extern Vtx VB_castle_courtyard_1_0xe053e50[];
extern Vtx VB_castle_courtyard_1_0xe054030[];
extern Vtx VB_castle_courtyard_1_0xe054210[];
extern Vtx VB_castle_courtyard_1_0xe0543f0[];
extern Vtx VB_castle_courtyard_1_0xe0571f0[];
extern Vtx VB_castle_courtyard_1_0xe057390[];
extern Vtx VB_castle_courtyard_1_0xe057570[];
extern Vtx VB_castle_courtyard_1_0xe057750[];
extern Vtx VB_castle_courtyard_1_0xe057930[];
extern Vtx VB_castle_courtyard_1_0xe05a730[];
extern Vtx VB_castle_courtyard_1_0xe05a8d0[];
extern Vtx VB_castle_courtyard_1_0xe05aab0[];
extern Vtx VB_castle_courtyard_1_0xe05ac90[];
extern Vtx VB_castle_courtyard_1_0xe05ae70[];
extern Vtx VB_castle_courtyard_1_0xe05dc70[];
extern Vtx VB_castle_courtyard_1_0xe05de10[];
extern Vtx VB_castle_courtyard_1_0xe05dff0[];
extern Vtx VB_castle_courtyard_1_0xe05e1d0[];
extern Vtx VB_castle_courtyard_1_0xe05e3b0[];
extern Vtx VB_castle_courtyard_1_0xe0611b0[];
extern Vtx VB_castle_courtyard_1_0xe061350[];
extern Vtx VB_castle_courtyard_1_0xe061530[];
extern Vtx VB_castle_courtyard_1_0xe061710[];
extern Vtx VB_castle_courtyard_1_0xe0618f0[];
extern Vtx VB_castle_courtyard_1_0xe0646f0[];
extern Vtx VB_castle_courtyard_1_0xe064890[];
extern Vtx VB_castle_courtyard_1_0xe064a70[];
extern Vtx VB_castle_courtyard_1_0xe064c50[];
extern Vtx VB_castle_courtyard_1_0xe064e30[];
extern Vtx VB_castle_courtyard_1_0xe067c30[];
extern Vtx VB_castle_courtyard_1_0xe067dd0[];
extern Vtx VB_castle_courtyard_1_0xe067fb0[];
extern Vtx VB_castle_courtyard_1_0xe068190[];
extern Vtx VB_castle_courtyard_1_0xe068370[];
extern Vtx VB_castle_courtyard_1_0xe06b170[];
extern Vtx VB_castle_courtyard_1_0xe06b310[];
extern Vtx VB_castle_courtyard_1_0xe06b4f0[];
extern Vtx VB_castle_courtyard_1_0xe06b6d0[];
extern Vtx VB_castle_courtyard_1_0xe06b8b0[];
extern Vtx VB_castle_courtyard_1_0xe06e6b0[];
extern Vtx VB_castle_courtyard_1_0xe06e850[];
extern Vtx VB_castle_courtyard_1_0xe06ea30[];
extern Vtx VB_castle_courtyard_1_0xe06ec10[];
extern Vtx VB_castle_courtyard_1_0xe06edf0[];
extern Vtx VB_castle_courtyard_2_0xe00df10[];
extern Vtx VB_castle_courtyard_2_0xe00f510[];
extern Vtx VB_castle_courtyard_2_0xe013500[];
extern Vtx VB_castle_courtyard_3_0xe0112e0[];
extern Vtx VB_castle_courtyard_3_0xe018e20[];
extern Vtx VB_castle_courtyard_3_0xe00e690[];
extern Vtx VB_castle_courtyard_3_0xe0161d0[];
extern Vtx VB_castle_courtyard_4_0xe00aed0[];
extern Vtx VB_castle_courtyard_4_0xe00c4f0[];
extern Vtx VB_castle_courtyard_4_0xe0104e0[];
extern Vtx VB_pss_1_0xe00bac0[];
extern Vtx VB_pss_2_0xe005f80[];
extern Vtx VB_pss_3_0xe00e0a0[];
extern Vtx VB_pss_3_0xe00eb40[];
extern Vtx VB_pss_3_0xe013180[];
extern Vtx VB_pss_3_0xe013680[];
extern Vtx VB_pss_3_0xe017440[];
extern Vtx VB_pss_3_0xe017940[];
extern Vtx VB_pss_3_0xe01a060[];
extern Vtx VB_pss_3_0xe01a560[];
extern Vtx VB_pss_3_0xe01e320[];
extern Vtx VB_pss_3_0xe01fec0[];
extern Vtx VB_pss_3_0xe020520[];
extern Vtx VB_pss_5_0xe005a90[];
extern Vtx VB_pss_6_0xe006ea0[];
extern Vtx VB_pss_6_0xe007660[];
extern Vtx VB_cotmc_2_0xe03ad90[];
extern Vtx VB_cotmc_2_0xe03ae10[];
extern Vtx VB_cotmc_2_0xe03ae50[];
extern Vtx VB_cotmc_2_0xe03aed0[];
extern Vtx VB_cotmc_2_0xe03af50[];
extern Vtx VB_cotmc_2_0xe03afd0[];
extern Vtx VB_cotmc_2_0xe03b010[];
extern Vtx VB_cotmc_2_0xe03b090[];
extern Vtx VB_cotmc_2_0xe06e3e0[];
extern Vtx VB_cotmc_2_0xe091eb0[];
extern Vtx VB_cotmc_2_0xe0925d0[];
extern Vtx VB_cotmc_2_0xe092a10[];
extern Vtx VB_cotmc_2_0xe093130[];
extern Vtx VB_cotmc_2_0xe093570[];
extern Vtx VB_cotmc_2_0xe093c90[];
extern Vtx VB_cotmc_2_0xe094e00[];
extern Vtx VB_cotmc_2_0xe095520[];
extern Vtx VB_cotmc_2_0xe095960[];
extern Vtx VB_cotmc_2_0xe096080[];
extern Vtx VB_cotmc_2_0xe09aa20[];
extern Vtx VB_cotmc_2_0xe09b140[];
extern Vtx VB_cotmc_2_0xe09b580[];
extern Vtx VB_cotmc_2_0xe09bca0[];
extern Vtx VB_cotmc_2_0xe09deb0[];
extern Vtx VB_cotmc_2_0xe09e5d0[];
extern Vtx VB_cotmc_2_0xe09ea10[];
extern Vtx VB_cotmc_2_0xe09f130[];
extern Vtx VB_cotmc_2_0xe09f570[];
extern Vtx VB_cotmc_2_0xe09fc90[];
extern Vtx VB_totwc_1_0xe01f730[];
extern Vtx VB_totwc_1_0xe024da0[];
extern Vtx VB_totwc_1_0xe02e5e0[];
extern Vtx VB_totwc_1_0xe034d40[];
extern Vtx VB_totwc_2_0xe021800[];
extern Vtx VB_totwc_2_0xe022250[];
extern Vtx VB_wmotr_2_0xe069e40[];
extern Vtx VB_wmotr_2_0xe082c10[];
extern Vtx VB_wmotr_2_0xe08ecf0[];
extern Vtx VB_wmotr_2_0xe08f5c0[];
extern Vtx VB_wmotr_2_0xe090440[];
extern Vtx VB_wmotr_2_0xe09b330[];
extern Vtx VB_wmotr_2_0xe09bc00[];
extern Vtx VB_wmotr_2_0xe077540[];
extern Vtx VB_wmotr_2_0xe078c60[];
extern Vtx VB_wmotr_2_0xe0bace0[];
extern Vtx VB_bowser_3_1_0xe02c150[];
extern Vtx VB_bowser_3_1_0xe0345a0[];
extern Vtx VB_bowser_3_1_0xe034a40[];
extern Vtx VB_bowser_3_1_0xe034ee0[];
extern Vtx VB_bowser_3_1_0xe035380[];
extern Vtx VB_bowser_3_1_0xe035820[];
extern Vtx VB_bowser_3_1_0xe035cc0[];
extern Vtx VB_bowser_3_1_0xe036160[];
extern Vtx VB_bowser_3_1_0xe03a380[];
extern Vtx VB_bowser_3_1_0xe03a640[];
extern Vtx VB_bowser_3_1_0xe0884f0[];
extern Vtx VB_bowser_3_1_0xe0886f0[];
extern Vtx VB_bowser_3_1_0xe02de20[];
extern Vtx VB_bowser_3_1_0xe049e30[];
Vtx *ScrollTargets[]={
 &VB_ccm_1_0xe03f240[0],
 &VB_ccm_1_0xe057f70[0],
 &VB_castle_inside_1_0xe01c540[0],
 &VB_castle_inside_1_0xe0248a0[0],
 &VB_castle_inside_1_0xe024da0[0],
 &VB_castle_inside_1_0xe026240[0],
 &VB_castle_inside_1_0xe0169f0[0],
 &VB_castle_inside_1_0xe01c5a0[0],
 &VB_castle_inside_1_0xe024900[0],
 &VB_castle_inside_1_0xe024f20[0],
 &VB_castle_inside_1_0xe0262a0[0],
 &VB_castle_inside_1_0xe031550[0],
 &VB_castle_inside_1_0xe0317d0[0],
 &VB_castle_inside_1_0xe0319b0[0],
 &VB_castle_inside_3_0xe033d30[0],
 &VB_castle_inside_3_0xe055b70[0],
 &VB_castle_inside_3_0xe056cc0[0],
 &VB_castle_inside_3_0xe03f6a0[0],
 &VB_castle_inside_3_0xe04fda0[0],
 &VB_hmc_1_0xe060fc0[0],
 &VB_hmc_1_0xe06d900[0],
 &VB_ssl_1_0xe030370[0],
 &VB_ssl_1_0xe05b990[0],
 &VB_ssl_1_0xe07dfe0[0],
 &VB_ssl_1_0xe087880[0],
 &VB_ssl_1_0xe0895c0[0],
 &VB_bob_1_0xe04a3e0[0],
 &VB_bob_1_0xe0758f0[0],
 &VB_bob_1_0xe09d0b0[0],
 &VB_sl_1_0xe045460[0],
 &VB_sl_1_0xe048d00[0],
 &VB_sl_1_0xe04c840[0],
 &VB_sl_1_0xe058a00[0],
 &VB_sl_1_0xe0663e0[0],
 &VB_sl_1_0xe0a3b30[0],
 &VB_sl_1_0xe067800[0],
 &VB_sl_1_0xe0a3090[0],
 &VB_wdw_1_0xe052e60[0],
 &VB_wdw_1_0xe057fc0[0],
 &VB_wdw_1_0xe075e10[0],
 &VB_jrb_1_0xe039d60[0],
 &VB_jrb_1_0xe0402b0[0],
 &VB_jrb_1_0xe041120[0],
 &VB_jrb_1_0xe047fb0[0],
 &VB_jrb_1_0xe053ad0[0],
 &VB_thi_1_0xe04cfd0[0],
 &VB_thi_1_0xe054690[0],
 &VB_thi_1_0xe055b60[0],
 &VB_thi_1_0xe059cf0[0],
 &VB_thi_1_0xe0b66f0[0],
 &VB_thi_1_0xe0c4ea0[0],
 &VB_thi_1_0xe0c8340[0],
 &VB_thi_1_0xe0c8510[0],
 &VB_thi_1_0xe0c8630[0],
 &VB_thi_1_0xe0d5c10[0],
 &VB_thi_1_0xe0dacc0[0],
 &VB_thi_1_0xe0e0440[0],
 &VB_thi_1_0xe0e0a20[0],
 &VB_thi_1_0xe0e4380[0],
 &VB_thi_1_0xe0e43e0[0],
 &VB_thi_1_0xe0e44f0[0],
 &VB_thi_1_0xe0e45c0[255],
 &VB_rr_1_0xe03af60[0],
 &VB_rr_1_0xe043450[0],
 &VB_rr_1_0xe043930[0],
 &VB_rr_1_0xe043e10[0],
 &VB_rr_1_0xe0442f0[0],
 &VB_rr_1_0xe0447d0[0],
 &VB_rr_1_0xe044cb0[0],
 &VB_rr_1_0xe045190[0],
 &VB_rr_1_0xe045670[0],
 &VB_rr_1_0xe045b50[0],
 &VB_rr_1_0xe046030[0],
 &VB_rr_1_0xe046510[0],
 &VB_rr_1_0xe0469f0[0],
 &VB_rr_1_0xe046ed0[0],
 &VB_rr_1_0xe0473b0[0],
 &VB_rr_1_0xe047890[0],
 &VB_rr_1_0xe047d70[0],
 &VB_rr_1_0xe048250[0],
 &VB_rr_1_0xe048730[0],
 &VB_rr_1_0xe063b80[0],
 &VB_rr_1_0xe072750[0],
 &VB_rr_1_0xe078f20[0],
 &VB_rr_1_0xe06cbe0[0],
 &VB_rr_2_0xe00c820[0],
 &VB_rr_2_0xe017bf0[0],
 &VB_rr_2_0xe01ab00[0],
 &VB_rr_2_0xe01ae00[0],
 &VB_rr_2_0xe01af80[0],
 &VB_rr_2_0xe01b3a0[0],
 &VB_rr_2_0xe01b9a0[0],
 &VB_rr_2_0xe01c0c0[0],
 &VB_rr_2_0xe01cde0[0],
 &VB_rr_2_0xe020cb0[0],
 &VB_rr_2_0xe026350[0],
 &VB_rr_2_0xe0273d0[0],
 &VB_rr_2_0xe028810[0],
 &VB_rr_2_0xe028db0[0],
 &VB_rr_2_0xe0294d0[0],
 &VB_rr_2_0xe029a70[0],
 &VB_rr_2_0xe02a190[0],
 &VB_rr_2_0xe02b3f0[0],
 &VB_castle_grounds_1_0xe0625c0[0],
 &VB_castle_grounds_1_0xe065830[0],
 &VB_castle_grounds_1_0xe08ef30[0],
 &VB_castle_grounds_1_0xe0b0a40[0],
 &VB_castle_grounds_1_0xe0b52a0[0],
 &VB_castle_grounds_1_0xe0ba640[0],
 &VB_castle_grounds_1_0xe0bc8c0[0],
 &VB_castle_grounds_1_0xe0bd700[0],
 &VB_castle_grounds_1_0xe0bd880[0],
 &VB_castle_grounds_1_0xe0bd940[0],
 &VB_castle_grounds_1_0xe0bab80[0],
 &VB_castle_grounds_2_0xe0415b0[0],
 &VB_castle_grounds_2_0xe0498f0[0],
 &VB_castle_grounds_2_0xe04bff0[0],
 &VB_castle_grounds_2_0xe051e00[0],
 &VB_castle_grounds_2_0xe04c4c0[0],
 &VB_castle_grounds_2_0xe052040[0],
 &VB_castle_grounds_2_0xe053680[0],
 &VB_castle_grounds_3_0xe005020[0],
 &VB_castle_grounds_3_0xe00dd50[0],
 &VB_castle_grounds_3_0xe0058f0[0],
 &VB_castle_grounds_3_0xe00e4d0[0],
 &VB_castle_grounds_3_0xe015fa0[0],
 &VB_castle_grounds_3_0xe018f70[0],
 &VB_vcutm_1_0xe032530[0],
 &VB_vcutm_1_0xe050630[0],
 &VB_vcutm_1_0xe0506b0[0],
 &VB_vcutm_1_0xe051090[0],
 &VB_vcutm_1_0xe051110[0],
 &VB_vcutm_1_0xe054790[0],
 &VB_vcutm_1_0xe054810[0],
 &VB_vcutm_1_0xe055e70[0],
 &VB_vcutm_1_0xe055ef0[0],
 &VB_vcutm_1_0xe07dda0[0],
 &VB_vcutm_1_0xe083400[0],
 &VB_vcutm_1_0xe083640[0],
 &VB_vcutm_1_0xe083aa0[0],
 &VB_vcutm_1_0xe083f00[0],
 &VB_vcutm_1_0xe0860a0[0],
 &VB_vcutm_1_0xe08f210[0],
 &VB_vcutm_1_0xe08f290[0],
 &VB_vcutm_1_0xe094010[0],
 &VB_vcutm_1_0xe095c00[0],
 &VB_vcutm_1_0xe095d20[0],
 &VB_vcutm_1_0xe095e40[0],
 &VB_vcutm_1_0xe095f60[0],
 &VB_vcutm_1_0xe096640[0],
 &VB_vcutm_1_0xe0966c0[0],
 &VB_vcutm_1_0xe0967e0[0],
 &VB_vcutm_1_0xe096900[0],
 &VB_sa_1_0xe026cb0[0],
 &VB_sa_1_0xe038800[0],
 &VB_sa_1_0xe049be0[0],
 &VB_sa_1_0xe04af80[0],
 &VB_sa_1_0xe06fd40[0],
 &VB_sa_1_0xe04c7d0[0],
 &VB_sa_1_0xe056380[0],
 &VB_sa_1_0xe0639f0[0],
 &VB_sa_1_0xe06d000[0],
 &VB_lll_1_0xe03ed50[0],
 &VB_lll_1_0xe03f1b0[0],
 &VB_lll_1_0xe0558e0[0],
 &VB_lll_1_0xe0a4050[0],
 &VB_lll_1_0xe0b27b0[0],
 &VB_lll_1_0xe06f2a0[0],
 &VB_lll_1_0xe0a4010[0],
 &VB_ddd_1_0xe0384e0[0],
 &VB_ddd_1_0xe0385c0[0],
 &VB_ddd_1_0xe04c9c0[0],
 &VB_ddd_1_0xe0599b0[0],
 &VB_ddd_1_0xe059d80[0],
 &VB_ddd_1_0xe05c7e0[0],
 &VB_ddd_1_0xe061520[0],
 &VB_ddd_1_0xe063cf0[0],
 &VB_ddd_2_0xe005490[0],
 &VB_wf_1_0xe07a520[0],
 &VB_wf_1_0xe0eb6e0[0],
 &VB_wf_1_0xe0eb0e0[0],
 &VB_ending_3_0xe00b020[0],
 &VB_ending_3_0xe00c120[0],
 &VB_ending_3_0xe00e560[0],
 &VB_ending_3_0xe00fb00[0],
 &VB_ending_3_0xe010f80[0],
 &VB_ending_3_0xe0168d0[0],
 &VB_ending_3_0xe018d00[0],
 &VB_ending_4_0xe013d10[0],
 &VB_ending_4_0xe0202a0[0],
 &VB_ending_7_0xe005a90[0],
 &VB_castle_courtyard_1_0xe03fcd0[0],
 &VB_castle_courtyard_1_0xe043210[0],
 &VB_castle_courtyard_1_0xe046750[0],
 &VB_castle_courtyard_1_0xe049c90[0],
 &VB_castle_courtyard_1_0xe04d1d0[0],
 &VB_castle_courtyard_1_0xe050710[0],
 &VB_castle_courtyard_1_0xe053c50[0],
 &VB_castle_courtyard_1_0xe057190[0],
 &VB_castle_courtyard_1_0xe05a6d0[0],
 &VB_castle_courtyard_1_0xe05dc10[0],
 &VB_castle_courtyard_1_0xe061150[0],
 &VB_castle_courtyard_1_0xe064690[0],
 &VB_castle_courtyard_1_0xe067bd0[0],
 &VB_castle_courtyard_1_0xe06b110[0],
 &VB_castle_courtyard_1_0xe06e650[0],
 &VB_castle_courtyard_1_0xe03fd30[0],
 &VB_castle_courtyard_1_0xe03fed0[0],
 &VB_castle_courtyard_1_0xe0400b0[0],
 &VB_castle_courtyard_1_0xe040290[0],
 &VB_castle_courtyard_1_0xe040470[0],
 &VB_castle_courtyard_1_0xe043270[0],
 &VB_castle_courtyard_1_0xe043410[0],
 &VB_castle_courtyard_1_0xe0435f0[0],
 &VB_castle_courtyard_1_0xe0437d0[0],
 &VB_castle_courtyard_1_0xe0439b0[0],
 &VB_castle_courtyard_1_0xe0467b0[0],
 &VB_castle_courtyard_1_0xe046950[0],
 &VB_castle_courtyard_1_0xe046b30[0],
 &VB_castle_courtyard_1_0xe046d10[0],
 &VB_castle_courtyard_1_0xe046ef0[0],
 &VB_castle_courtyard_1_0xe049cf0[0],
 &VB_castle_courtyard_1_0xe049e90[0],
 &VB_castle_courtyard_1_0xe04a070[0],
 &VB_castle_courtyard_1_0xe04a250[0],
 &VB_castle_courtyard_1_0xe04a430[0],
 &VB_castle_courtyard_1_0xe04d230[0],
 &VB_castle_courtyard_1_0xe04d3d0[0],
 &VB_castle_courtyard_1_0xe04d5b0[0],
 &VB_castle_courtyard_1_0xe04d790[0],
 &VB_castle_courtyard_1_0xe04d970[0],
 &VB_castle_courtyard_1_0xe050770[0],
 &VB_castle_courtyard_1_0xe050910[0],
 &VB_castle_courtyard_1_0xe050af0[0],
 &VB_castle_courtyard_1_0xe050cd0[0],
 &VB_castle_courtyard_1_0xe050eb0[0],
 &VB_castle_courtyard_1_0xe053cb0[0],
 &VB_castle_courtyard_1_0xe053e50[0],
 &VB_castle_courtyard_1_0xe054030[0],
 &VB_castle_courtyard_1_0xe054210[0],
 &VB_castle_courtyard_1_0xe0543f0[0],
 &VB_castle_courtyard_1_0xe0571f0[0],
 &VB_castle_courtyard_1_0xe057390[0],
 &VB_castle_courtyard_1_0xe057570[0],
 &VB_castle_courtyard_1_0xe057750[0],
 &VB_castle_courtyard_1_0xe057930[0],
 &VB_castle_courtyard_1_0xe05a730[0],
 &VB_castle_courtyard_1_0xe05a8d0[0],
 &VB_castle_courtyard_1_0xe05aab0[0],
 &VB_castle_courtyard_1_0xe05ac90[0],
 &VB_castle_courtyard_1_0xe05ae70[0],
 &VB_castle_courtyard_1_0xe05dc70[0],
 &VB_castle_courtyard_1_0xe05de10[0],
 &VB_castle_courtyard_1_0xe05dff0[0],
 &VB_castle_courtyard_1_0xe05e1d0[0],
 &VB_castle_courtyard_1_0xe05e3b0[0],
 &VB_castle_courtyard_1_0xe0611b0[0],
 &VB_castle_courtyard_1_0xe061350[0],
 &VB_castle_courtyard_1_0xe061530[0],
 &VB_castle_courtyard_1_0xe061710[0],
 &VB_castle_courtyard_1_0xe0618f0[0],
 &VB_castle_courtyard_1_0xe0646f0[0],
 &VB_castle_courtyard_1_0xe064890[0],
 &VB_castle_courtyard_1_0xe064a70[0],
 &VB_castle_courtyard_1_0xe064c50[0],
 &VB_castle_courtyard_1_0xe064e30[0],
 &VB_castle_courtyard_1_0xe067c30[0],
 &VB_castle_courtyard_1_0xe067dd0[0],
 &VB_castle_courtyard_1_0xe067fb0[0],
 &VB_castle_courtyard_1_0xe068190[0],
 &VB_castle_courtyard_1_0xe068370[0],
 &VB_castle_courtyard_1_0xe06b170[0],
 &VB_castle_courtyard_1_0xe06b310[0],
 &VB_castle_courtyard_1_0xe06b4f0[0],
 &VB_castle_courtyard_1_0xe06b6d0[0],
 &VB_castle_courtyard_1_0xe06b8b0[0],
 &VB_castle_courtyard_1_0xe06e6b0[0],
 &VB_castle_courtyard_1_0xe06e850[0],
 &VB_castle_courtyard_1_0xe06ea30[0],
 &VB_castle_courtyard_1_0xe06ec10[0],
 &VB_castle_courtyard_1_0xe06edf0[0],
 &VB_castle_courtyard_2_0xe00df10[0],
 &VB_castle_courtyard_2_0xe00f510[0],
 &VB_castle_courtyard_2_0xe013500[0],
 &VB_castle_courtyard_3_0xe0112e0[0],
 &VB_castle_courtyard_3_0xe018e20[0],
 &VB_castle_courtyard_3_0xe00e690[0],
 &VB_castle_courtyard_3_0xe0161d0[0],
 &VB_castle_courtyard_4_0xe00aed0[0],
 &VB_castle_courtyard_4_0xe00c4f0[0],
 &VB_castle_courtyard_4_0xe0104e0[0],
 &VB_pss_1_0xe00bac0[0],
 &VB_pss_2_0xe005f80[0],
 &VB_pss_3_0xe00e0a0[0],
 &VB_pss_3_0xe00eb40[0],
 &VB_pss_3_0xe013180[0],
 &VB_pss_3_0xe013680[0],
 &VB_pss_3_0xe017440[0],
 &VB_pss_3_0xe017940[0],
 &VB_pss_3_0xe01a060[0],
 &VB_pss_3_0xe01a560[0],
 &VB_pss_3_0xe01e320[0],
 &VB_pss_3_0xe01fec0[0],
 &VB_pss_3_0xe020520[0],
 &VB_pss_5_0xe005a90[0],
 &VB_pss_6_0xe006ea0[0],
 &VB_pss_6_0xe007660[0],
 &VB_cotmc_2_0xe03ad90[0],
 &VB_cotmc_2_0xe03ae10[0],
 &VB_cotmc_2_0xe03ae50[0],
 &VB_cotmc_2_0xe03aed0[0],
 &VB_cotmc_2_0xe03af50[0],
 &VB_cotmc_2_0xe03afd0[0],
 &VB_cotmc_2_0xe03b010[0],
 &VB_cotmc_2_0xe03b090[0],
 &VB_cotmc_2_0xe06e3e0[0],
 &VB_cotmc_2_0xe091eb0[0],
 &VB_cotmc_2_0xe0925d0[0],
 &VB_cotmc_2_0xe092a10[0],
 &VB_cotmc_2_0xe093130[0],
 &VB_cotmc_2_0xe093570[0],
 &VB_cotmc_2_0xe093c90[0],
 &VB_cotmc_2_0xe094e00[0],
 &VB_cotmc_2_0xe095520[0],
 &VB_cotmc_2_0xe095960[0],
 &VB_cotmc_2_0xe096080[0],
 &VB_cotmc_2_0xe09aa20[0],
 &VB_cotmc_2_0xe09b140[0],
 &VB_cotmc_2_0xe09b580[0],
 &VB_cotmc_2_0xe09bca0[0],
 &VB_cotmc_2_0xe09deb0[0],
 &VB_cotmc_2_0xe09e5d0[0],
 &VB_cotmc_2_0xe09ea10[0],
 &VB_cotmc_2_0xe09f130[0],
 &VB_cotmc_2_0xe09f570[0],
 &VB_cotmc_2_0xe09fc90[0],
 &VB_totwc_1_0xe01f730[0],
 &VB_totwc_1_0xe024da0[0],
 &VB_totwc_1_0xe02e5e0[0],
 &VB_totwc_1_0xe034d40[0],
 &VB_totwc_2_0xe021800[0],
 &VB_totwc_2_0xe022250[0],
 &VB_wmotr_2_0xe069e40[0],
 &VB_wmotr_2_0xe082c10[0],
 &VB_wmotr_2_0xe08ecf0[0],
 &VB_wmotr_2_0xe08f5c0[0],
 &VB_wmotr_2_0xe090440[0],
 &VB_wmotr_2_0xe09b330[0],
 &VB_wmotr_2_0xe09bc00[0],
 &VB_wmotr_2_0xe077540[0],
 &VB_wmotr_2_0xe078c60[0],
 &VB_wmotr_2_0xe0bace0[0],
 &VB_bowser_3_1_0xe02c150[0],
 &VB_bowser_3_1_0xe0345a0[0],
 &VB_bowser_3_1_0xe034a40[0],
 &VB_bowser_3_1_0xe034ee0[0],
 &VB_bowser_3_1_0xe035380[0],
 &VB_bowser_3_1_0xe035820[0],
 &VB_bowser_3_1_0xe035cc0[0],
 &VB_bowser_3_1_0xe036160[0],
 &VB_bowser_3_1_0xe03a380[0],
 &VB_bowser_3_1_0xe03a640[0],
 &VB_bowser_3_1_0xe0884f0[0],
 &VB_bowser_3_1_0xe0886f0[0],
 &VB_bowser_3_1_0xe02de20[0],
 &VB_bowser_3_1_0xe049e30[0],
};