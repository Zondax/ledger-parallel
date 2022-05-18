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
} pd_Fraction_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_Vecu8_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V15_t fraction;
    };
} pd_BodyPart_V15_t;

typedef struct {
    uint8_t value;
    pd_Vecu8_t named;
} pd_NetworkId_V15_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V15_t;

typedef struct {
    pd_NetworkId_V15_t networkId;
    pd_u8_array_32_V15_t key;
} pd_AccountId32_V15_t;

typedef struct {
    pd_NetworkId_V15_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V15_t;

typedef struct {
    pd_NetworkId_V15_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V15_t;

typedef struct {
    pd_BodyId_V15_t id;
    pd_BodyPart_V15_t part;
} pd_Plurality_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V15_t accountId32;
        pd_AccountIndex64_V15_t accountIndex64;
        pd_AccountKey20_V15_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Vecu8_t generalKey;
        pd_Plurality_V15_t plurality;
    };
} pd_Junction_V15_t;

typedef struct {
    pd_Junction_V15_t junction;
} pd_JunctionX1_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
} pd_JunctionX2_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
    pd_Junction_V15_t junction2;
} pd_JunctionX3_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
    pd_Junction_V15_t junction2;
    pd_Junction_V15_t junction3;
} pd_JunctionX4_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
    pd_Junction_V15_t junction2;
    pd_Junction_V15_t junction3;
    pd_Junction_V15_t junction4;
} pd_JunctionX5_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
    pd_Junction_V15_t junction2;
    pd_Junction_V15_t junction3;
    pd_Junction_V15_t junction4;
    pd_Junction_V15_t junction5;
} pd_JunctionX6_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
    pd_Junction_V15_t junction2;
    pd_Junction_V15_t junction3;
    pd_Junction_V15_t junction4;
    pd_Junction_V15_t junction5;
    pd_Junction_V15_t junction6;
} pd_JunctionX7_V15_t;

typedef struct {
    pd_Junction_V15_t junction0;
    pd_Junction_V15_t junction1;
    pd_Junction_V15_t junction2;
    pd_Junction_V15_t junction3;
    pd_Junction_V15_t junction4;
    pd_Junction_V15_t junction5;
    pd_Junction_V15_t junction6;
    pd_Junction_V15_t junction7;
} pd_JunctionX8_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionX1_V15_t x1;
        pd_JunctionX2_V15_t x2;
        pd_JunctionX3_V15_t x3;
        pd_JunctionX4_V15_t x4;
        pd_JunctionX5_V15_t x5;
        pd_JunctionX6_V15_t x6;
        pd_JunctionX7_V15_t x7;
        pd_JunctionX8_V15_t x8;
    };
} pd_Junctions_V15_t;

typedef struct {
    pd_Junctions_V15_t junctions;
} pd_MultiLocationV0_V15_t;

typedef struct {
    uint8_t parents;
    pd_Junctions_V15_t interior;
} pd_MultiLocationV1_V15_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_u128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstance_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V15_t multilocationV0;
        pd_MultiLocationV1_V15_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V15_t;

typedef struct {
    pd_Compactu128_t value;
} pd_Fungible_V15_t;

typedef struct {
    pd_Vecu8_t id;
    pd_Compactu128_t amount;
} pd_AbstractFungible_V15_t;

typedef struct {
    pd_Vecu8_t _class;
    pd_AssetInstance_V15_t instance;
} pd_AbstractNonFungible_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_BoxVersionedMultiLocation_V15_t concrete;
        pd_Vecu8_t abstract;
    };
} pd_AssetId_V15_t;

typedef struct {
    pd_MultiLocationV0_V15_t id;
    pd_Compactu128_t amount;
} pd_ConcreteFungible_V15_t;

typedef struct {
    pd_MultiLocationV0_V15_t _class;
    pd_AssetInstance_V15_t instance;
} pd_ConcreteNonFungible_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_Fungible_V15_t fungible;
        pd_AssetInstance_V15_t nonFungible;
    };
} pd_Fungibility_V15_t;

typedef struct {
    pd_u128_t value;
} pd_Rate_V15_t;

typedef struct {
    uint32_t value;
} pd_Ratio_V15_t;

typedef struct {
    pd_Rate_V15_t baseRate;
} pd_CurveModel_V15_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V15_t;

typedef struct {
    pd_Rate_V15_t baseRate;
    pd_Rate_V15_t jumpRate;
    pd_Rate_V15_t fullRate;
    pd_Ratio_V15_t jumpUtilization;
} pd_JumpModel_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_Vecu8_t abstract;
        pd_MultiLocationV0_V15_t concrete;
        pd_AbstractFungible_V15_t abstractFungible;
        pd_AbstractNonFungible_V15_t abstractNonFungible;
        pd_ConcreteFungible_V15_t concreteFungible;
        pd_ConcreteNonFungible_V15_t concreteNonFungible;
    };
} pd_MultiAssetV0_V15_t;

typedef struct {
    pd_AssetId_V15_t assetId;
    pd_Fungibility_V15_t fungibility;
} pd_MultiAssetV1_V15_t;

typedef struct {
    pd_Compactu128_t value;
    pd_Compactu32_t era;
} pd_UnlockChunk_V15_t;

typedef struct {
    uint8_t value;
} pd_Vote_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AccountIdOfT_V15_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V15_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V15_t;

