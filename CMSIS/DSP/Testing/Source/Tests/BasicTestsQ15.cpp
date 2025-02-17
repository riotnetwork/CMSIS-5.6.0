#include "BasicTestsQ15.h"
#include "Error.h"

#define SNR_THRESHOLD 70

#define MULT_SNR_THRESHOLD 60

#define ONEHALF 0x4000

#define GET_Q15_PTR() \
const q15_t *inp1=input1.ptr(); \
const q15_t *inp2=input2.ptr(); \
q15_t *refp=ref.ptr(); \
q15_t *outp=output.ptr();

    void BasicTestsQ15::test_add_q15()
    {
        GET_Q15_PTR();

        arm_add_q15(inp1,inp2,outp,input1.nbSamples());
        

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);

    } 

    void BasicTestsQ15::test_sub_q15()
    {
        GET_Q15_PTR();

        arm_sub_q15(inp1,inp2,outp,input1.nbSamples());
        
        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);
       
    } 

    void BasicTestsQ15::test_mult_q15()
    {
        GET_Q15_PTR();

        arm_mult_q15(inp1,inp2,outp,input1.nbSamples());

        ASSERT_SNR(output,ref,(float32_t)MULT_SNR_THRESHOLD);
       
    } 

   

    void BasicTestsQ15::test_negate_q15()
    {
        const q15_t *inp1=input1.ptr();
        q15_t *refp=ref.ptr();
        q15_t *outp=output.ptr();

        arm_negate_q15(inp1,outp,input1.nbSamples());

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);
       
    } 

    void BasicTestsQ15::test_offset_q15()
    {
        const q15_t *inp1=input1.ptr();
        q15_t *refp=ref.ptr();
        q15_t *outp=output.ptr();

        arm_offset_q15(inp1,this->scalar,outp,input1.nbSamples());

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);
       
    } 

    void BasicTestsQ15::test_scale_q15()
    {
        const q15_t *inp1=input1.ptr();
        q15_t *refp=ref.ptr();
        q15_t *outp=output.ptr();

        arm_scale_q15(inp1,this->scalar,0,outp,input1.nbSamples());

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);
       
    } 

    void BasicTestsQ15::test_dot_prod_q15()
    {
        q63_t r;

        const q15_t *inp1=input1.ptr();
        const q15_t *inp2=input2.ptr();
        q63_t *refp=dotRef.ptr(); 
        q63_t *outp=dotOutput.ptr();

        arm_dot_prod_q15(inp1,inp2,input1.nbSamples(),&r);

        outp[0] = r;

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);

       
    } 

    void BasicTestsQ15::test_abs_q15()
    {
        GET_Q15_PTR();

        arm_abs_q15(inp1,outp,input1.nbSamples());

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);
       
    } 

    void BasicTestsQ15::test_shift_q15()
    {
        const q15_t *inp1=input1.ptr();
        q15_t *refp=ref.ptr();
        q15_t *outp=output.ptr();

        arm_shift_q15(inp1,1,outp,input1.nbSamples());

        ASSERT_SNR(output,ref,(float32_t)SNR_THRESHOLD);
       
    } 


    void BasicTestsQ15::setUp(Testing::testID_t id,std::vector<Testing::param_t>& params,Client::PatternMgr *mgr)
    {
      
       Testing::nbSamples_t nb=MAX_NB_SAMPLES; 

       this->scalar = ONEHALF;

       
       switch(id)
       {
        case BasicTestsQ15::TEST_ADD_Q15_1:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_ADD_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_ADD_Q15_2:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_ADD_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_ADD_Q15_3:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_ADD_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;


        case BasicTestsQ15::TEST_SUB_Q15_4:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_SUB_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_SUB_Q15_5:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_SUB_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_SUB_Q15_6:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_SUB_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_MULT_Q15_7:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_MULT_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_MULT_Q15_8:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_MULT_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_MULT_Q15_9:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_MULT_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_NEGATE_Q15_10:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_NEGATE_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_NEGATE_Q15_11:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_NEGATE_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_NEGATE_Q15_12:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_NEGATE_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_OFFSET_Q15_13:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_OFFSET_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_OFFSET_Q15_14:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_OFFSET_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_OFFSET_Q15_15:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_OFFSET_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_SCALE_Q15_16:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_SCALE_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_SCALE_Q15_17:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_SCALE_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_SCALE_Q15_18:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_SCALE_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_DOT_PROD_Q15_19:
          nb = 3;
          dotRef.reload(BasicTestsQ15::REF_DOT_3_Q15_ID,mgr);
          dotOutput.create(dotRef.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_DOT_PROD_Q15_20:
          nb = 8;
          dotRef.reload(BasicTestsQ15::REF_DOT_4N_Q15_ID,mgr);
          dotOutput.create(dotRef.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_DOT_PROD_Q15_21:
          nb = 9;
          dotRef.reload(BasicTestsQ15::REF_DOT_4N1_Q15_ID,mgr);
          dotOutput.create(dotRef.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_ABS_Q15_22:
          nb = 3;
          ref.reload(BasicTestsQ15::REF_ABS_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_ABS_Q15_23:
          nb = 8;
          ref.reload(BasicTestsQ15::REF_ABS_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;
        case BasicTestsQ15::TEST_ABS_Q15_24:
          nb = 9;
          ref.reload(BasicTestsQ15::REF_ABS_Q15_ID,mgr,nb);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUT1_Q15_ID,mgr,nb);
          input2.reload(BasicTestsQ15::INPUT2_Q15_ID,mgr,nb);
          break;

        case BasicTestsQ15::TEST_ADD_Q15_25:
          input1.reload(BasicTestsQ15::MAXPOS_Q15_ID,mgr);
          input2.reload(BasicTestsQ15::MAXPOS_Q15_ID,mgr);
          ref.reload(BasicTestsQ15::REF_POSSAT_12_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_ADD_Q15_26:
          input1.reload(BasicTestsQ15::MAXNEG_Q15_ID,mgr);
          input2.reload(BasicTestsQ15::MAXNEG_Q15_ID,mgr);
          ref.reload(BasicTestsQ15::REF_NEGSAT_13_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_SUB_Q15_27:
          ref.reload(BasicTestsQ15::REF_POSSAT_14_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXPOS_Q15_ID,mgr);
          input2.reload(BasicTestsQ15::MAXNEG_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_SUB_Q15_28:
          ref.reload(BasicTestsQ15::REF_NEGSAT_15_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXNEG_Q15_ID,mgr);
          input2.reload(BasicTestsQ15::MAXPOS_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_MULT_Q15_29:
          ref.reload(BasicTestsQ15::REF_POSSAT_16_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXNEG2_Q15_ID,mgr);
          input2.reload(BasicTestsQ15::MAXNEG2_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_NEGATE_Q15_30:
          ref.reload(BasicTestsQ15::REF_POSSAT_17_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXNEG2_Q15_ID,mgr);
          break;

        case BasicTestsQ15::TEST_OFFSET_Q15_31:
          ref.reload(BasicTestsQ15::REF_POSSAT_18_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXPOS_Q15_ID,mgr);
          /* 0.9 */
          this->scalar = 0x7333;
          break;

        case BasicTestsQ15::TEST_OFFSET_Q15_32:
          ref.reload(BasicTestsQ15::REF_NEGSAT_19_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXNEG_Q15_ID,mgr);
          /* -0.9 */
          this->scalar = 0x8ccd;
          break;

        case BasicTestsQ15::TEST_SCALE_Q15_33:
          ref.reload(BasicTestsQ15::REF_POSSAT_20_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXNEG2_Q15_ID,mgr);
          /* Minus max*/
          this->scalar = 0x8000;
          break;

        case BasicTestsQ15::TEST_SHIFT_Q15_34:
          ref.reload(BasicTestsQ15::REF_SHIFT_21_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::INPUTRAND_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_SHIFT_Q15_35:
          ref.reload(BasicTestsQ15::REF_SHIFT_POSSAT_22_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXPOS_Q15_ID,mgr);
        break;

        case BasicTestsQ15::TEST_SHIFT_Q15_36:
          ref.reload(BasicTestsQ15::REF_SHIFT_NEGSAT_23_Q15_ID,mgr);
          output.create(ref.nbSamples(),BasicTestsQ15::OUT_SAMPLES_Q15_ID,mgr);
          input1.reload(BasicTestsQ15::MAXNEG_Q15_ID,mgr);
        break;

       }
      

       

    }

    void BasicTestsQ15::tearDown(Testing::testID_t id,Client::PatternMgr *mgr)
    {
       switch(id)
       {
         case BasicTestsQ15::TEST_DOT_PROD_Q15_19:
         case BasicTestsQ15::TEST_DOT_PROD_Q15_20:
         case BasicTestsQ15::TEST_DOT_PROD_Q15_21:
            dotOutput.dump(mgr);
         break;

         default:
            output.dump(mgr);
       }

        
    }
