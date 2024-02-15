  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 45;
      section.data(45)  = dumData; %prealloc
      
	  ;% rtP.DCVoltageSource_Amplitude
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.DCVoltageSource1_Amplitude
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.DCMachine_Ifinit
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.CoulombTfViscousBmwFrictionTorques_gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.CoulombTfViscousBmwFrictionTorques_offset
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.RepeatingSequence_rep_seq_y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.StateSpace_P1_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.StateSpace_P1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtP.StateSpace_P2_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 19;
	
	  ;% rtP.StateSpace_P2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 21;
	
	  ;% rtP.StateSpace_P3_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 25;
	
	  ;% rtP.StateSpace_P3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 27;
	
	  ;% rtP.StateSpace_P4_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 28;
	
	  ;% rtP.StateSpace_P4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 30;
	
	  ;% rtP.Integrator_IC
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 145;
	
	  ;% rtP.StateSpace_P1_Size_j03jomzcbw
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 146;
	
	  ;% rtP.StateSpace_P1_e3cm2xon5j
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 148;
	
	  ;% rtP.StateSpace_P2_Size_ndoezivct2
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 172;
	
	  ;% rtP.StateSpace_P2_drr0oeq0oe
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 174;
	
	  ;% rtP.StateSpace_P3_Size_avrulq4hjb
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 178;
	
	  ;% rtP.StateSpace_P3_lk0jwa33xb
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 180;
	
	  ;% rtP.StateSpace_P4_Size_jcfjorwpgw
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 181;
	
	  ;% rtP.StateSpace_P4_mncjstijua
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 183;
	
	  ;% rtP.StateSpace_P5_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 359;
	
	  ;% rtP.StateSpace_P5
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 361;
	
	  ;% rtP.StateSpace_P6_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 363;
	
	  ;% rtP.StateSpace_P6
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 365;
	
	  ;% rtP.StateSpace_P7_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 366;
	
	  ;% rtP.StateSpace_P7
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 368;
	
	  ;% rtP.StateSpace_P8_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 369;
	
	  ;% rtP.StateSpace_P8
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 371;
	
	  ;% rtP.StateSpace_P9_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 372;
	
	  ;% rtP.StateSpace_P9
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 374;
	
	  ;% rtP.StateSpace_P10_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 375;
	
	  ;% rtP.StateSpace_P10
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 377;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 378;
	
	  ;% rtP.donotdeletethisgain_Gain_ijfdm1zi4o
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 379;
	
	  ;% rtP.LookUpTable1_bp01Data
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 380;
	
	  ;% rtP.DeadZone_Start
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 382;
	
	  ;% rtP.DeadZone_End
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 383;
	
	  ;% rtP.Gain2_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 384;
	
	  ;% rtP.Fieldarmaturemutualinductance_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 385;
	
	  ;% rtP.Gain1_Gain
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 386;
	
	  ;% rtP.Constant_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 387;
	
	  ;% rtP.Constant_Value_knnilg5f2q
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 388;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtB.axmmhiccox
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.dwpzvnyws1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.fua0oio1qa
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.noqxuuytub
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.nhfuapoovh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.ct0taxgvv3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.dalxhvg1zf
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtB.n5upg3xxwm
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtB.j1eypzh03i
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtB.h451ajn5pc
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtB.dav20jyvk3
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtB.g4p2xlgqdu
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% rtB.e3114yddje
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% rtB.m0juatoz4z
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% rtB.pjsgwedo55
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% rtB.ogaap0wcng
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
	  ;% rtB.noffyg4nar
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 17;
	
	  ;% rtB.iw2api0er3
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% rtB.dkw4zvirgz
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% rtB.ooxs3jjvtd
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 20;
	
	  ;% rtB.nyl0zlk1x2
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.gj1pm3tws0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.pl2nkwidb2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% rtDW.e0bjgobeax
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.i3xyhwkhup
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 22;
	
	  ;% rtDW.ktifmyvz3q.LoggedData
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 44;
	
	  ;% rtDW.ktn12s1iuj.LoggedData
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 45;
	
	  ;% rtDW.kpdwoqm44m.LoggedData
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 46;
	
	  ;% rtDW.pdi0yga5qo.LoggedData
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 47;
	
	  ;% rtDW.kx0nbvf0s5.LoggedData
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 48;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.opv2pzumsy
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jiw4bh1isx
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 23;
	
	  ;% rtDW.perqcxtxaf
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 46;
	
	  ;% rtDW.m0sqzkayaq
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 48;
	
	  ;% rtDW.ifodo1eta0
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3867164020;
  targMap.checksum1 = 1644783790;
  targMap.checksum2 = 2590097787;
  targMap.checksum3 = 1616282842;