typedef struct {
    pd_Vote_V15_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V15_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOf_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BalanceOfT_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BlockNumberForT_V15_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ContributionStrategy_V15_t;

typedef struct {
    uint32_t value;
} pd_CurrencyId_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_JumpModel_V15_t jump;
        pd_CurveModel_V15_t curve;
    };
} pd_InterestRateModel_V15_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V15_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V15_t;

typedef struct {
    uint8_t value;
} pd_MarketState_V15_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V15_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V15_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleCurrencyIdBalance_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleOracleKeyOracleValue_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecEraIndex_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV0_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV1_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecUnlockChunk_V15_t;

typedef struct {
    pd_BlockNumber_t start;
    pd_BlockNumber_t period;
    uint32_t periodCount;
    pd_Compactu128_t perPeriod;
} pd_VestingScheduleOf_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V15_t voteStandard;
        pd_AccountVoteSplit_V15_t voteSplit;
    };
} pd_AccountVote_V15_t;

typedef struct {
    pd_AssetIdOf_V15_t assetid1;
    pd_AssetIdOf_V15_t assetid2;
} pd_AssetIdOfAssetIdOf_V15_t;

typedef struct {
    pd_Balance_t balance1;
    pd_Balance_t balance2;
} pd_BalanceOfBalanceOf_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiAssetV0_V15_t multiassetV0;
        pd_MultiAssetV1_V15_t multiassetV1;
    };
} pd_BoxVersionedMultiAsset_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_V15_t vecMultiassetV0;
        pd_VecMultiAssetV1_V15_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_V15_t;

typedef struct {
    pd_CurrencyId_V15_t id;
    pd_bool_t external;
    pd_Balance_t fee;
    pd_bool_t enable;
    pd_Balance_t outCap;
    pd_Balance_t outAmount;
    pd_Balance_t inCap;
    pd_Balance_t inAmount;
} pd_BridgeToken_V15_t;

typedef struct {
    pd_Compactu32_t accounts;
    pd_Compactu32_t sufficients;
    pd_Compactu32_t approvals;
} pd_DestroyWitness_V15_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V15_t id;
        pd_CompactAccountIndex_V15_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V15_t;

typedef struct {
    pd_Ratio_V15_t collateralFactor;
    pd_Ratio_V15_t liquidationThreshold;
    pd_Ratio_V15_t reserveFactor;
    pd_Ratio_V15_t closeFactor;
    pd_Rate_V15_t liquidateIncentive;
    pd_Ratio_V15_t liquidateIncentiveReservedFactor;
    pd_InterestRateModel_V15_t rateModel;
    pd_MarketState_V15_t state;
    pd_Balance_t supplyCap;
    pd_Balance_t borrowCap;
    pd_CurrencyId_V15_t ptokenId;
} pd_MarketBalanceOfT_V15_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V15_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V15_t contained;
} pd_OptionTimepoint_V15_t;

typedef struct {
    pd_u128_t value;
} pd_Price_V15_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V15_t accountId;
} pd_RewardDestination_V15_t;

typedef struct {
    pd_AccountId_V15_t stash;
    pd_Compactu128_t total;
    pd_Compactu128_t active;
    pd_VecUnlockChunk_V15_t unlocking;
    pd_VecEraIndex_V15_t claimedRewards;
} pd_StakingLedgerAccountIdBalanceOfT_V15_t;

typedef struct {
    pd_Vecu8_t value;
} pd_TeleAccount_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AccountOfT_V15_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOfT_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AssetType_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallIdOfT_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallOrHashOfT_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V15_t;

typedef struct {
    uint8_t value;
} pd_BridgeType_V15_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V15_t;

typedef struct {
    uint32_t value;
} pd_ChainId_V15_t;

typedef struct {
    uint64_t value;
} pd_ChainNonce_V15_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V15_t;

typedef struct {
    uint16_t value;
} pd_DerivativeIndex_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DoubleEncodedTuple_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V15_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LeasePeriod_V15_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V15_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V15_t contained;
} pd_OptionAccountId_V15_t;

typedef struct {
    uint8_t some;
    pd_BalanceOfT_V15_t contained;
} pd_OptionBalanceOfT_V15_t;

typedef struct {
    uint8_t some;
    pd_BlockNumberForT_V15_t contained;
} pd_OptionBlockNumberForT_V15_t;

typedef struct {
    uint8_t some;
    pd_ContributionStrategy_V15_t contained;
} pd_OptionContributionStrategy_V15_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V15_t contained;
} pd_OptionProxyType_V15_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V15_t contained;
} pd_OptionReferendumIndex_V15_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V15_t contained;
} pd_OptionXcmVersion_V15_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V15_t contained;
} pd_OptionschedulePeriodBlockNumber_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V15_t;

typedef struct {
    uint32_t value;
} pd_ParaId_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainInherentData_V15_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V15_t;

typedef struct {
    uint64_t value;
} pd_QueryId_V15_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Response_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_RewardDestinationAccountIdOfT_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StreamId_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Timestamp_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UpwardMessage_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountIdOfT_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdOf_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleCurrencyIdBalance_V15_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleOracleKeyOracleValue_V15_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V15_t;

typedef struct {
    uint64_t value;
} pd_Weight_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmCall_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmWeightFeeMiscWeightBalanceOfT_V15_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V15_t;

#ifdef __cplusplus
}
#endif
