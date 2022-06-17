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
#include "substrate_methods_V16.h"
#include "substrate_types_V16.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId32_V16(parser_context_t* c, pd_AccountId32_V16_t* v);
parser_error_t _readAccountId_V16(parser_context_t* c, pd_AccountId_V16_t* v);
parser_error_t _readAccountIndex64_V16(parser_context_t* c, pd_AccountIndex64_V16_t* v);
parser_error_t _readAccountKey20_V16(parser_context_t* c, pd_AccountKey20_V16_t* v);
parser_error_t _readAssetIdOfAssetIdOf_V16(parser_context_t* c, pd_AssetIdOfAssetIdOf_V16_t* v);
parser_error_t _readAssetIdOfT_V16(parser_context_t* c, pd_AssetIdOfT_V16_t* v);
parser_error_t _readAssetIdOf_V16(parser_context_t* c, pd_AssetIdOf_V16_t* v);
parser_error_t _readBalanceOfBalanceOf_V16(parser_context_t* c, pd_BalanceOfBalanceOf_V16_t* v);
parser_error_t _readBodyId_V16(parser_context_t* c, pd_BodyId_V16_t* v);
parser_error_t _readBodyPart_V16(parser_context_t* c, pd_BodyPart_V16_t* v);
parser_error_t _readBoxVersionedMultiLocation_V16(parser_context_t* c, pd_BoxVersionedMultiLocation_V16_t* v);
parser_error_t _readBridgeToken_V16(parser_context_t* c, pd_BridgeToken_V16_t* v);
parser_error_t _readBridgeType_V16(parser_context_t* c, pd_BridgeType_V16_t* v);
parser_error_t _readCallHashOf_V16(parser_context_t* c, pd_CallHashOf_V16_t* v);
parser_error_t _readChainId_V16(parser_context_t* c, pd_ChainId_V16_t* v);
parser_error_t _readChainNonce_V16(parser_context_t* c, pd_ChainNonce_V16_t* v);
parser_error_t _readChildStorageKind_V16(parser_context_t* c, pd_ChildStorageKind_V16_t* v);
parser_error_t _readCompactAccountIndex_V16(parser_context_t* c, pd_CompactAccountIndex_V16_t* v);
parser_error_t _readContributionStrategy_V16(parser_context_t* c, pd_ContributionStrategy_V16_t* v);
parser_error_t _readConviction_V16(parser_context_t* c, pd_Conviction_V16_t* v);
parser_error_t _readCurrencyId_V16(parser_context_t* c, pd_CurrencyId_V16_t* v);
parser_error_t _readCurveModel_V16(parser_context_t* c, pd_CurveModel_V16_t* v);
parser_error_t _readDerivativeIndex_V16(parser_context_t* c, pd_DerivativeIndex_V16_t* v);
parser_error_t _readDestroyWitness_V16(parser_context_t* c, pd_DestroyWitness_V16_t* v);
parser_error_t _readEraIndex_V16(parser_context_t* c, pd_EraIndex_V16_t* v);
parser_error_t _readFraction_V16(parser_context_t* c, pd_Fraction_V16_t* v);
parser_error_t _readInterestRateModel_V16(parser_context_t* c, pd_InterestRateModel_V16_t* v);
parser_error_t _readJumpModel_V16(parser_context_t* c, pd_JumpModel_V16_t* v);
parser_error_t _readJunctionV0X1_V16(parser_context_t* c, pd_JunctionV0X1_V16_t* v);
parser_error_t _readJunctionV0X2_V16(parser_context_t* c, pd_JunctionV0X2_V16_t* v);
parser_error_t _readJunctionV0X3_V16(parser_context_t* c, pd_JunctionV0X3_V16_t* v);
parser_error_t _readJunctionV0_V16(parser_context_t* c, pd_JunctionV0_V16_t* v);
parser_error_t _readJunctionV1X1_V16(parser_context_t* c, pd_JunctionV1X1_V16_t* v);
parser_error_t _readJunctionV1X2_V16(parser_context_t* c, pd_JunctionV1X2_V16_t* v);
parser_error_t _readJunctionV1X3_V16(parser_context_t* c, pd_JunctionV1X3_V16_t* v);
parser_error_t _readJunctionV1_V16(parser_context_t* c, pd_JunctionV1_V16_t* v);
parser_error_t _readJunctionsV0_V16(parser_context_t* c, pd_JunctionsV0_V16_t* v);
parser_error_t _readJunctionsV1_V16(parser_context_t* c, pd_JunctionsV1_V16_t* v);
parser_error_t _readKeys_V16(parser_context_t* c, pd_Keys_V16_t* v);
parser_error_t _readLeasePeriod_V16(parser_context_t* c, pd_LeasePeriod_V16_t* v);
parser_error_t _readLookupasStaticLookupSource_V16(parser_context_t* c, pd_LookupasStaticLookupSource_V16_t* v);
parser_error_t _readMarketBalanceOfT_V16(parser_context_t* c, pd_MarketBalanceOfT_V16_t* v);
parser_error_t _readMarketState_V16(parser_context_t* c, pd_MarketState_V16_t* v);
parser_error_t _readMemberCount_V16(parser_context_t* c, pd_MemberCount_V16_t* v);
parser_error_t _readMultiLocationV0_V16(parser_context_t* c, pd_MultiLocationV0_V16_t* v);
parser_error_t _readMultiLocationV1_V16(parser_context_t* c, pd_MultiLocationV1_V16_t* v);
parser_error_t _readNetworkId_V16(parser_context_t* c, pd_NetworkId_V16_t* v);
parser_error_t _readOpaqueCall_V16(parser_context_t* c, pd_OpaqueCall_V16_t* v);
parser_error_t _readOptionAccountId_V16(parser_context_t* c, pd_OptionAccountId_V16_t* v);
parser_error_t _readOptionContributionStrategy_V16(parser_context_t* c, pd_OptionContributionStrategy_V16_t* v);
parser_error_t _readOptionProxyType_V16(parser_context_t* c, pd_OptionProxyType_V16_t* v);
parser_error_t _readOptionRate_V16(parser_context_t* c, pd_OptionRate_V16_t* v);
parser_error_t _readOptionRatio_V16(parser_context_t* c, pd_OptionRatio_V16_t* v);
parser_error_t _readOptionTimepoint_V16(parser_context_t* c, pd_OptionTimepoint_V16_t* v);
parser_error_t _readOverweightIndex_V16(parser_context_t* c, pd_OverweightIndex_V16_t* v);
parser_error_t _readParaId_V16(parser_context_t* c, pd_ParaId_V16_t* v);
parser_error_t _readPerbill_V16(parser_context_t* c, pd_Perbill_V16_t* v);
parser_error_t _readPlurality_V16(parser_context_t* c, pd_Plurality_V16_t* v);
parser_error_t _readPrice_V16(parser_context_t* c, pd_Price_V16_t* v);
parser_error_t _readProxyType_V16(parser_context_t* c, pd_ProxyType_V16_t* v);
parser_error_t _readRate_V16(parser_context_t* c, pd_Rate_V16_t* v);
parser_error_t _readRatio_V16(parser_context_t* c, pd_Ratio_V16_t* v);
parser_error_t _readReferendumIndex_V16(parser_context_t* c, pd_ReferendumIndex_V16_t* v);
parser_error_t _readRegistrarIndex_V16(parser_context_t* c, pd_RegistrarIndex_V16_t* v);
parser_error_t _readRewardDestination_V16(parser_context_t* c, pd_RewardDestination_V16_t* v);
parser_error_t _readStakingLedgerAccountIdBalanceOfT_V16(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V16_t* v);
parser_error_t _readTeleAccount_V16(parser_context_t* c, pd_TeleAccount_V16_t* v);
parser_error_t _readTimepoint_V16(parser_context_t* c, pd_Timepoint_V16_t* v);
parser_error_t _readUnlockChunk_V16(parser_context_t* c, pd_UnlockChunk_V16_t* v);
parser_error_t _readVecAccountId_V16(parser_context_t* c, pd_VecAccountId_V16_t* v);
parser_error_t _readVecAssetIdOf_V16(parser_context_t* c, pd_VecAssetIdOf_V16_t* v);
parser_error_t _readVecEraIndex_V16(parser_context_t* c, pd_VecEraIndex_V16_t* v);
parser_error_t _readVecUnlockChunk_V16(parser_context_t* c, pd_VecUnlockChunk_V16_t* v);
parser_error_t _readVecVestingScheduleOf_V16(parser_context_t* c, pd_VecVestingScheduleOf_V16_t* v);
parser_error_t _readVestingScheduleOf_V16(parser_context_t* c, pd_VestingScheduleOf_V16_t* v);
parser_error_t _readWeight_V16(parser_context_t* c, pd_Weight_V16_t* v);
parser_error_t _readu8_array_32_V16(parser_context_t* c, pd_u8_array_32_V16_t* v);

