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
#include "substrate_methods_V15.h"
#include "substrate_types_V15.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V15(parser_context_t* c, pd_AccountId_V15_t* v);
parser_error_t _readAssetIdOfAssetIdOf_V15(parser_context_t* c, pd_AssetIdOfAssetIdOf_V15_t* v);
parser_error_t _readAssetIdOfT_V15(parser_context_t* c, pd_AssetIdOfT_V15_t* v);
parser_error_t _readAssetIdOf_V15(parser_context_t* c, pd_AssetIdOf_V15_t* v);
parser_error_t _readBalanceOfBalanceOf_V15(parser_context_t* c, pd_BalanceOfBalanceOf_V15_t* v);
parser_error_t _readBridgeToken_V15(parser_context_t* c, pd_BridgeToken_V15_t* v);
parser_error_t _readBridgeType_V15(parser_context_t* c, pd_BridgeType_V15_t* v);
parser_error_t _readCallHashOf_V15(parser_context_t* c, pd_CallHashOf_V15_t* v);
parser_error_t _readChainId_V15(parser_context_t* c, pd_ChainId_V15_t* v);
parser_error_t _readChainNonce_V15(parser_context_t* c, pd_ChainNonce_V15_t* v);
parser_error_t _readCompactAccountIndex_V15(parser_context_t* c, pd_CompactAccountIndex_V15_t* v);
parser_error_t _readConviction_V15(parser_context_t* c, pd_Conviction_V15_t* v);
parser_error_t _readCurrencyId_V15(parser_context_t* c, pd_CurrencyId_V15_t* v);
parser_error_t _readCurveModel_V15(parser_context_t* c, pd_CurveModel_V15_t* v);
parser_error_t _readDerivativeIndex_V15(parser_context_t* c, pd_DerivativeIndex_V15_t* v);
parser_error_t _readDestroyWitness_V15(parser_context_t* c, pd_DestroyWitness_V15_t* v);
parser_error_t _readEraIndex_V15(parser_context_t* c, pd_EraIndex_V15_t* v);
parser_error_t _readInterestRateModel_V15(parser_context_t* c, pd_InterestRateModel_V15_t* v);
parser_error_t _readJumpModel_V15(parser_context_t* c, pd_JumpModel_V15_t* v);
parser_error_t _readKeys_V15(parser_context_t* c, pd_Keys_V15_t* v);
parser_error_t _readLookupasStaticLookupSource_V15(parser_context_t* c, pd_LookupasStaticLookupSource_V15_t* v);
parser_error_t _readMarketBalanceOfT_V15(parser_context_t* c, pd_MarketBalanceOfT_V15_t* v);
parser_error_t _readMarketState_V15(parser_context_t* c, pd_MarketState_V15_t* v);
parser_error_t _readMemberCount_V15(parser_context_t* c, pd_MemberCount_V15_t* v);
parser_error_t _readOpaqueCall_V15(parser_context_t* c, pd_OpaqueCall_V15_t* v);
parser_error_t _readOptionAccountId_V15(parser_context_t* c, pd_OptionAccountId_V15_t* v);
parser_error_t _readOptionProxyType_V15(parser_context_t* c, pd_OptionProxyType_V15_t* v);
parser_error_t _readOptionTimepoint_V15(parser_context_t* c, pd_OptionTimepoint_V15_t* v);
parser_error_t _readPerbill_V15(parser_context_t* c, pd_Perbill_V15_t* v);
parser_error_t _readPrice_V15(parser_context_t* c, pd_Price_V15_t* v);
parser_error_t _readProxyType_V15(parser_context_t* c, pd_ProxyType_V15_t* v);
parser_error_t _readRate_V15(parser_context_t* c, pd_Rate_V15_t* v);
parser_error_t _readRatio_V15(parser_context_t* c, pd_Ratio_V15_t* v);
parser_error_t _readReferendumIndex_V15(parser_context_t* c, pd_ReferendumIndex_V15_t* v);
parser_error_t _readRegistrarIndex_V15(parser_context_t* c, pd_RegistrarIndex_V15_t* v);
parser_error_t _readRewardDestination_V15(parser_context_t* c, pd_RewardDestination_V15_t* v);
parser_error_t _readStakingLedgerAccountIdBalanceOfT_V15(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V15_t* v);
parser_error_t _readTeleAccount_V15(parser_context_t* c, pd_TeleAccount_V15_t* v);
parser_error_t _readTimepoint_V15(parser_context_t* c, pd_Timepoint_V15_t* v);
parser_error_t _readUnlockChunk_V15(parser_context_t* c, pd_UnlockChunk_V15_t* v);
parser_error_t _readVecAccountId_V15(parser_context_t* c, pd_VecAccountId_V15_t* v);
parser_error_t _readVecAssetIdOf_V15(parser_context_t* c, pd_VecAssetIdOf_V15_t* v);
parser_error_t _readVecEraIndex_V15(parser_context_t* c, pd_VecEraIndex_V15_t* v);
parser_error_t _readVecUnlockChunk_V15(parser_context_t* c, pd_VecUnlockChunk_V15_t* v);
parser_error_t _readVecVestingScheduleOf_V15(parser_context_t* c, pd_VecVestingScheduleOf_V15_t* v);
parser_error_t _readVestingScheduleOf_V15(parser_context_t* c, pd_VestingScheduleOf_V15_t* v);
parser_error_t _readWeight_V15(parser_context_t* c, pd_Weight_V15_t* v);

