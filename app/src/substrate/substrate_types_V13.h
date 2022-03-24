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
} pd_Fraction_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_Vecu8_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V13_t fraction;
    };
} pd_BodyPart_V13_t;

typedef struct {
    uint8_t value;
    pd_Vecu8_t named;
} pd_NetworkId_V13_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V13_t;

typedef struct {
    pd_NetworkId_V13_t networkId;
    pd_u8_array_32_V13_t key;
} pd_AccountId32_V13_t;

typedef struct {
    pd_NetworkId_V13_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V13_t;

typedef struct {
    pd_NetworkId_V13_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V13_t;

typedef struct {
    pd_BodyId_V13_t id;
    pd_BodyPart_V13_t part;
} pd_Plurality_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V13_t accountId32;
        pd_AccountIndex64_V13_t accountIndex64;
        pd_AccountKey20_V13_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Vecu8_t generalKey;
        pd_Plurality_V13_t plurality;
    };
} pd_Junction_V13_t;

typedef struct {
    pd_Junction_V13_t junction;
} pd_JunctionX1_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
} pd_JunctionX2_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
    pd_Junction_V13_t junction2;
} pd_JunctionX3_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
    pd_Junction_V13_t junction2;
    pd_Junction_V13_t junction3;
} pd_JunctionX4_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
    pd_Junction_V13_t junction2;
    pd_Junction_V13_t junction3;
    pd_Junction_V13_t junction4;
} pd_JunctionX5_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
    pd_Junction_V13_t junction2;
    pd_Junction_V13_t junction3;
    pd_Junction_V13_t junction4;
    pd_Junction_V13_t junction5;
} pd_JunctionX6_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
    pd_Junction_V13_t junction2;
    pd_Junction_V13_t junction3;
    pd_Junction_V13_t junction4;
    pd_Junction_V13_t junction5;
    pd_Junction_V13_t junction6;
} pd_JunctionX7_V13_t;

typedef struct {
    pd_Junction_V13_t junction0;
    pd_Junction_V13_t junction1;
    pd_Junction_V13_t junction2;
    pd_Junction_V13_t junction3;
    pd_Junction_V13_t junction4;
    pd_Junction_V13_t junction5;
    pd_Junction_V13_t junction6;
    pd_Junction_V13_t junction7;
} pd_JunctionX8_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionX1_V13_t x1;
        pd_JunctionX2_V13_t x2;
        pd_JunctionX3_V13_t x3;
        pd_JunctionX4_V13_t x4;
        pd_JunctionX5_V13_t x5;
        pd_JunctionX6_V13_t x6;
        pd_JunctionX7_V13_t x7;
        pd_JunctionX8_V13_t x8;
    };
} pd_Junctions_V13_t;

typedef struct {
    pd_Junctions_V13_t junctions;
} pd_MultiLocationV0_V13_t;

typedef struct {
    uint8_t parents;
    pd_Junctions_V13_t interior;
} pd_MultiLocationV1_V13_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_u128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstance_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V13_t multilocationV0;
        pd_MultiLocationV1_V13_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V13_t;

typedef struct {
    pd_Compactu128_t value;
} pd_Fungible_V13_t;

typedef struct {
    pd_Vecu8_t id;
    pd_Compactu128_t amount;
} pd_AbstractFungible_V13_t;

typedef struct {
    pd_Vecu8_t _class;
    pd_AssetInstance_V13_t instance;
} pd_AbstractNonFungible_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_BoxVersionedMultiLocation_V13_t concrete;
        pd_Vecu8_t abstract;
    };
} pd_AssetId_V13_t;

typedef struct {
    pd_MultiLocationV0_V13_t id;
    pd_Compactu128_t amount;
} pd_ConcreteFungible_V13_t;