// toString functions
parser_error_t _toStringAccountId32_V16(
    const pd_AccountId32_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V16(
    const pd_AccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V16(
    const pd_AccountIndex64_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V16(
    const pd_AccountKey20_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfAssetIdOf_V16(
    const pd_AssetIdOfAssetIdOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfT_V16(
    const pd_AssetIdOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOf_V16(
    const pd_AssetIdOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfBalanceOf_V16(
    const pd_BalanceOfBalanceOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V16(
    const pd_BodyId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V16(
    const pd_BodyPart_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V16(
    const pd_BoxVersionedMultiLocation_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeToken_V16(
    const pd_BridgeToken_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeType_V16(
    const pd_BridgeType_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V16(
    const pd_CallHashOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainId_V16(
    const pd_ChainId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainNonce_V16(
    const pd_ChainNonce_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChildStorageKind_V16(
    const pd_ChildStorageKind_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V16(
    const pd_CompactAccountIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringContributionStrategy_V16(
    const pd_ContributionStrategy_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V16(
    const pd_Conviction_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V16(
    const pd_CurrencyId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurveModel_V16(
    const pd_CurveModel_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDerivativeIndex_V16(
    const pd_DerivativeIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V16(
    const pd_DestroyWitness_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V16(
    const pd_EraIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V16(
    const pd_Fraction_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInterestRateModel_V16(
    const pd_InterestRateModel_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJumpModel_V16(
    const pd_JumpModel_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1_V16(
    const pd_JunctionV0X1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2_V16(
    const pd_JunctionV0X2_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3_V16(
    const pd_JunctionV0X3_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0_V16(
    const pd_JunctionV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1_V16(
    const pd_JunctionV1X1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2_V16(
    const pd_JunctionV1X2_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3_V16(
    const pd_JunctionV1X3_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1_V16(
    const pd_JunctionV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0_V16(
    const pd_JunctionsV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1_V16(
    const pd_JunctionsV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V16(
    const pd_Keys_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriod_V16(
    const pd_LeasePeriod_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V16(
    const pd_LookupasStaticLookupSource_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketBalanceOfT_V16(
    const pd_MarketBalanceOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketState_V16(
    const pd_MarketState_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V16(
    const pd_MemberCount_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V16(
    const pd_MultiLocationV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V16(
    const pd_MultiLocationV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V16(
    const pd_NetworkId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V16(
    const pd_OpaqueCall_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V16(
    const pd_OptionAccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionContributionStrategy_V16(
    const pd_OptionContributionStrategy_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V16(
    const pd_OptionProxyType_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRate_V16(
    const pd_OptionRate_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRatio_V16(
    const pd_OptionRatio_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V16(
    const pd_OptionTimepoint_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V16(
    const pd_OverweightIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V16(
    const pd_ParaId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V16(
    const pd_Perbill_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V16(
    const pd_Plurality_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPrice_V16(
    const pd_Price_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V16(
    const pd_ProxyType_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRate_V16(
    const pd_Rate_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRatio_V16(
    const pd_Ratio_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V16(
    const pd_ReferendumIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V16(
    const pd_RegistrarIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V16(
    const pd_RewardDestination_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V16(
    const pd_StakingLedgerAccountIdBalanceOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTeleAccount_V16(
    const pd_TeleAccount_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V16(
    const pd_Timepoint_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUnlockChunk_V16(
    const pd_UnlockChunk_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V16(
    const pd_VecAccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdOf_V16(
    const pd_VecAssetIdOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecEraIndex_V16(
    const pd_VecEraIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecUnlockChunk_V16(
    const pd_VecUnlockChunk_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V16(
    const pd_VecVestingScheduleOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V16(
    const pd_VestingScheduleOf_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V16(
    const pd_Weight_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V16(
    const pd_u8_array_32_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