// toString functions
parser_error_t _toStringAccountId_V15(
    const pd_AccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfAssetIdOf_V15(
    const pd_AssetIdOfAssetIdOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfT_V15(
    const pd_AssetIdOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOf_V15(
    const pd_AssetIdOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfBalanceOf_V15(
    const pd_BalanceOfBalanceOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeToken_V15(
    const pd_BridgeToken_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeType_V15(
    const pd_BridgeType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V15(
    const pd_CallHashOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainId_V15(
    const pd_ChainId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainNonce_V15(
    const pd_ChainNonce_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V15(
    const pd_CompactAccountIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V15(
    const pd_Conviction_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V15(
    const pd_CurrencyId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurveModel_V15(
    const pd_CurveModel_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDerivativeIndex_V15(
    const pd_DerivativeIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V15(
    const pd_DestroyWitness_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V15(
    const pd_EraIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInterestRateModel_V15(
    const pd_InterestRateModel_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJumpModel_V15(
    const pd_JumpModel_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V15(
    const pd_Keys_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V15(
    const pd_LookupasStaticLookupSource_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketBalanceOfT_V15(
    const pd_MarketBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketState_V15(
    const pd_MarketState_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V15(
    const pd_MemberCount_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V15(
    const pd_OpaqueCall_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V15(
    const pd_OptionAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V15(
    const pd_OptionProxyType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V15(
    const pd_OptionTimepoint_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V15(
    const pd_Perbill_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPrice_V15(
    const pd_Price_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V15(
    const pd_ProxyType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRate_V15(
    const pd_Rate_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRatio_V15(
    const pd_Ratio_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V15(
    const pd_ReferendumIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V15(
    const pd_RegistrarIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V15(
    const pd_RewardDestination_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V15(
    const pd_StakingLedgerAccountIdBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTeleAccount_V15(
    const pd_TeleAccount_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V15(
    const pd_Timepoint_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUnlockChunk_V15(
    const pd_UnlockChunk_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V15(
    const pd_VecAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdOf_V15(
    const pd_VecAssetIdOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecEraIndex_V15(
    const pd_VecEraIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecUnlockChunk_V15(
    const pd_VecUnlockChunk_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V15(
    const pd_VecVestingScheduleOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V15(
    const pd_VestingScheduleOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V15(
    const pd_Weight_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