typedef struct {
    pd_MultiLocationV0_V13_t _class;
    pd_AssetInstance_V13_t instance;
} pd_ConcreteNonFungible_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_Fungible_V13_t fungible;
        pd_AssetInstance_V13_t nonFungible;
    };
} pd_Fungibility_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_Vecu8_t abstract;
        pd_MultiLocationV0_V13_t concrete;
        pd_AbstractFungible_V13_t abstractFungible;
        pd_AbstractNonFungible_V13_t abstractNonFungible;
        pd_ConcreteFungible_V13_t concreteFungible;
        pd_ConcreteNonFungible_V13_t concreteNonFungible;
    };
} pd_MultiAssetV0_V13_t;

typedef struct {
    pd_AssetId_V13_t assetId;
    pd_Fungibility_V13_t fungibility;
} pd_MultiAssetV1_V13_t;

typedef struct {
    uint8_t value;
} pd_Vote_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AccountIdOfT_V13_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V13_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V13_t;

typedef struct {
    pd_Vote_V13_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V13_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOfTI_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BalanceOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BlockNumberForT_V13_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ContributionStrategy_V13_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V13_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V13_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V13_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V13_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleCurrencyIdBalance_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleOracleKeyOracleValue_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV0_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV1_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_VestingScheduleOf_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V13_t voteStandard;
        pd_AccountVoteSplit_V13_t voteSplit;
    };
} pd_AccountVote_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiAssetV0_V13_t multiassetV0;
        pd_MultiAssetV1_V13_t multiassetV1;
    };
} pd_BoxVersionedMultiAsset_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_V13_t vecMultiassetV0;
        pd_VecMultiAssetV1_V13_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_V13_t;

typedef struct {
    pd_Compactu32_t accounts;
    pd_Compactu32_t sufficients;
    pd_Compactu32_t approvals;
} pd_DestroyWitness_V13_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V13_t id;
        pd_CompactAccountIndex_V13_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V13_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V13_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V13_t contained;
} pd_OptionTimepoint_V13_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V13_t accountId;
} pd_RewardDestination_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AccountOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AssetIdOfTIAssetIdOfTI_V13_t;

typedef struct {
    uint32_t value;
} pd_AssetIdOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AssetType_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BalanceOfTIBalanceOfTI_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallIdOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallOrHashOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BridgeToken_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BridgeType_V13_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChainId_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChainNonce_V13_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V13_t;

typedef struct {
    uint32_t value;
} pd_CurrencyId_V13_t;

typedef struct {
    uint16_t value;
} pd_DerivativeIndex_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DoubleEncodedTuple_V13_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_InterestRateModel_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V13_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LeasePeriod_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MarketBalanceOfT_V13_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V13_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V13_t contained;
} pd_OptionAccountId_V13_t;

typedef struct {
    uint8_t some;
    pd_BalanceOfT_V13_t contained;
} pd_OptionBalanceOfT_V13_t;

typedef struct {
    uint8_t some;
    pd_BlockNumberForT_V13_t contained;
} pd_OptionBlockNumberForT_V13_t;

typedef struct {
    uint8_t some;
    pd_ContributionStrategy_V13_t contained;
} pd_OptionContributionStrategy_V13_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V13_t contained;
} pd_OptionProxyType_V13_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V13_t contained;
} pd_OptionReferendumIndex_V13_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V13_t contained;
} pd_OptionXcmVersion_V13_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V13_t contained;
} pd_OptionschedulePeriodBlockNumber_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParaId_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainInherentData_V13_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Price_V13_t;

typedef struct {
    uint64_t value;
} pd_QueryId_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Rate_V13_t;

typedef struct {
    uint32_t value;
} pd_Ratio_V13_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Response_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_RewardDestinationAccountIdOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StakingLedgerAccountIdBalanceOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StreamId_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TeleAccount_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Timestamp_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UpwardMessage_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountIdOfT_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdOfTI_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleCurrencyIdBalance_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleOracleKeyOracleValue_V13_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V13_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V13_t;

typedef struct {
    uint64_t value;
} pd_Weight_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmCall_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmWeightFeeMiscWeightBalanceOfT_V13_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V13_t;

#ifdef __cplusplus
}
#endif
