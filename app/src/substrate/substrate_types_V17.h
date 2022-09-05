/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    pd_Compactu32_t nom;
    pd_Compactu32_t denom;
} pd_Fraction_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V17_t fraction;
    };
} pd_BodyPart_V17_t;

typedef struct {
    uint8_t value;
    pd_Bytes_t named;
} pd_NetworkId_V17_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V17_t;

typedef struct {
    pd_NetworkId_V17_t networkId;
    pd_u8_array_32_V17_t key;
} pd_AccountId32_V17_t;

typedef struct {
    pd_NetworkId_V17_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V17_t;

typedef struct {
    pd_NetworkId_V17_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V17_t;

typedef struct {
    pd_BodyId_V17_t id;
    pd_BodyPart_V17_t part;
} pd_Plurality_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V17_t accountId32;
        pd_AccountIndex64_V17_t accountIndex64;
        pd_AccountKey20_V17_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V17_t plurality;
    };
} pd_JunctionV0_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V17_t accountId32;
        pd_AccountIndex64_V17_t accountIndex64;
        pd_AccountKey20_V17_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V17_t plurality;
    };
} pd_JunctionV1_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction;
} pd_JunctionV0X1_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
} pd_JunctionV0X2_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
    pd_JunctionV0_V17_t junction2;
} pd_JunctionV0X3_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
    pd_JunctionV0_V17_t junction2;
    pd_JunctionV0_V17_t junction3;
} pd_JunctionV0X4_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
    pd_JunctionV0_V17_t junction2;
    pd_JunctionV0_V17_t junction3;
    pd_JunctionV0_V17_t junction4;
} pd_JunctionV0X5_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
    pd_JunctionV0_V17_t junction2;
    pd_JunctionV0_V17_t junction3;
    pd_JunctionV0_V17_t junction4;
    pd_JunctionV0_V17_t junction5;
} pd_JunctionV0X6_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
    pd_JunctionV0_V17_t junction2;
    pd_JunctionV0_V17_t junction3;
    pd_JunctionV0_V17_t junction4;
    pd_JunctionV0_V17_t junction5;
    pd_JunctionV0_V17_t junction6;
} pd_JunctionV0X7_V17_t;

typedef struct {
    pd_JunctionV0_V17_t junction0;
    pd_JunctionV0_V17_t junction1;
    pd_JunctionV0_V17_t junction2;
    pd_JunctionV0_V17_t junction3;
    pd_JunctionV0_V17_t junction4;
    pd_JunctionV0_V17_t junction5;
    pd_JunctionV0_V17_t junction6;
    pd_JunctionV0_V17_t junction7;
} pd_JunctionV0X8_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction;
} pd_JunctionV1X1_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
} pd_JunctionV1X2_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
    pd_JunctionV1_V17_t junction2;
} pd_JunctionV1X3_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
    pd_JunctionV1_V17_t junction2;
    pd_JunctionV1_V17_t junction3;
} pd_JunctionV1X4_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
    pd_JunctionV1_V17_t junction2;
    pd_JunctionV1_V17_t junction3;
    pd_JunctionV1_V17_t junction4;
} pd_JunctionV1X5_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
    pd_JunctionV1_V17_t junction2;
    pd_JunctionV1_V17_t junction3;
    pd_JunctionV1_V17_t junction4;
    pd_JunctionV1_V17_t junction5;
} pd_JunctionV1X6_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
    pd_JunctionV1_V17_t junction2;
    pd_JunctionV1_V17_t junction3;
    pd_JunctionV1_V17_t junction4;
    pd_JunctionV1_V17_t junction5;
    pd_JunctionV1_V17_t junction6;
} pd_JunctionV1X7_V17_t;

typedef struct {
    pd_JunctionV1_V17_t junction0;
    pd_JunctionV1_V17_t junction1;
    pd_JunctionV1_V17_t junction2;
    pd_JunctionV1_V17_t junction3;
    pd_JunctionV1_V17_t junction4;
    pd_JunctionV1_V17_t junction5;
    pd_JunctionV1_V17_t junction6;
    pd_JunctionV1_V17_t junction7;
} pd_JunctionV1X8_V17_t;

typedef struct {
    pd_u128_t value;
} pd_Rate_V17_t;

typedef struct {
    uint32_t value;
} pd_Ratio_V17_t;

typedef struct {
    pd_Rate_V17_t baseRate;
} pd_CurveModel_V17_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V17_t;

typedef struct {
    pd_Rate_V17_t baseRate;
    pd_Rate_V17_t jumpRate;
    pd_Rate_V17_t fullRate;
    pd_Ratio_V17_t jumpUtilization;
} pd_JumpModel_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV0X1_V17_t x1;
        pd_JunctionV0X2_V17_t x2;
        pd_JunctionV0X3_V17_t x3;
#ifdef JUNCTIONS_FULL
        pd_JunctionV0X4_V17_t x4;
        pd_JunctionV0X5_V17_t x5;
        pd_JunctionV0X6_V17_t x6;
        pd_JunctionV0X7_V17_t x7;
        pd_JunctionV0X8_V17_t x8;
#endif
    };
} pd_JunctionsV0_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV1X1_V17_t x1;
        pd_JunctionV1X2_V17_t x2;
        pd_JunctionV1X3_V17_t x3;
#ifdef JUNCTIONS_FULL
        pd_JunctionV1X4_V17_t x4;
        pd_JunctionV1X5_V17_t x5;
        pd_JunctionV1X6_V17_t x6;
        pd_JunctionV1X7_V17_t x7;
        pd_JunctionV1X8_V17_t x8;
