Model: "model_1"
__________________________________________________________________________________________________
 Layer (type)                   Output Shape         Param #     Connected to                     
==================================================================================================
 input_2 (InputLayer)           [(None, 64, 64, 3)]  0           []                               
                                                                                                  
 zero_padding2d_1 (ZeroPadding2  (None, 70, 70, 3)   0           ['input_2[0][0]']                
 D)                                                                                               
                                                                                                  
 conv2d_85 (Conv2D)             (None, 32, 32, 64)   9472        ['zero_padding2d_1[0][0]']       
                                                                                                  
 batch_normalization_85 (BatchN  (None, 32, 32, 64)  256         ['conv2d_85[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_76 (Activation)     (None, 32, 32, 64)   0           ['batch_normalization_85[0][0]'] 
                                                                                                  
 max_pooling2d_1 (MaxPooling2D)  (None, 15, 15, 64)  0           ['activation_76[0][0]']          
                                                                                                  
 conv2d_86 (Conv2D)             (None, 15, 15, 64)   4160        ['max_pooling2d_1[0][0]']        
                                                                                                  
 batch_normalization_86 (BatchN  (None, 15, 15, 64)  256         ['conv2d_86[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_77 (Activation)     (None, 15, 15, 64)   0           ['batch_normalization_86[0][0]'] 
                                                                                                  
 conv2d_87 (Conv2D)             (None, 15, 15, 64)   36928       ['activation_77[0][0]']          
                                                                                                  
 batch_normalization_87 (BatchN  (None, 15, 15, 64)  256         ['conv2d_87[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_78 (Activation)     (None, 15, 15, 64)   0           ['batch_normalization_87[0][0]'] 
                                                                                                  
 conv2d_88 (Conv2D)             (None, 15, 15, 256)  16640       ['activation_78[0][0]']          
                                                                                                  
 conv2d_89 (Conv2D)             (None, 15, 15, 256)  16640       ['max_pooling2d_1[0][0]']        
                                                                                                  
 batch_normalization_88 (BatchN  (None, 15, 15, 256)  1024       ['conv2d_88[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 batch_normalization_89 (BatchN  (None, 15, 15, 256)  1024       ['conv2d_89[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 add_25 (Add)                   (None, 15, 15, 256)  0           ['batch_normalization_88[0][0]', 
                                                                  'batch_normalization_89[0][0]'] 
                                                                                                  
 activation_79 (Activation)     (None, 15, 15, 256)  0           ['add_25[0][0]']                 
                                                                                                  
 conv2d_90 (Conv2D)             (None, 15, 15, 64)   16448       ['activation_79[0][0]']          
                                                                                                  
 batch_normalization_90 (BatchN  (None, 15, 15, 64)  256         ['conv2d_90[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_80 (Activation)     (None, 15, 15, 64)   0           ['batch_normalization_90[0][0]'] 
                                                                                                  
 conv2d_91 (Conv2D)             (None, 15, 15, 64)   36928       ['activation_80[0][0]']          
                                                                                                  
 batch_normalization_91 (BatchN  (None, 15, 15, 64)  256         ['conv2d_91[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_81 (Activation)     (None, 15, 15, 64)   0           ['batch_normalization_91[0][0]'] 
                                                                                                  
 conv2d_92 (Conv2D)             (None, 15, 15, 256)  16640       ['activation_81[0][0]']          
                                                                                                  
 batch_normalization_92 (BatchN  (None, 15, 15, 256)  1024       ['conv2d_92[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 add_26 (Add)                   (None, 15, 15, 256)  0           ['batch_normalization_92[0][0]', 
                                                                  'activation_79[0][0]']          
                                                                                                  
 activation_82 (Activation)     (None, 15, 15, 256)  0           ['add_26[0][0]']                 
                                                                                                  
 conv2d_93 (Conv2D)             (None, 15, 15, 64)   16448       ['activation_82[0][0]']          
                                                                                                  
 batch_normalization_93 (BatchN  (None, 15, 15, 64)  256         ['conv2d_93[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_83 (Activation)     (None, 15, 15, 64)   0           ['batch_normalization_93[0][0]'] 
                                                                                                  
 conv2d_94 (Conv2D)             (None, 15, 15, 64)   36928       ['activation_83[0][0]']          
                                                                                                  
 batch_normalization_94 (BatchN  (None, 15, 15, 64)  256         ['conv2d_94[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_84 (Activation)     (None, 15, 15, 64)   0           ['batch_normalization_94[0][0]'] 
                                                                                                  
 conv2d_95 (Conv2D)             (None, 15, 15, 256)  16640       ['activation_84[0][0]']          
                                                                                                  
 batch_normalization_95 (BatchN  (None, 15, 15, 256)  1024       ['conv2d_95[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 add_27 (Add)                   (None, 15, 15, 256)  0           ['batch_normalization_95[0][0]', 
                                                                  'activation_82[0][0]']          
                                                                                                  
 activation_85 (Activation)     (None, 15, 15, 256)  0           ['add_27[0][0]']                 
                                                                                                  
 conv2d_96 (Conv2D)             (None, 8, 8, 128)    32896       ['activation_85[0][0]']          
                                                                                                  
 batch_normalization_96 (BatchN  (None, 8, 8, 128)   512         ['conv2d_96[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_86 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_96[0][0]'] 
                                                                                                  
 conv2d_97 (Conv2D)             (None, 8, 8, 128)    147584      ['activation_86[0][0]']          
                                                                                                  
 batch_normalization_97 (BatchN  (None, 8, 8, 128)   512         ['conv2d_97[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 activation_87 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_97[0][0]'] 
                                                                                                  
 conv2d_98 (Conv2D)             (None, 8, 8, 512)    66048       ['activation_87[0][0]']          
                                                                                                  
 conv2d_99 (Conv2D)             (None, 8, 8, 512)    131584      ['activation_85[0][0]']          
                                                                                                  
 batch_normalization_98 (BatchN  (None, 8, 8, 512)   2048        ['conv2d_98[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 batch_normalization_99 (BatchN  (None, 8, 8, 512)   2048        ['conv2d_99[0][0]']              
 ormalization)                                                                                    
                                                                                                  
 add_28 (Add)                   (None, 8, 8, 512)    0           ['batch_normalization_98[0][0]', 
                                                                  'batch_normalization_99[0][0]'] 
                                                                                                  
 activation_88 (Activation)     (None, 8, 8, 512)    0           ['add_28[0][0]']                 
                                                                                                  
 conv2d_100 (Conv2D)            (None, 8, 8, 128)    65664       ['activation_88[0][0]']          
                                                                                                  
 batch_normalization_100 (Batch  (None, 8, 8, 128)   512         ['conv2d_100[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_89 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_100[0][0]']
                                                                                                  
 conv2d_101 (Conv2D)            (None, 8, 8, 128)    147584      ['activation_89[0][0]']          
                                                                                                  
 batch_normalization_101 (Batch  (None, 8, 8, 128)   512         ['conv2d_101[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_90 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_101[0][0]']
                                                                                                  
 conv2d_102 (Conv2D)            (None, 8, 8, 512)    66048       ['activation_90[0][0]']          
                                                                                                  
 batch_normalization_102 (Batch  (None, 8, 8, 512)   2048        ['conv2d_102[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_29 (Add)                   (None, 8, 8, 512)    0           ['batch_normalization_102[0][0]',
                                                                  'activation_88[0][0]']          
                                                                                                  
 activation_91 (Activation)     (None, 8, 8, 512)    0           ['add_29[0][0]']                 
                                                                                                  
 conv2d_103 (Conv2D)            (None, 8, 8, 128)    65664       ['activation_91[0][0]']          
                                                                                                  
 batch_normalization_103 (Batch  (None, 8, 8, 128)   512         ['conv2d_103[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_92 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_103[0][0]']
                                                                                                  
 conv2d_104 (Conv2D)            (None, 8, 8, 128)    147584      ['activation_92[0][0]']          
                                                                                                  
 batch_normalization_104 (Batch  (None, 8, 8, 128)   512         ['conv2d_104[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_93 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_104[0][0]']
                                                                                                  
 conv2d_105 (Conv2D)            (None, 8, 8, 512)    66048       ['activation_93[0][0]']          
                                                                                                  
 batch_normalization_105 (Batch  (None, 8, 8, 512)   2048        ['conv2d_105[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_30 (Add)                   (None, 8, 8, 512)    0           ['batch_normalization_105[0][0]',
                                                                  'activation_91[0][0]']          
                                                                                                  
 activation_94 (Activation)     (None, 8, 8, 512)    0           ['add_30[0][0]']                 
                                                                                                  
 conv2d_106 (Conv2D)            (None, 8, 8, 128)    65664       ['activation_94[0][0]']          
                                                                                                  
 batch_normalization_106 (Batch  (None, 8, 8, 128)   512         ['conv2d_106[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_95 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_106[0][0]']
                                                                                                  
 conv2d_107 (Conv2D)            (None, 8, 8, 128)    147584      ['activation_95[0][0]']          
                                                                                                  
 batch_normalization_107 (Batch  (None, 8, 8, 128)   512         ['conv2d_107[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_96 (Activation)     (None, 8, 8, 128)    0           ['batch_normalization_107[0][0]']
                                                                                                  
 conv2d_108 (Conv2D)            (None, 8, 8, 512)    66048       ['activation_96[0][0]']          
                                                                                                  
 batch_normalization_108 (Batch  (None, 8, 8, 512)   2048        ['conv2d_108[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_31 (Add)                   (None, 8, 8, 512)    0           ['batch_normalization_108[0][0]',
                                                                  'activation_94[0][0]']          
                                                                                                  
 activation_97 (Activation)     (None, 8, 8, 512)    0           ['add_31[0][0]']                 
                                                                                                  
 conv2d_109 (Conv2D)            (None, 4, 4, 256)    131328      ['activation_97[0][0]']          
                                                                                                  
 batch_normalization_109 (Batch  (None, 4, 4, 256)   1024        ['conv2d_109[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_98 (Activation)     (None, 4, 4, 256)    0           ['batch_normalization_109[0][0]']
                                                                                                  
 conv2d_110 (Conv2D)            (None, 4, 4, 256)    590080      ['activation_98[0][0]']          
                                                                                                  
 batch_normalization_110 (Batch  (None, 4, 4, 256)   1024        ['conv2d_110[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_99 (Activation)     (None, 4, 4, 256)    0           ['batch_normalization_110[0][0]']
                                                                                                  
 conv2d_111 (Conv2D)            (None, 4, 4, 1024)   263168      ['activation_99[0][0]']          
                                                                                                  
 conv2d_112 (Conv2D)            (None, 4, 4, 1024)   525312      ['activation_97[0][0]']          
                                                                                                  
 batch_normalization_111 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_111[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 batch_normalization_112 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_112[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_32 (Add)                   (None, 4, 4, 1024)   0           ['batch_normalization_111[0][0]',
                                                                  'batch_normalization_112[0][0]']
                                                                                                  
 activation_100 (Activation)    (None, 4, 4, 1024)   0           ['add_32[0][0]']                 
                                                                                                  
 conv2d_113 (Conv2D)            (None, 4, 4, 256)    262400      ['activation_100[0][0]']         
                                                                                                  
 batch_normalization_113 (Batch  (None, 4, 4, 256)   1024        ['conv2d_113[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_101 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_113[0][0]']
                                                                                                  
 conv2d_114 (Conv2D)            (None, 4, 4, 256)    590080      ['activation_101[0][0]']         
                                                                                                  
 batch_normalization_114 (Batch  (None, 4, 4, 256)   1024        ['conv2d_114[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_102 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_114[0][0]']
                                                                                                  
 conv2d_115 (Conv2D)            (None, 4, 4, 1024)   263168      ['activation_102[0][0]']         
                                                                                                  
 batch_normalization_115 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_115[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_33 (Add)                   (None, 4, 4, 1024)   0           ['batch_normalization_115[0][0]',
                                                                  'activation_100[0][0]']         
                                                                                                  
 activation_103 (Activation)    (None, 4, 4, 1024)   0           ['add_33[0][0]']                 
                                                                                                  
 conv2d_116 (Conv2D)            (None, 4, 4, 256)    262400      ['activation_103[0][0]']         
                                                                                                  
 batch_normalization_116 (Batch  (None, 4, 4, 256)   1024        ['conv2d_116[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_104 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_116[0][0]']
                                                                                                  
 conv2d_117 (Conv2D)            (None, 4, 4, 256)    590080      ['activation_104[0][0]']         
                                                                                                  
 batch_normalization_117 (Batch  (None, 4, 4, 256)   1024        ['conv2d_117[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_105 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_117[0][0]']
                                                                                                  
 conv2d_118 (Conv2D)            (None, 4, 4, 1024)   263168      ['activation_105[0][0]']         
                                                                                                  
 batch_normalization_118 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_118[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_34 (Add)                   (None, 4, 4, 1024)   0           ['batch_normalization_118[0][0]',
                                                                  'activation_103[0][0]']         
                                                                                                  
 activation_106 (Activation)    (None, 4, 4, 1024)   0           ['add_34[0][0]']                 
                                                                                                  
 conv2d_119 (Conv2D)            (None, 4, 4, 256)    262400      ['activation_106[0][0]']         
                                                                                                  
 batch_normalization_119 (Batch  (None, 4, 4, 256)   1024        ['conv2d_119[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_107 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_119[0][0]']
                                                                                                  
 conv2d_120 (Conv2D)            (None, 4, 4, 256)    590080      ['activation_107[0][0]']         
                                                                                                  
 batch_normalization_120 (Batch  (None, 4, 4, 256)   1024        ['conv2d_120[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_108 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_120[0][0]']
                                                                                                  
 conv2d_121 (Conv2D)            (None, 4, 4, 1024)   263168      ['activation_108[0][0]']         
                                                                                                  
 batch_normalization_121 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_121[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_35 (Add)                   (None, 4, 4, 1024)   0           ['batch_normalization_121[0][0]',
                                                                  'activation_106[0][0]']         
                                                                                                  
 activation_109 (Activation)    (None, 4, 4, 1024)   0           ['add_35[0][0]']                 
                                                                                                  
 conv2d_122 (Conv2D)            (None, 4, 4, 256)    262400      ['activation_109[0][0]']         
                                                                                                  
 batch_normalization_122 (Batch  (None, 4, 4, 256)   1024        ['conv2d_122[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_110 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_122[0][0]']
                                                                                                  
 conv2d_123 (Conv2D)            (None, 4, 4, 256)    590080      ['activation_110[0][0]']         
                                                                                                  
 batch_normalization_123 (Batch  (None, 4, 4, 256)   1024        ['conv2d_123[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_111 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_123[0][0]']
                                                                                                  
 conv2d_124 (Conv2D)            (None, 4, 4, 1024)   263168      ['activation_111[0][0]']         
                                                                                                  
 batch_normalization_124 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_124[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_36 (Add)                   (None, 4, 4, 1024)   0           ['batch_normalization_124[0][0]',
                                                                  'activation_109[0][0]']         
                                                                                                  
 activation_112 (Activation)    (None, 4, 4, 1024)   0           ['add_36[0][0]']                 
                                                                                                  
 conv2d_125 (Conv2D)            (None, 4, 4, 256)    262400      ['activation_112[0][0]']         
                                                                                                  
 batch_normalization_125 (Batch  (None, 4, 4, 256)   1024        ['conv2d_125[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_113 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_125[0][0]']
                                                                                                  
 conv2d_126 (Conv2D)            (None, 4, 4, 256)    590080      ['activation_113[0][0]']         
                                                                                                  
 batch_normalization_126 (Batch  (None, 4, 4, 256)   1024        ['conv2d_126[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_114 (Activation)    (None, 4, 4, 256)    0           ['batch_normalization_126[0][0]']
                                                                                                  
 conv2d_127 (Conv2D)            (None, 4, 4, 1024)   263168      ['activation_114[0][0]']         
                                                                                                  
 batch_normalization_127 (Batch  (None, 4, 4, 1024)  4096        ['conv2d_127[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_37 (Add)                   (None, 4, 4, 1024)   0           ['batch_normalization_127[0][0]',
                                                                  'activation_112[0][0]']         
                                                                                                  
 activation_115 (Activation)    (None, 4, 4, 1024)   0           ['add_37[0][0]']                 
                                                                                                  
 conv2d_128 (Conv2D)            (None, 2, 2, 512)    524800      ['activation_115[0][0]']         
                                                                                                  
 batch_normalization_128 (Batch  (None, 2, 2, 512)   2048        ['conv2d_128[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_116 (Activation)    (None, 2, 2, 512)    0           ['batch_normalization_128[0][0]']
                                                                                                  
 conv2d_129 (Conv2D)            (None, 2, 2, 512)    2359808     ['activation_116[0][0]']         
                                                                                                  
 batch_normalization_129 (Batch  (None, 2, 2, 512)   2048        ['conv2d_129[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_117 (Activation)    (None, 2, 2, 512)    0           ['batch_normalization_129[0][0]']
                                                                                                  
 conv2d_130 (Conv2D)            (None, 2, 2, 2048)   1050624     ['activation_117[0][0]']         
                                                                                                  
 conv2d_131 (Conv2D)            (None, 2, 2, 2048)   2099200     ['activation_115[0][0]']         
                                                                                                  
 batch_normalization_130 (Batch  (None, 2, 2, 2048)  8192        ['conv2d_130[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 batch_normalization_131 (Batch  (None, 2, 2, 2048)  8192        ['conv2d_131[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_38 (Add)                   (None, 2, 2, 2048)   0           ['batch_normalization_130[0][0]',
                                                                  'batch_normalization_131[0][0]']
                                                                                                  
 activation_118 (Activation)    (None, 2, 2, 2048)   0           ['add_38[0][0]']                 
                                                                                                  
 conv2d_132 (Conv2D)            (None, 2, 2, 512)    1049088     ['activation_118[0][0]']         
                                                                                                  
 batch_normalization_132 (Batch  (None, 2, 2, 512)   2048        ['conv2d_132[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_119 (Activation)    (None, 2, 2, 512)    0           ['batch_normalization_132[0][0]']
                                                                                                  
 conv2d_133 (Conv2D)            (None, 2, 2, 512)    2359808     ['activation_119[0][0]']         
                                                                                                  
 batch_normalization_133 (Batch  (None, 2, 2, 512)   2048        ['conv2d_133[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_120 (Activation)    (None, 2, 2, 512)    0           ['batch_normalization_133[0][0]']
                                                                                                  
 conv2d_134 (Conv2D)            (None, 2, 2, 2048)   1050624     ['activation_120[0][0]']         
                                                                                                  
 batch_normalization_134 (Batch  (None, 2, 2, 2048)  8192        ['conv2d_134[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_39 (Add)                   (None, 2, 2, 2048)   0           ['batch_normalization_134[0][0]',
                                                                  'activation_118[0][0]']         
                                                                                                  
 activation_121 (Activation)    (None, 2, 2, 2048)   0           ['add_39[0][0]']                 
                                                                                                  
 conv2d_135 (Conv2D)            (None, 2, 2, 512)    1049088     ['activation_121[0][0]']         
                                                                                                  
 batch_normalization_135 (Batch  (None, 2, 2, 512)   2048        ['conv2d_135[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_122 (Activation)    (None, 2, 2, 512)    0           ['batch_normalization_135[0][0]']
                                                                                                  
 conv2d_136 (Conv2D)            (None, 2, 2, 512)    2359808     ['activation_122[0][0]']         
                                                                                                  
 batch_normalization_136 (Batch  (None, 2, 2, 512)   2048        ['conv2d_136[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 activation_123 (Activation)    (None, 2, 2, 512)    0           ['batch_normalization_136[0][0]']
                                                                                                  
 conv2d_137 (Conv2D)            (None, 2, 2, 2048)   1050624     ['activation_123[0][0]']         
                                                                                                  
 batch_normalization_137 (Batch  (None, 2, 2, 2048)  8192        ['conv2d_137[0][0]']             
 Normalization)                                                                                   
                                                                                                  
 add_40 (Add)                   (None, 2, 2, 2048)   0           ['batch_normalization_137[0][0]',
                                                                  'activation_121[0][0]']         
                                                                                                  
 activation_124 (Activation)    (None, 2, 2, 2048)   0           ['add_40[0][0]']                 
                                                                                                  
 average_pooling2d_1 (AveragePo  (None, 1, 1, 2048)  0           ['activation_124[0][0]']         
 oling2D)                                                                                         
                                                                                                  
 flatten_1 (Flatten)            (None, 2048)         0           ['average_pooling2d_1[0][0]']    
                                                                                                  
 dense_1 (Dense)                (None, 6)            12294       ['flatten_1[0][0]']              
                                                                                                  
==================================================================================================
Total params: 23,600,006
Trainable params: 23,546,886
Non-trainable params: 53,120
__________________________________________________________________________________________________