#pragma once
#include "ofMain.h"

class AlchemyPlayer {

public:
    const static int Contrl1 = 0;
    const static int Contrl2 = 1;
    const static int Contrl3 = 2;
    const static int Contrl4 = 3;
    const static int Contrl5 = 4;
    const static int Contrl6 = 5;
    const static int Contrl7 = 6;
    const static int Contrl8 = 7;
    const static int XyPad1x = 8;
    const static int XyPad1y = 9;
    const static int XyPad2x = 10;
    const static int XyPad2y = 11;
    const static int EnvAtt = 12;
    const static int EnvDec = 13;
    const static int EnvSust = 14;
    const static int EnvRel = 15;
    const static int RemixX = 16;
    const static int RemixY = 17;
    const static int F1Cut = 18;
    const static int F1Res = 19;
    const static int F1Drive = 20;
    const static int F1FxMix = 21;
    const static int F2Cut = 22;
    const static int F2Res = 23;
    const static int F2Drive = 24;
    const static int F2FxMix = 25;
    const static int FSerMix = 26;
    const static int Amp = 27;
    const static int Pan = 28;
    const static int TuneCrs = 29;
    const static int TuneFine = 30;
    const static int Porto = 31;
    const static int Volume = 32;
    const static int ArpMode = 33;
    const static int ArpAmp = 34;
    const static int ArpPan = 35;
    const static int ArpTCrs = 36;
    const static int ArpTFine = 37;
    const static int ArpOct = 38;
    const static int ArpKVel = 39;
    const static int ArpSplit = 40;
    const static int ArpSrc = 41;
    const static int ArpLatch = 42;
    const static int MorAllX = 43;
    const static int MorAllY = 44;
    const static int MorTimeX = 45;
    const static int MorTimeY = 46;
    const static int MorAddX = 47;
    const static int MorAddY = 48;
    const static int MorSpecX = 49;
    const static int MorSpecY = 50;
    const static int MorGranX = 51;
    const static int MorGranY = 52;
    const static int MorFiltX = 53;
    const static int MorFiltY = 54;
    const static int DelLRate = 55;
    const static int DelLRat2 = 56;
    const static int DelRRate = 57;
    const static int DelRRat2 = 58;
    const static int DelLOff = 59;
    const static int DelLOff2 = 60;
    const static int DelROff = 61;
    const static int DelROff2 = 62;
    const static int DelFback = 63;
    const static int DelFbac2 = 64;
    const static int DelFbaR = 65;
    const static int DelFbaR2 = 66;
    const static int DelF1Cut = 67;
    const static int DelF1Cu2 = 68;
    const static int DelF2Cut = 69;
    const static int DelF2Cu2 = 70;
    const static int DelF1Res = 71;
    const static int DelF1Re2 = 72;
    const static int DelF2Res = 73;
    const static int DelF2Re2 = 74;
    const static int DelMix = 75;
    const static int DelMix2 = 76;
    const static int DelCross = 77;
    const static int DelCros2 = 78;
    const static int DelIPan = 79;
    const static int DelIPan2 = 80;
    const static int RevSize = 81;
    const static int RevMix = 82;
    const static int RevDamp = 83;
    const static int RevDelay = 84;
    const static int RevLoCut = 85;
    const static int RevHiCut = 86;
    const static int ModDelay = 87;
    const static int ModDela2 = 88;
    const static int ModDepth = 89;
    const static int ModDept2 = 90;
    const static int ModRate = 91;
    const static int ModRate2 = 92;
    const static int ModFback = 93;
    const static int ModFbac2 = 94;
    const static int ModMix = 95;
    const static int ModMix2 = 96;
    const static int ModSte = 97;
    const static int ModSte2 = 98;
    const static int DisCrush = 99;
    const static int DisCrus2 = 100;
    const static int DisMech = 101;
    const static int DisMech2 = 102;
    const static int DisTube = 103;
    const static int DisTube2 = 104;
    const static int DisXcita = 105;
    const static int DisXcit2 = 106;
    const static int DisPGain = 107;
    const static int DisPGai2 = 108;
    const static int FilCut = 109;
    const static int FilRes = 110;
    const static int FilDrive = 111;
    const static int FilMix = 112;
    const static int BpfLoCut = 113;
    const static int BpfLoCu2 = 114;
    const static int BpfHiCut = 115;
    const static int BpfHiCu2 = 116;
    const static int BpfLoRes = 117;
    const static int BpfLoRe2 = 118;
    const static int BpfHiRes = 119;
    const static int BpfHiRe2 = 120;
    const static int BpfBRMix = 121;
    const static int BpfBRMi2 = 122;
    const static int BEnhAmnt = 123;
    const static int BEnhTune = 124;
    const static int ComAmnt = 125;
    const static int ComRelse = 126;
    const static int PanPan = 127;
    const static int AmpAmp = 128;
    const static int AcoQual = 129;
    const static int AcoVar = 130;
    const static int AcoHold = 131;
    const static int AcoSize = 132;
    const static int AcoPreDe = 133;
    const static int AcoWidth = 134;
    const static int AcoGtAm = 135;
    const static int AcoGtAt = 136;
    const static int AcoGtRel = 137;
    const static int AcoTime = 138;
    const static int AcoDiffu = 139;
    const static int AcoEqLoF = 140;
    const static int AcoEqLoG = 141;
    const static int AcoEqHiF = 142;
    const static int AcoEqHiG = 143;
    const static int AcoMix = 144;
    const static int AcoDmpLF = 145;
    const static int AcoDmpLA = 146;
    const static int AcoDmpHF = 147;
    const static int AcoDmpHA = 148;
    const static int Eq3LoGai = 149;
    const static int Eq3LoGa2 = 150;
    const static int Eq3MiGai = 151;
    const static int Eq3MiGa2 = 152;
    const static int Eq3HiGai = 153;
    const static int Eq3HiGa2 = 154;
    const static int Eq3LoFrq = 155;
    const static int Eq3LoFr2 = 156;
    const static int Eq3MiFrq = 157;
    const static int Eq3MiFr2 = 158;
    const static int Eq3HiFrq = 159;
    const static int Eq3HiFr2 = 160;
    const static int Eq3LoBw = 161;
    const static int Eq3LoBw2 = 162;
    const static int Eq3MiBw = 163;
    const static int Eq3MiBw2 = 164;
    const static int Eq3HiBw = 165;
    const static int Eq3HiBw2 = 166;
    const static int A_Amp = 167;
    const static int B_Amp = 168;
    const static int C_Amp = 169;
    const static int D_Amp = 170;
    const static int A_Pan = 171;
    const static int B_Pan = 172;
    const static int C_Pan = 173;
    const static int D_Pan = 174;
    const static int A_TunCrs = 175;
    const static int B_TunCrs = 176;
    const static int C_TunCrs = 177;
    const static int D_TunCrs = 178;
    const static int A_TunFin = 179;
    const static int B_TunFin = 180;
    const static int C_TunFin = 181;
    const static int D_TunFin = 182;
    const static int A_Pos = 183;
    const static int B_Pos = 184;
    const static int C_Pos = 185;
    const static int D_Pos = 186;
    const static int A_Strtch = 187;
    const static int B_Strtch = 188;
    const static int C_Strtch = 189;
    const static int D_Strtch = 190;
    const static int A_FilMix = 191;
    const static int B_FilMix = 192;
    const static int C_FilMix = 193;
    const static int D_FilMix = 194;
    const static int A_AdVol = 195;
    const static int B_AdVol = 196;
    const static int C_AdVol = 197;
    const static int D_AdVol = 198;
    const static int A_AdSym = 199;
    const static int B_AdSym = 200;
    const static int C_AdSym = 201;
    const static int D_AdSym = 202;
    const static int A_AdPVar = 203;
    const static int B_AdPVar = 204;
    const static int C_AdPVar = 205;
    const static int D_AdPVar = 206;
    const static int A_AdNOsc = 207;
    const static int B_AdNOsc = 208;
    const static int C_AdNOsc = 209;
    const static int D_AdNOsc = 210;
    const static int A_AdPtch = 211;
    const static int B_AdPtch = 212;
    const static int C_AdPtch = 213;
    const static int D_AdPtch = 214;
    const static int A_AdAmp = 215;
    const static int B_AdAmp = 216;
    const static int C_AdAmp = 217;
    const static int D_AdAmp = 218;
    const static int A_AdPan = 219;
    const static int B_AdPan = 220;
    const static int C_AdPan = 221;
    const static int D_AdPan = 222;
    const static int A_AdDet = 223;
    const static int B_AdDet = 224;
    const static int C_AdDet = 225;
    const static int D_AdDet = 226;
    const static int A_SpVol = 227;
    const static int B_SpVol = 228;
    const static int C_SpVol = 229;
    const static int D_SpVol = 230;
    const static int A_SpAmp = 231;
    const static int B_SpAmp = 232;
    const static int C_SpAmp = 233;
    const static int D_SpAmp = 234;
    const static int A_SpHp = 235;
    const static int B_SpHp = 236;
    const static int C_SpHp = 237;
    const static int D_SpHp = 238;
    const static int A_SpLp = 239;
    const static int B_SpLp = 240;
    const static int C_SpLp = 241;
    const static int D_SpLp = 242;
    const static int A_GrVol = 243;
    const static int B_GrVol = 244;
    const static int C_GrVol = 245;
    const static int D_GrVol = 246;
    const static int A_GrSize = 247;
    const static int B_GrSize = 248;
    const static int C_GrSize = 249;
    const static int D_GrSize = 250;
    const static int A_GrDens = 251;
    const static int B_GrDens = 252;
    const static int C_GrDens = 253;
    const static int D_GrDens = 254;
    const static int A_GrRTim = 255;
    const static int B_GrRTim = 256;
    const static int C_GrRTim = 257;
    const static int D_GrRTim = 258;
    const static int A_GrRPan = 259;
    const static int B_GrRPan = 260;
    const static int C_GrRPan = 261;
    const static int D_GrRPan = 262;
    const static int A_F1Cut = 263;
    const static int B_F1Cut = 264;
    const static int C_F1Cut = 265;
    const static int D_F1Cut = 266;
    const static int A_F1Res = 267;
    const static int B_F1Res = 268;
    const static int C_F1Res = 269;
    const static int D_F1Res = 270;
    const static int A_F2Cut = 271;
    const static int B_F2Cut = 272;
    const static int C_F2Cut = 273;
    const static int D_F2Cut = 274;
    const static int A_F2Res = 275;
    const static int B_F2Res = 276;
    const static int C_F2Res = 277;
    const static int D_F2Res = 278;
    const static int A_F3Cut = 279;
    const static int B_F3Cut = 280;
    const static int C_F3Cut = 281;
    const static int D_F3Cut = 282;
    const static int A_F3Res = 283;
    const static int B_F3Res = 284;
    const static int C_F3Res = 285;
    const static int D_F3Res = 286;
    const static int DsPrGain = 287;
    const static int DsPrGai2 = 288;
    const static int PolPB000 = 289;
    const static int PolPB001 = 290;
    const static int PolPB002 = 291;
    const static int PolPB003 = 292;
    const static int PolPB004 = 293;
    const static int PolPB005 = 294;
    const static int PolPB006 = 295;
    const static int PolPB007 = 296;
    const static int PolPB008 = 297;
    const static int PolPB009 = 298;
    const static int PolPB010 = 299;
    const static int PolPB011 = 300;
    const static int PolPB012 = 301;
    const static int PolPB013 = 302;
    const static int PolPB014 = 303;
    const static int PolPB015 = 304;
    const static int PolPB016 = 305;
    const static int PolPB017 = 306;
    const static int PolPB018 = 307;
    const static int PolPB019 = 308;
    const static int PolPB020 = 309;
    const static int PolPB021 = 310;
    const static int PolPB022 = 311;
    const static int PolPB023 = 312;
    const static int PolPB024 = 313;
    const static int PolPB025 = 314;
    const static int PolPB026 = 315;
    const static int PolPB027 = 316;
    const static int PolPB028 = 317;
    const static int PolPB029 = 318;
    const static int PolPB030 = 319;
    const static int PolPB031 = 320;
    const static int PolPB032 = 321;
    const static int PolPB033 = 322;
    const static int PolPB034 = 323;
    const static int PolPB035 = 324;
    const static int PolPB036 = 325;
    const static int PolPB037 = 326;
    const static int PolPB038 = 327;
    const static int PolPB039 = 328;
    const static int PolPB040 = 329;
    const static int PolPB041 = 330;
    const static int PolPB042 = 331;
    const static int PolPB043 = 332;
    const static int PolPB044 = 333;
    const static int PolPB045 = 334;
    const static int PolPB046 = 335;
    const static int PolPB047 = 336;
    const static int PolPB048 = 337;
    const static int PolPB049 = 338;
    const static int PolPB050 = 339;
    const static int PolPB051 = 340;
    const static int PolPB052 = 341;
    const static int PolPB053 = 342;
    const static int PolPB054 = 343;
    const static int PolPB055 = 344;
    const static int PolPB056 = 345;
    const static int PolPB057 = 346;
    const static int PolPB058 = 347;
    const static int PolPB059 = 348;
    const static int PolPB060 = 349;
    const static int PolPB061 = 350;
    const static int PolPB062 = 351;
    const static int PolPB063 = 352;
    const static int PolPB064 = 353;
    const static int PolPB065 = 354;
    const static int PolPB066 = 355;
    const static int PolPB067 = 356;
    const static int PolPB068 = 357;
    const static int PolPB069 = 358;
    const static int PolPB070 = 359;
    const static int PolPB071 = 360;
    const static int PolPB072 = 361;
    const static int PolPB073 = 362;
    const static int PolPB074 = 363;
    const static int PolPB075 = 364;
    const static int PolPB076 = 365;
    const static int PolPB077 = 366;
    const static int PolPB078 = 367;
    const static int PolPB079 = 368;
    const static int PolPB080 = 369;
    const static int PolPB081 = 370;
    const static int PolPB082 = 371;
    const static int PolPB083 = 372;
    const static int PolPB084 = 373;
    const static int PolPB085 = 374;
    const static int PolPB086 = 375;
    const static int PolPB087 = 376;
    const static int PolPB088 = 377;
    const static int PolPB089 = 378;
    const static int PolPB090 = 379;
    const static int PolPB091 = 380;
    const static int PolPB092 = 381;
    const static int PolPB093 = 382;
    const static int PolPB094 = 383;
    const static int PolPB095 = 384;
    const static int PolPB096 = 385;
    const static int PolPB097 = 386;
    const static int PolPB098 = 387;
    const static int PolPB099 = 388;
    const static int PolPB100 = 389;
    const static int PolPB101 = 390;
    const static int PolPB102 = 391;
    const static int PolPB103 = 392;
    const static int PolPB104 = 393;
    const static int PolPB105 = 394;
    const static int PolPB106 = 395;
    const static int PolPB107 = 396;
    const static int PolPB108 = 397;
    const static int PolPB109 = 398;
    const static int PolPB110 = 399;
    const static int PolPB111 = 400;
    const static int PolPB112 = 401;
    const static int PolPB113 = 402;
    const static int PolPB114 = 403;
    const static int PolPB115 = 404;
    const static int PolPB116 = 405;
    const static int PolPB117 = 406;
    const static int PolPB118 = 407;
    const static int PolPB119 = 408;
    const static int PolPB120 = 409;
    const static int PolPB121 = 410;
    const static int PolPB122 = 411;
    const static int PolPB123 = 412;
    const static int PolPB124 = 413;
    const static int PolPB125 = 414;
    const static int PolPB126 = 415;
    const static int PolPB127 = 416;
protected:
    
};