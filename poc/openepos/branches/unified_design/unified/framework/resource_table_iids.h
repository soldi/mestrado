
#ifndef __resource_table_iids_h
#define __resource_table_iids_h

namespace Implementation {

const unsigned char Resource_Table<Add,0>::IID[Traits<Add>::n_ids] = {0};
unsigned int Resource_Table_Array<Add>::id_count = 0;
const unsigned char Resource_Table_Array<Add>::IID[1][Traits<Add>::n_ids] = { {Resource_Table<Add,0>::IID[0]} };

const unsigned char Resource_Table<Mult,0>::IID[Traits<Mult>::n_ids] = {0,Resource_Table<Add,0>::IID[0]};
unsigned int Resource_Table_Array<Mult>::id_count = 0;
const unsigned char Resource_Table_Array<Mult>::IID[1][Traits<Mult>::n_ids] = { {Resource_Table<Mult,0>::IID[0],Resource_Table<Mult,0>::IID[1]}};


const unsigned char Resource_Table<Sched<void,void> ,0>::IID[Traits<Sched<void,void> >::n_ids] = {0};
unsigned int Resource_Table_Array<Sched<void,void> >::id_count = 0;
const unsigned char Resource_Table_Array<Sched<void,void> >::IID[1][Traits<Sched<void,void> >::n_ids] =
                                                                                { {Resource_Table<Sched<void,void>,0>::IID[0]}};


const unsigned char Resource_Table<DTMF_Detector,0>::IID[Traits<DTMF_Detector>::n_ids] = {0};
unsigned int Resource_Table_Array<DTMF_Detector>::id_count = 0;
const unsigned char Resource_Table_Array<DTMF_Detector>::IID[1][Traits<DTMF_Detector>::n_ids] =
                                                                               { {Resource_Table<DTMF_Detector,0>::IID[0]}};

const unsigned char Resource_Table<ADPCM_Codec,0>::IID[Traits<ADPCM_Codec>::n_ids] = {0};
unsigned int Resource_Table_Array<ADPCM_Codec>::id_count = 0;
const unsigned char Resource_Table_Array<ADPCM_Codec>::IID[1][Traits<ADPCM_Codec>::n_ids] =
                                                                               { {Resource_Table<ADPCM_Codec,0>::IID[0]}};

const unsigned char Resource_Table<Dummy_Callee,0>::IID[Traits<Dummy_Callee>::n_ids] = {0};
unsigned int Resource_Table_Array<Dummy_Callee>::id_count = 0;
const unsigned char Resource_Table_Array<Dummy_Callee>::IID[1][Traits<Dummy_Callee>::n_ids] =
                                                                               { {Resource_Table<Dummy_Callee,0>::IID[0]}};

const unsigned char Resource_Table<Dummy_Caller,0>::IID[Traits<Dummy_Caller>::n_ids] = {0,Resource_Table<Dummy_Callee,0>::IID[0]};
unsigned int Resource_Table_Array<Dummy_Caller>::id_count = 0;
const unsigned char Resource_Table_Array<Dummy_Caller>::IID[1][Traits<Dummy_Caller>::n_ids] = { {Resource_Table<Dummy_Caller,0>::IID[0],Resource_Table<Dummy_Caller,0>::IID[1]}};

///////////////////////////

const unsigned char Resource_Table<RSP_Controller,0>::IID[Traits<RSP_Controller>::n_ids] = {0};
unsigned int Resource_Table_Array<RSP_Controller>::id_count = 0;
const unsigned char Resource_Table_Array<RSP_Controller>::IID[1][Traits<RSP_Controller>::n_ids] = { {Resource_Table<RSP_Controller,0>::IID[0]}};


const unsigned char Resource_Table<RSP_DTMF,0>::IID[Traits<RSP_DTMF>::n_ids] = {0,Resource_Table<RSP_Controller,0>::IID[0]};
unsigned int Resource_Table_Array<RSP_DTMF>::id_count = 0;
const unsigned char Resource_Table_Array<RSP_DTMF>::IID[1][Traits<RSP_DTMF>::n_ids] = { {Resource_Table<RSP_DTMF,0>::IID[0],Resource_Table<RSP_DTMF,0>::IID[1]}};


const unsigned char Resource_Table<RSP_ADPCM,0>::IID[Traits<RSP_ADPCM>::n_ids] = {0,Resource_Table<RSP_DTMF,0>::IID[0],Resource_Table<RSP_DTMF,0>::IID[1]};
unsigned int Resource_Table_Array<RSP_ADPCM>::id_count = 0;
const unsigned char Resource_Table_Array<RSP_ADPCM>::IID[1][Traits<RSP_ADPCM>::n_ids] = { {Resource_Table<RSP_ADPCM,0>::IID[0],Resource_Table<RSP_ADPCM,0>::IID[1],Resource_Table<RSP_ADPCM,0>::IID[2]}};


const unsigned char Resource_Table<RSP_AES,0>::IID[Traits<RSP_AES>::n_ids] = {0,Resource_Table<RSP_ADPCM,0>::IID[0],Resource_Table<RSP_ADPCM,0>::IID[1],Resource_Table<RSP_ADPCM,0>::IID[2]};
unsigned int Resource_Table_Array<RSP_AES>::id_count = 0;
const unsigned char Resource_Table_Array<RSP_AES>::IID[1][Traits<RSP_AES>::n_ids] = { {Resource_Table<RSP_AES,0>::IID[0],Resource_Table<RSP_AES,0>::IID[1],Resource_Table<RSP_AES,0>::IID[2],Resource_Table<RSP_AES,0>::IID[3]}};

const unsigned char Resource_Table<RSP_ETH,0>::IID[Traits<RSP_ETH>::n_ids] = {0,Resource_Table<RSP_AES,0>::IID[0],Resource_Table<RSP_AES,0>::IID[1],Resource_Table<RSP_AES,0>::IID[2],Resource_Table<RSP_AES,0>::IID[3]};
unsigned int Resource_Table_Array<RSP_ETH>::id_count = 0;
const unsigned char Resource_Table_Array<RSP_ETH>::IID[1][Traits<RSP_ETH>::n_ids] = { {Resource_Table<RSP_ETH,0>::IID[0],Resource_Table<RSP_ETH,0>::IID[1],Resource_Table<RSP_ETH,0>::IID[2],Resource_Table<RSP_ETH,0>::IID[3],Resource_Table<RSP_ETH,0>::IID[4]}};

///////////////////////////

const unsigned int PHY_Table::X[12] = { Resource_Table<Add,0>::X,
                                       Resource_Table<Mult,0>::X,
                                       Resource_Table<Sched<void,void>,0>::X,
                                       Resource_Table<DTMF_Detector,0>::X,
                                       Resource_Table<ADPCM_Codec,0>::X,
                                       Resource_Table<Dummy_Callee,0>::X,
                                       Resource_Table<Dummy_Caller,0>::X,
                                       Resource_Table<RSP_Controller,0>::X,
                                       Resource_Table<RSP_DTMF,0>::X,
                                       Resource_Table<RSP_ADPCM,0>::X,
                                       Resource_Table<RSP_AES,0>::X,
                                       Resource_Table<RSP_ETH,0>::X};
const unsigned int PHY_Table::Y[12] = { Resource_Table<Add,0>::Y,
                                       Resource_Table<Mult,0>::Y,
                                       Resource_Table<Sched<void,void>,0>::Y,
                                       Resource_Table<DTMF_Detector,0>::Y,
                                       Resource_Table<ADPCM_Codec,0>::Y,
                                       Resource_Table<Dummy_Callee,0>::Y,
                                       Resource_Table<Dummy_Caller,0>::Y,
                                       Resource_Table<RSP_Controller,0>::Y,
                                       Resource_Table<RSP_DTMF,0>::Y,
                                       Resource_Table<RSP_ADPCM,0>::Y,
                                       Resource_Table<RSP_AES,0>::Y,
                                       Resource_Table<RSP_ETH,0>::Y};
const unsigned int PHY_Table::LOCAL[12] = { Resource_Table<Add,0>::LOCAL,
                                              Resource_Table<Mult,0>::LOCAL,
                                              Resource_Table<Sched<void,void>,0>::LOCAL,
                                              Resource_Table<DTMF_Detector,0>::LOCAL,
                                              Resource_Table<ADPCM_Codec,0>::LOCAL,
                                              Resource_Table<Dummy_Callee,0>::LOCAL,
                                              Resource_Table<Dummy_Caller,0>::LOCAL,
                                              Resource_Table<RSP_Controller,0>::LOCAL,
                                              Resource_Table<RSP_DTMF,0>::LOCAL,
                                              Resource_Table<RSP_ADPCM,0>::LOCAL,
                                              Resource_Table<RSP_AES,0>::LOCAL,
                                              Resource_Table<RSP_ETH,0>::LOCAL};

}

#endif