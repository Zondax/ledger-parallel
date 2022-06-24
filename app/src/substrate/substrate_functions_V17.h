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

#include "parser_common.h"
#include "substrate_methods_V17.h"
#include "substrate_types_V17.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId32_V17(parser_context_t* c, pd_AccountId32_V17_t* v);
parser_error_t _readAccountId_V17(parser_context_t* c, pd_AccountId_V17_t* v);
parser_error_t _readAccountIndex64_V17(parser_context_t* c, pd_AccountIndex64_V17_t* v);
parser_error_t _readAccountKey20_V17(parser_context_t* c, pd_AccountKey20_V17_t* v);
parser_error_t _readAssetIdOfAssetIdOf_V17(parser_context_t* c, pd_AssetIdOfAssetIdOf_V17_t* v);
parser_error_t _readAssetIdOfT_V17(parser_context_t* c, pd_AssetIdOfT_V17_t* v);
parser_error_t _readAssetIdOf_V17(parser_context_t* c, pd_AssetIdOf_V17_t* v);
parser_error_t _readBalanceOfBalanceOf_V17(parser_context_t* c, pd_BalanceOfBalanceOf_V17_t* v);
parser_error_t _readBodyId_V17(parser_context_t* c, pd_BodyId_V17_t* v);
parser_error_t _readBodyPart_V17(parser_context_t* c, pd_BodyPart_V17_t* v);
parser_error_t _readBoxVersionedMultiLocation_V17(parser_context_t* c, pd_BoxVersionedMultiLocation_V17_t* v);
parser_error_t _readBridgeToken_V17(parser_context_t* c, pd_BridgeToken_V17_t* v);
parser_error_t _readBridgeType_V17(parser_context_t* c, pd_BridgeType_V17_t* v);
parser_error_t _readCallHashOf_V17(parser_context_t* c, pd_CallHashOf_V17_t* v);
parser_error_t _readChainId_V17(parser_context_t* c, pd_ChainId_V17_t* v);
parser_error_t _readChainNonce_V17(parser_context_t* c, pd_ChainNonce_V17_t* v);
parser_error_t _readChildStorageKind_V17(parser_context_t* c, pd_ChildStorageKind_V17_t* v);
parser_error_t _readCompactAccountIndex_V17(parser_context_t* c, pd_CompactAccountIndex_V17_t* v);
parser_error_t _readContributionStrategy_V17(parser_context_t* c, pd_ContributionStrategy_V17_t* v);
parser_error_t _readConviction_V17(parser_context_t* c, pd_Conviction_V17_t* v);
parser_error_t _readCurrencyId_V17(parser_context_t* c, pd_CurrencyId_V17_t* v);
parser_error_t _readCurveModel_V17(parser_context_t* c, pd_CurveModel_V17_t* v);
parser_error_t _readDerivativeIndex_V17(parser_context_t* c, pd_DerivativeIndex_V17_t* v);
parser_error_t _readDestroyWitness_V17(parser_context_t* c, pd_DestroyWitness_V17_t* v);
parser_error_t _readEraIndex_V17(parser_context_t* c, pd_EraIndex_V17_t* v);
parser_error_t _readFraction_V17(parser_context_t* c, pd_Fraction_V17_t* v);
parser_error_t _readInterestRateModel_V17(parser_context_t* c, pd_InterestRateModel_V17_t* v);
parser_error_t _readJumpModel_V17(parser_context_t* c, pd_JumpModel_V17_t* v);
parser_error_t _readJunctionV0X1_V17(parser_context_t* c, pd_JunctionV0X1_V17_t* v);
parser_error_t _readJunctionV0X2_V17(parser_context_t* c, pd_JunctionV0X2_V17_t* v);
parser_error_t _readJunctionV0X3_V17(parser_context_t* c, pd_JunctionV0X3_V17_t* v);
parser_error_t _readJunctionV0X4_V17(parser_context_t* c, pd_JunctionV0X4_V17_t* v);
parser_error_t _readJunctionV0X5_V17(parser_context_t* c, pd_JunctionV0X5_V17_t* v);
parser_error_t _readJunctionV0X6_V17(parser_context_t* c, pd_JunctionV0X6_V17_t* v);
parser_error_t _readJunctionV0X7_V17(parser_context_t* c, pd_JunctionV0X7_V17_t* v);
parser_error_t _readJunctionV0X8_V17(parser_context_t* c, pd_JunctionV0X8_V17_t* v);
parser_error_t _readJunctionV0_V17(parser_context_t* c, pd_JunctionV0_V17_t* v);
parser_error_t _readJunctionV1X1_V17(parser_context_t* c, pd_JunctionV1X1_V17_t* v);
parser_error_t _readJunctionV1X2_V17(parser_context_t* c, pd_JunctionV1X2_V17_t* v);
parser_error_t _readJunctionV1X3_V17(parser_context_t* c, pd_JunctionV1X3_V17_t* v);
parser_error_t _readJunctionV1X4_V17(parser_context_t* c, pd_JunctionV1X4_V17_t* v);
parser_error_t _readJunctionV1X5_V17(parser_context_t* c, pd_JunctionV1X5_V17_t* v);
parser_error_t _readJunctionV1X6_V17(parser_context_t* c, pd_JunctionV1X6_V17_t* v);
parser_error_t _readJunctionV1X7_V17(parser_context_t* c, pd_JunctionV1X7_V17_t* v);
parser_error_t _readJunctionV1X8_V17(parser_context_t* c, pd_JunctionV1X8_V17_t* v);
parser_error_t _readJunctionV1_V17(parser_context_t* c, pd_JunctionV1_V17_t* v);
parser_error_t _readJunctionsV0_V17(parser_context_t* c, pd_JunctionsV0_V17_t* v);
parser_error_t _readJunctionsV1_V17(parser_context_t* c, pd_JunctionsV1_V17_t* v);
parser_error_t _readKeys_V17(parser_context_t* c, pd_Keys_V17_t* v);
parser_error_t _readLeasePeriod_V17(parser_context_t* c, pd_LeasePeriod_V17_t* v);
parser_error_t _readLookupasStaticLookupSource_V17(parser_context_t* c, pd_LookupasStaticLookupSource_V17_t* v);
parser_error_t _readMarketBalanceOfT_V17(parser_context_t* c, pd_MarketBalanceOfT_V17_t* v);
parser_error_t _readMarketState_V17(parser_context_t* c, pd_MarketState_V17_t* v);
parser_error_t _readMemberCount_V17(parser_context_t* c, pd_MemberCount_V17_t* v);
parser_error_t _readMultiLocationV0_V17(parser_context_t* c, pd_MultiLocationV0_V17_t* v);
parser_error_t _readMultiLocationV1_V17(parser_context_t* c, pd_MultiLocationV1_V17_t* v);
parser_error_t _readNetworkId_V17(parser_context_t* c, pd_NetworkId_V17_t* v);
parser_error_t _readOpaqueCall_V17(parser_context_t* c, pd_OpaqueCall_V17_t* v);
parser_error_t _readOptionAccountId_V17(parser_context_t* c, pd_OptionAccountId_V17_t* v);
parser_error_t _readOptionContributionStrategy_V17(parser_context_t* c, pd_OptionContributionStrategy_V17_t* v);
parser_error_t _readOptionProxyType_V17(parser_context_t* c, pd_OptionProxyType_V17_t* v);
parser_error_t _readOptionRate_V17(parser_context_t* c, pd_OptionRate_V17_t* v);
parser_error_t _readOptionRatio_V17(parser_context_t* c, pd_OptionRatio_V17_t* v);
parser_error_t _readOptionTimepoint_V17(parser_context_t* c, pd_OptionTimepoint_V17_t* v);
parser_error_t _readOverweightIndex_V17(parser_context_t* c, pd_OverweightIndex_V17_t* v);
parser_error_t _readParaId_V17(parser_context_t* c, pd_ParaId_V17_t* v);
parser_error_t _readPerbill_V17(parser_context_t* c, pd_Perbill_V17_t* v);
parser_error_t _readPlurality_V17(parser_context_t* c, pd_Plurality_V17_t* v);
parser_error_t _readPrice_V17(parser_context_t* c, pd_Price_V17_t* v);
parser_error_t _readProxyType_V17(parser_context_t* c, pd_ProxyType_V17_t* v);
parser_error_t _readRate_V17(parser_context_t* c, pd_Rate_V17_t* v);
parser_error_t _readRatio_V17(parser_context_t* c, pd_Ratio_V17_t* v);
parser_error_t _readReferendumIndex_V17(parser_context_t* c, pd_ReferendumIndex_V17_t* v);
parser_error_t _readRegistrarIndex_V17(parser_context_t* c, pd_RegistrarIndex_V17_t* v);
parser_error_t _readRewardDestination_V17(parser_context_t* c, pd_RewardDestination_V17_t* v);
parser_error_t _readStakingLedgerAccountIdBalanceOfT_V17(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V17_t* v);
parser_error_t _readTeleAccount_V17(parser_context_t* c, pd_TeleAccount_V17_t* v);
parser_error_t _readTimepoint_V17(parser_context_t* c, pd_Timepoint_V17_t* v);
parser_error_t _readUnlockChunk_V17(parser_context_t* c, pd_UnlockChunk_V17_t* v);
parser_error_t _readUnstakeProvider_V17(parser_context_t* c, pd_UnstakeProvider_V17_t* v);
parser_error_t _readVecAccountId_V17(parser_context_t* c, pd_VecAccountId_V17_t* v);
parser_error_t _readVecAssetIdOf_V17(parser_context_t* c, pd_VecAssetIdOf_V17_t* v);
parser_error_t _readVecEraIndex_V17(parser_context_t* c, pd_VecEraIndex_V17_t* v);
parser_error_t _readVecUnlockChunk_V17(parser_context_t* c, pd_VecUnlockChunk_V17_t* v);
parser_error_t _readVecVestingScheduleOf_V17(parser_context_t* c, pd_VecVestingScheduleOf_V17_t* v);
parser_error_t _readVestingScheduleOf_V17(parser_context_t* c, pd_VestingScheduleOf_V17_t* v);
parser_error_t _readWeight_V17(parser_context_t* c, pd_Weight_V17_t* v);
parser_error_t _readu8_array_32_V17(parser_context_t* c, pd_u8_array_32_V17_t* v);