#endif
    };
} pd_JunctionsV1_V17_t;

typedef struct {
    pd_Compactu128_t value;
    pd_Compactu32_t era;
} pd_UnlockChunk_V17_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V17_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOf_V17_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V17_t;

typedef struct {
    uint8_t value;
} pd_ContributionStrategy_V17_t;

typedef struct {
    uint32_t value;
} pd_CurrencyId_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_JumpModel_V17_t jump;
        pd_CurveModel_V17_t curve;
    };
} pd_InterestRateModel_V17_t;

typedef struct {
    uint8_t value;
} pd_MarketState_V17_t;

typedef struct {
    pd_JunctionsV0_V17_t junctions;
} pd_MultiLocationV0_V17_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV1_V17_t interior;
} pd_MultiLocationV1_V17_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V17_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V17_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecEraIndex_V17_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecUnlockChunk_V17_t;

typedef struct {
    pd_BlockNumber_t start;
    pd_BlockNumber_t period;
    uint32_t periodCount;
    pd_Compactu128_t perPeriod;
} pd_VestingScheduleOf_V17_t;

typedef struct {
    pd_AssetIdOf_V17_t assetid1;
    pd_AssetIdOf_V17_t assetid2;
} pd_AssetIdOfAssetIdOf_V17_t;

typedef struct {
    pd_u128_t balance1;
    pd_u128_t balance2;
} pd_BalanceOfBalanceOf_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V17_t multilocationV0;
        pd_MultiLocationV1_V17_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V17_t;

typedef struct {
    pd_CurrencyId_V17_t id;
    pd_bool_t external;
    pd_Balance_t fee;
    pd_bool_t enable;
    pd_Balance_t outCap;
    pd_Balance_t outAmount;
    pd_Balance_t inCap;
    pd_Balance_t inAmount;
} pd_BridgeToken_V17_t;

typedef struct {
    pd_Compactu32_t accounts;
    pd_Compactu32_t sufficients;
    pd_Compactu32_t approvals;
} pd_DestroyWitness_V17_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V17_t id;
        pd_CompactAccountIndex_V17_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V17_t;

typedef struct {
    pd_Ratio_V17_t collateralFactor;
    pd_Ratio_V17_t liquidationThreshold;
    pd_Ratio_V17_t reserveFactor;
    pd_Ratio_V17_t closeFactor;
    pd_Rate_V17_t liquidateIncentive;
    pd_Ratio_V17_t liquidateIncentiveReservedFactor;
    pd_InterestRateModel_V17_t rateModel;
    pd_MarketState_V17_t state;
    pd_Balance_t supplyCap;
    pd_Balance_t borrowCap;
    pd_CurrencyId_V17_t ptokenId;
} pd_MarketBalanceOfT_V17_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V17_t;

typedef struct {
    uint8_t some;
    pd_Rate_V17_t contained;
} pd_OptionRate_V17_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V17_t contained;
} pd_OptionTimepoint_V17_t;

typedef struct {
    pd_u128_t value;
} pd_Price_V17_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V17_t accountId;
} pd_RewardDestination_V17_t;

typedef struct {
    pd_AccountId_V17_t stash;
    pd_Compactu128_t total;
    pd_Compactu128_t active;
    pd_VecUnlockChunk_V17_t unlocking;
    pd_VecEraIndex_V17_t claimedRewards;
} pd_StakingLedgerAccountIdBalanceOfT_V17_t;

typedef struct {
    pd_u128_t value;
} pd_StreamId_V17_t;

typedef struct {
    pd_Vecu8_t value;
} pd_TeleAccount_V17_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V17_t;

typedef struct {
    uint8_t value;
    pd_MultiLocationV1_V17_t sibling;
} pd_XcmCall_V17_t;

typedef struct {
    uint64_t weight;
    pd_Balance_t fee;
} pd_XcmWeightFeeMiscWeightBalanceOfT_V17_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOfT_V17_t;

typedef struct {
    uint8_t value;
} pd_BridgeType_V17_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V17_t;

typedef struct {
    uint32_t value;
} pd_ChainId_V17_t;

typedef struct {
    uint64_t value;
} pd_ChainNonce_V17_t;

typedef struct {
    uint8_t value;
} pd_ChildStorageKind_V17_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V17_t;

typedef struct {
    uint16_t value;
} pd_DerivativeIndex_V17_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V17_t;

typedef struct {
    uint32_t value;
} pd_LeasePeriod_V17_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V17_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V17_t contained;
} pd_OptionAccountId_V17_t;

typedef struct {
    uint8_t some;
    pd_ContributionStrategy_V17_t contained;
} pd_OptionContributionStrategy_V17_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V17_t contained;
} pd_OptionProxyType_V17_t;

typedef struct {
    uint8_t some;
    pd_Ratio_V17_t contained;
} pd_OptionRatio_V17_t;

typedef struct {
    uint64_t value;
} pd_OverweightIndex_V17_t;

typedef struct {
    uint32_t value;
} pd_ParaId_V17_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V17_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V17_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V17_t;

typedef struct {
    uint64_t value;
} pd_Timestamp_V17_t;

typedef struct {
    uint8_t value;
} pd_UnstakeProvider_V17_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V17_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdOf_V17_t;

typedef struct {
    uint64_t value;
} pd_Weight_V17_t;

#ifdef __cplusplus
}
#endif
