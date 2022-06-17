/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
} pd_Fraction_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V16_t fraction;
    };
} pd_BodyPart_V16_t;

typedef struct {
    uint8_t value;
    pd_Bytes_t named;
} pd_NetworkId_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V16_t;

typedef struct {
    pd_NetworkId_V16_t networkId;
    pd_u8_array_32_V16_t key;
} pd_AccountId32_V16_t;

typedef struct {
    pd_NetworkId_V16_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V16_t;

typedef struct {
    pd_NetworkId_V16_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V16_t;

typedef struct {
    pd_BodyId_V16_t id;
    pd_BodyPart_V16_t part;
} pd_Plurality_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V16_t accountId32;
        pd_AccountIndex64_V16_t accountIndex64;
        pd_AccountKey20_V16_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V16_t plurality;
    };
} pd_JunctionV0_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V16_t accountId32;
        pd_AccountIndex64_V16_t accountIndex64;
        pd_AccountKey20_V16_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V16_t plurality;
    };
} pd_JunctionV1_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction;
} pd_JunctionV0X1_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
} pd_JunctionV0X2_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
} pd_JunctionV0X3_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction;
} pd_JunctionV1X1_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
} pd_JunctionV1X2_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
} pd_JunctionV1X3_V16_t;

typedef struct {
    pd_u128_t value;
} pd_Rate_V16_t;

typedef struct {
    uint32_t value;
} pd_Ratio_V16_t;

typedef struct {
    pd_Rate_V16_t baseRate;
} pd_CurveModel_V16_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V16_t;

typedef struct {
    pd_Rate_V16_t baseRate;
    pd_Rate_V16_t jumpRate;
    pd_Rate_V16_t fullRate;
    pd_Ratio_V16_t jumpUtilization;
} pd_JumpModel_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV0X1_V16_t x1;
        pd_JunctionV0X2_V16_t x2;
        pd_JunctionV0X3_V16_t x3;
        // pd_JunctionV0X4_t x4;
        // pd_JunctionV0X5_t x5;
        // pd_JunctionV0X6_t x6;
        // pd_JunctionV0X7_t x7;
        // pd_JunctionV0X8_t x8;
    };
} pd_JunctionsV0_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV1X1_V16_t x1;
        pd_JunctionV1X2_V16_t x2;
        pd_JunctionV1X3_V16_t x3;
        // pd_JunctionV1X4_t x4;
        // pd_JunctionV1X5_t x5;
        // pd_JunctionV1X6_t x6;
        // pd_JunctionV1X7_t x7;
        // pd_JunctionV1X8_t x8;
    };
} pd_JunctionsV1_V16_t;

typedef struct {
    pd_Compactu128_t value;
    pd_Compactu32_t era;
} pd_UnlockChunk_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V16_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOf_V16_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V16_t;

typedef struct {
    uint8_t value;
} pd_ContributionStrategy_V16_t;

typedef struct {
    uint32_t value;
} pd_CurrencyId_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_JumpModel_V16_t jump;
        pd_CurveModel_V16_t curve;
    };
} pd_InterestRateModel_V16_t;

typedef struct {
    uint8_t value;
} pd_MarketState_V16_t;

typedef struct {
    pd_JunctionsV0_V16_t junctions;
} pd_MultiLocationV0_V16_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV1_V16_t interior;
} pd_MultiLocationV1_V16_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V16_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecEraIndex_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecUnlockChunk_V16_t;

typedef struct {
    pd_BlockNumber_t start;
    pd_BlockNumber_t period;
    uint32_t periodCount;
    pd_Compactu128_t perPeriod;
} pd_VestingScheduleOf_V16_t;

typedef struct {
    pd_AssetIdOf_V16_t assetid1;
    pd_AssetIdOf_V16_t assetid2;
} pd_AssetIdOfAssetIdOf_V16_t;

typedef struct {
    pd_Balance_t balance1;
    pd_Balance_t balance2;
} pd_BalanceOfBalanceOf_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V16_t multilocationV0;
        pd_MultiLocationV1_V16_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V16_t;

typedef struct {
    pd_CurrencyId_V16_t id;
    pd_bool_t external;
    pd_Balance_t fee;
    pd_bool_t enable;
    pd_Balance_t outCap;
    pd_Balance_t outAmount;
    pd_Balance_t inCap;
    pd_Balance_t inAmount;
} pd_BridgeToken_V16_t;

typedef struct {
    pd_Compactu32_t accounts;
    pd_Compactu32_t sufficients;
    pd_Compactu32_t approvals;
} pd_DestroyWitness_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V16_t id;
        pd_CompactAccountIndex_V16_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V16_t;

typedef struct {
    pd_Ratio_V16_t collateralFactor;
    pd_Ratio_V16_t liquidationThreshold;
    pd_Ratio_V16_t reserveFactor;
    pd_Ratio_V16_t closeFactor;
    pd_Rate_V16_t liquidateIncentive;
    pd_Ratio_V16_t liquidateIncentiveReservedFactor;
    pd_InterestRateModel_V16_t rateModel;
    pd_MarketState_V16_t state;
    pd_Balance_t supplyCap;
    pd_Balance_t borrowCap;
    pd_CurrencyId_V16_t ptokenId;
} pd_MarketBalanceOfT_V16_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V16_t;

typedef struct {
    uint8_t some;
    pd_Rate_V16_t contained;
} pd_OptionRate_V16_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V16_t contained;
} pd_OptionTimepoint_V16_t;

typedef struct {
    pd_u128_t value;
} pd_Price_V16_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V16_t accountId;
} pd_RewardDestination_V16_t;

typedef struct {
    pd_AccountId_V16_t stash;
    pd_Compactu128_t total;
    pd_Compactu128_t active;
    pd_VecUnlockChunk_V16_t unlocking;
    pd_VecEraIndex_V16_t claimedRewards;
} pd_StakingLedgerAccountIdBalanceOfT_V16_t;

typedef struct {
    pd_Vecu8_t value;
} pd_TeleAccount_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V16_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOfT_V16_t;

typedef struct {
    uint8_t value;
} pd_BridgeType_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V16_t;

typedef struct {
    uint32_t value;
} pd_ChainId_V16_t;

typedef struct {
    uint64_t value;
} pd_ChainNonce_V16_t;

typedef struct {
    uint8_t value;
} pd_ChildStorageKind_V16_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V16_t;

typedef struct {
    uint16_t value;
} pd_DerivativeIndex_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V16_t;

typedef struct {
    uint32_t value;
} pd_LeasePeriod_V16_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V16_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V16_t contained;
} pd_OptionAccountId_V16_t;

typedef struct {
    uint8_t some;
    pd_ContributionStrategy_V16_t contained;
} pd_OptionContributionStrategy_V16_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V16_t contained;
} pd_OptionProxyType_V16_t;

typedef struct {
    uint8_t some;
    pd_Ratio_V16_t contained;
} pd_OptionRatio_V16_t;

typedef struct {
    uint64_t value;
} pd_OverweightIndex_V16_t;

typedef struct {
    uint32_t value;
} pd_ParaId_V16_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V16_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V16_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdOf_V16_t;

typedef struct {
    uint64_t value;
} pd_Weight_V16_t;

#ifdef __cplusplus
}
#endif