// toString functions
parser_error_t _toStringAccountId32_V17(
    const pd_AccountId32_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V17(
    const pd_AccountId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V17(
    const pd_AccountIndex64_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V17(
    const pd_AccountKey20_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfAssetIdOf_V17(
    const pd_AssetIdOfAssetIdOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfT_V17(
    const pd_AssetIdOfT_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOf_V17(
    const pd_AssetIdOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfBalanceOf_V17(
    const pd_BalanceOfBalanceOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V17(
    const pd_BodyId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V17(
    const pd_BodyPart_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V17(
    const pd_BoxVersionedMultiLocation_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeToken_V17(
    const pd_BridgeToken_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeType_V17(
    const pd_BridgeType_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V17(
    const pd_CallHashOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainId_V17(
    const pd_ChainId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainNonce_V17(
    const pd_ChainNonce_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChildStorageKind_V17(
    const pd_ChildStorageKind_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V17(
    const pd_CompactAccountIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringContributionStrategy_V17(
    const pd_ContributionStrategy_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V17(
    const pd_Conviction_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V17(
    const pd_CurrencyId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurveModel_V17(
    const pd_CurveModel_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDerivativeIndex_V17(
    const pd_DerivativeIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V17(
    const pd_DestroyWitness_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V17(
    const pd_EraIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V17(
    const pd_Fraction_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInterestRateModel_V17(
    const pd_InterestRateModel_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJumpModel_V17(
    const pd_JumpModel_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1_V17(
    const pd_JunctionV0X1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2_V17(
    const pd_JunctionV0X2_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3_V17(
    const pd_JunctionV0X3_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4_V17(
    const pd_JunctionV0X4_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5_V17(
    const pd_JunctionV0X5_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6_V17(
    const pd_JunctionV0X6_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7_V17(
    const pd_JunctionV0X7_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8_V17(
    const pd_JunctionV0X8_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0_V17(
    const pd_JunctionV0_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1_V17(
    const pd_JunctionV1X1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2_V17(
    const pd_JunctionV1X2_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3_V17(
    const pd_JunctionV1X3_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4_V17(
    const pd_JunctionV1X4_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5_V17(
    const pd_JunctionV1X5_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6_V17(
    const pd_JunctionV1X6_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7_V17(
    const pd_JunctionV1X7_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8_V17(
    const pd_JunctionV1X8_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1_V17(
    const pd_JunctionV1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0_V17(
    const pd_JunctionsV0_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1_V17(
    const pd_JunctionsV1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V17(
    const pd_Keys_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriod_V17(
    const pd_LeasePeriod_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V17(
    const pd_LookupasStaticLookupSource_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketBalanceOfT_V17(
    const pd_MarketBalanceOfT_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketState_V17(
    const pd_MarketState_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V17(
    const pd_MemberCount_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V17(
    const pd_MultiLocationV0_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V17(
    const pd_MultiLocationV1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V17(
    const pd_NetworkId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V17(
    const pd_OpaqueCall_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V17(
    const pd_OptionAccountId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionContributionStrategy_V17(
    const pd_OptionContributionStrategy_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V17(
    const pd_OptionProxyType_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRate_V17(
    const pd_OptionRate_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRatio_V17(
    const pd_OptionRatio_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V17(
    const pd_OptionTimepoint_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V17(
    const pd_OverweightIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V17(
    const pd_ParaId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V17(
    const pd_Perbill_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V17(
    const pd_Plurality_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPrice_V17(
    const pd_Price_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V17(
    const pd_ProxyType_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRate_V17(
    const pd_Rate_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRatio_V17(
    const pd_Ratio_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V17(
    const pd_ReferendumIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V17(
    const pd_RegistrarIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V17(
    const pd_RewardDestination_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V17(
    const pd_StakingLedgerAccountIdBalanceOfT_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTeleAccount_V17(
    const pd_TeleAccount_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V17(
    const pd_Timepoint_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUnlockChunk_V17(
    const pd_UnlockChunk_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUnstakeProvider_V17(
    const pd_UnstakeProvider_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V17(
    const pd_VecAccountId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdOf_V17(
    const pd_VecAssetIdOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecEraIndex_V17(
    const pd_VecEraIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecUnlockChunk_V17(
    const pd_VecUnlockChunk_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V17(
    const pd_VecVestingScheduleOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V17(
    const pd_VestingScheduleOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V17(
    const pd_Weight_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V17(
    const pd_u8_array_32_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
