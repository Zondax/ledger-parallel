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
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V15.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V15(parser_context_t* c, pd_AccountId_V15_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAssetIdOfAssetIdOf_V15(parser_context_t* c, pd_AssetIdOfAssetIdOf_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetIdOf_V15(c, &v->assetid1))
    CHECK_ERROR(_readAssetIdOf_V15(c, &v->assetid2))
    return parser_ok;
}

parser_error_t _readAssetIdOfT_V15(parser_context_t* c, pd_AssetIdOfT_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetIdOf_V15(parser_context_t* c, pd_AssetIdOf_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readBalanceOfBalanceOf_V15(parser_context_t* c, pd_BalanceOfBalanceOf_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBalance(c, &v->balance1))
    CHECK_ERROR(_readBalance(c, &v->balance2))
    return parser_ok;
}

parser_error_t _readBridgeToken_V15(parser_context_t* c, pd_BridgeToken_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCurrencyId_V15(c, &v->id))
    CHECK_ERROR(_readbool(c, &v->external))
    CHECK_ERROR(_readBalance(c, &v->fee))
    CHECK_ERROR(_readbool(c, &v->enable))
    CHECK_ERROR(_readBalance(c, &v->outCap))
    CHECK_ERROR(_readBalance(c, &v->outAmount))
    CHECK_ERROR(_readBalance(c, &v->inCap))
    CHECK_ERROR(_readBalance(c, &v->inAmount))
    return parser_ok;
}

parser_error_t _readBridgeType_V15(parser_context_t* c, pd_BridgeType_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readCallHashOf_V15(parser_context_t* c, pd_CallHashOf_V15_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChainId_V15(parser_context_t* c, pd_ChainId_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readChainNonce_V15(parser_context_t* c, pd_ChainNonce_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V15(parser_context_t* c, pd_CompactAccountIndex_V15_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConviction_V15(parser_context_t* c, pd_Conviction_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readCurrencyId_V15(parser_context_t* c, pd_CurrencyId_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readCurveModel_V15(parser_context_t* c, pd_CurveModel_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRate_V15(c, &v->baseRate))
    return parser_ok;
}

parser_error_t _readDerivativeIndex_V15(parser_context_t* c, pd_DerivativeIndex_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readDestroyWitness_V15(parser_context_t* c, pd_DestroyWitness_V15_t* v)
{
    CHECK_ERROR(_readCompactu32(c, &v->accounts))
    CHECK_ERROR(_readCompactu32(c, &v->sufficients))
    CHECK_ERROR(_readCompactu32(c, &v->approvals))
    return parser_ok;
}

parser_error_t _readEraIndex_V15(parser_context_t* c, pd_EraIndex_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readInterestRateModel_V15(parser_context_t* c, pd_InterestRateModel_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readJumpModel_V15(c, &v->jump))
        break;
    case 1:
        CHECK_ERROR(_readCurveModel_V15(c, &v->curve))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJumpModel_V15(parser_context_t* c, pd_JumpModel_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRate_V15(c, &v->baseRate))
    CHECK_ERROR(_readRate_V15(c, &v->jumpRate))
    CHECK_ERROR(_readRate_V15(c, &v->fullRate))
    CHECK_ERROR(_readRatio_V15(c, &v->jumpUtilization))
    return parser_ok;
}

parser_error_t _readKeys_V15(parser_context_t* c, pd_Keys_V15_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLookupasStaticLookupSource_V15(parser_context_t* c, pd_LookupasStaticLookupSource_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V15(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V15(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMarketBalanceOfT_V15(parser_context_t* c, pd_MarketBalanceOfT_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRatio_V15(c, &v->collateralFactor))
    CHECK_ERROR(_readRatio_V15(c, &v->liquidationThreshold))
    CHECK_ERROR(_readRatio_V15(c, &v->reserveFactor))
    CHECK_ERROR(_readRatio_V15(c, &v->closeFactor))
    CHECK_ERROR(_readRate_V15(c, &v->liquidateIncentive))
    CHECK_ERROR(_readRatio_V15(c, &v->liquidateIncentiveReservedFactor))
    CHECK_ERROR(_readInterestRateModel_V15(c, &v->rateModel))
    CHECK_ERROR(_readMarketState_V15(c, &v->state))
    CHECK_ERROR(_readBalance(c, &v->supplyCap))
    CHECK_ERROR(_readBalance(c, &v->borrowCap))
    CHECK_ERROR(_readCurrencyId_V15(c, &v->ptokenId))
    return parser_ok;
}

parser_error_t _readMarketState_V15(parser_context_t* c, pd_MarketState_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readMemberCount_V15(parser_context_t* c, pd_MemberCount_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readOpaqueCall_V15(parser_context_t* c, pd_OpaqueCall_V15_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readPerbill_V15(parser_context_t* c, pd_Perbill_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPrice_V15(parser_context_t* c, pd_Price_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readProxyType_V15(parser_context_t* c, pd_ProxyType_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readRate_V15(parser_context_t* c, pd_Rate_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readRatio_V15(parser_context_t* c, pd_Ratio_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readReferendumIndex_V15(parser_context_t* c, pd_ReferendumIndex_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V15(parser_context_t* c, pd_RegistrarIndex_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRewardDestination_V15(parser_context_t* c, pd_RewardDestination_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId_V15(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readStakingLedgerAccountIdBalanceOfT_V15(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId_V15(c, &v->stash))
    CHECK_ERROR(_readCompactu128(c, &v->total))
    CHECK_ERROR(_readCompactu128(c, &v->active))
    CHECK_ERROR(_readVecUnlockChunk_V15(c, &v->unlocking))
    CHECK_ERROR(_readVecEraIndex_V15(c, &v->claimedRewards))
    return parser_ok;
}

parser_error_t _readTeleAccount_V15(parser_context_t* c, pd_TeleAccount_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTimepoint_V15(parser_context_t* c, pd_Timepoint_V15_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readUnlockChunk_V15(parser_context_t* c, pd_UnlockChunk_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->value))
    CHECK_ERROR(_readCompactu32(c, &v->era))
    return parser_ok;
}

parser_error_t _readVestingScheduleOf_V15(parser_context_t* c, pd_VestingScheduleOf_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBlockNumber(c, &v->start))
    CHECK_ERROR(_readBlockNumber(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->periodCount))
    CHECK_ERROR(_readCompactu128(c, &v->perPeriod));
    return parser_ok;
}

parser_error_t _readWeight_V15(parser_context_t* c, pd_Weight_V15_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readVecAccountId_V15(parser_context_t* c, pd_VecAccountId_V15_t* v) {
    GEN_DEF_READVECTOR(AccountId_V15)
}

parser_error_t _readVecAssetIdOf_V15(parser_context_t* c, pd_VecAssetIdOf_V15_t* v) {
    GEN_DEF_READVECTOR(AssetIdOf_V15)
}

parser_error_t _readVecEraIndex_V15(parser_context_t* c, pd_VecEraIndex_V15_t* v) {
    GEN_DEF_READVECTOR(EraIndex_V15)
}

parser_error_t _readVecUnlockChunk_V15(parser_context_t* c, pd_VecUnlockChunk_V15_t* v) {
    GEN_DEF_READVECTOR(UnlockChunk_V15)
}

parser_error_t _readVecVestingScheduleOf_V15(parser_context_t* c, pd_VecVestingScheduleOf_V15_t* v) {
    GEN_DEF_READVECTOR(VestingScheduleOf_V15)
}

parser_error_t _readOptionAccountId_V15(parser_context_t* c, pd_OptionAccountId_V15_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V15(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V15(parser_context_t* c, pd_OptionProxyType_V15_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V15(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V15(parser_context_t* c, pd_OptionTimepoint_V15_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V15(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V15(
    const pd_AccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdOfAssetIdOf_V15(
    const pd_AssetIdOfAssetIdOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetIdOf_V15(&v->assetid1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetIdOf_V15(&v->assetid2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetIdOf_V15(&v->assetid1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetIdOf_V15(&v->assetid2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetIdOfT_V15(
    const pd_AssetIdOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdOf_V15(
    const pd_AssetIdOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBalanceOfBalanceOf_V15(
    const pd_BalanceOfBalanceOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBalance(&v->balance1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalance(&v->balance1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->balance2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBridgeToken_V15(
    const pd_BridgeToken_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringCurrencyId_V15(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->external, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->fee, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->enable, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringBalance(&v->outCap, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringBalance(&v->outAmount, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringBalance(&v->inCap, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringBalance(&v->inAmount, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCurrencyId_V15(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->external, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->fee, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringbool(&v->enable, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringBalance(&v->outCap, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringBalance(&v->outAmount, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringBalance(&v->inCap, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringBalance(&v->inAmount, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBridgeType_V15(
    const pd_BridgeType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "BridgeOut");
        break;
    case 1:
        snprintf(outValue, outValueLen, "BridgeIn");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringCallHashOf_V15(
    const pd_CallHashOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChainId_V15(
    const pd_ChainId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChainNonce_V15(
    const pd_ChainNonce_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactAccountIndex_V15(
    const pd_CompactAccountIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConviction_V15(
    const pd_Conviction_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "None");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Locked1x");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Locked2x");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Locked3x");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Locked4x");
        break;
    case 5:
        snprintf(outValue, outValueLen, "Locked5x");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringCurrencyId_V15(
    const pd_CurrencyId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurveModel_V15(
    const pd_CurveModel_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringRate_V15(&v->baseRate, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringDerivativeIndex_V15(
    const pd_DerivativeIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDestroyWitness_V15(
    const pd_DestroyWitness_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->accounts, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->sufficients, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu32(&v->approvals, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->accounts, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->sufficients, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu32(&v->approvals, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEraIndex_V15(
    const pd_EraIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringInterestRateModel_V15(
    const pd_InterestRateModel_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringJumpModel_V15(&v->jump, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        CHECK_ERROR(_toStringCurveModel_V15(&v->curve, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJumpModel_V15(
    const pd_JumpModel_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringRate_V15(&v->baseRate, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRate_V15(&v->jumpRate, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringRate_V15(&v->fullRate, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringRatio_V15(&v->jumpUtilization, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringRate_V15(&v->baseRate, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRate_V15(&v->jumpRate, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringRate_V15(&v->fullRate, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringRatio_V15(&v->jumpUtilization, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringKeys_V15(
    const pd_Keys_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLookupasStaticLookupSource_V15(
    const pd_LookupasStaticLookupSource_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V15(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V15(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMarketBalanceOfT_V15(
    const pd_MarketBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[11] = { 0 };
    CHECK_ERROR(_toStringRatio_V15(&v->collateralFactor, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRatio_V15(&v->liquidationThreshold, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringRatio_V15(&v->reserveFactor, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringRatio_V15(&v->closeFactor, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringRate_V15(&v->liquidateIncentive, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringRatio_V15(&v->liquidateIncentiveReservedFactor, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringInterestRateModel_V15(&v->rateModel, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringMarketState_V15(&v->state, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringBalance(&v->supplyCap, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringBalance(&v->borrowCap, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringCurrencyId_V15(&v->ptokenId, outValue, outValueLen, 0, &pages[10]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringRatio_V15(&v->collateralFactor, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRatio_V15(&v->liquidationThreshold, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringRatio_V15(&v->reserveFactor, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringRatio_V15(&v->closeFactor, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringRate_V15(&v->liquidateIncentive, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringRatio_V15(&v->liquidateIncentiveReservedFactor, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringInterestRateModel_V15(&v->rateModel, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringMarketState_V15(&v->state, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringBalance(&v->supplyCap, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringBalance(&v->borrowCap, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringCurrencyId_V15(&v->ptokenId, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMarketState_V15(
    const pd_MarketState_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Active");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Pending");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Supervision");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringMemberCount_V15(
    const pd_MemberCount_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOpaqueCall_V15(
    const pd_OpaqueCall_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPerbill_V15(
    const pd_Perbill_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPrice_V15(
    const pd_Price_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringProxyType_V15(
    const pd_ProxyType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Loans");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Staking");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Crowdloans");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Farming");
        break;
    default:
        return parser_print_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringRate_V15(
    const pd_Rate_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringRatio_V15(
    const pd_Ratio_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringReferendumIndex_V15(
    const pd_ReferendumIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V15(
    const pd_RegistrarIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRewardDestination_V15(
    const pd_RewardDestination_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Staked");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Stash");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Controller");
        break;
    case 3:
        CHECK_ERROR(_toStringAccountId_V15(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V15(
    const pd_StakingLedgerAccountIdBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringAccountId_V15(&v->stash, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->total, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu128(&v->active, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringVecUnlockChunk_V15(&v->unlocking, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringVecEraIndex_V15(&v->claimedRewards, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId_V15(&v->stash, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->total, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu128(&v->active, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringVecUnlockChunk_V15(&v->unlocking, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringVecEraIndex_V15(&v->claimedRewards, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTeleAccount_V15(
    const pd_TeleAccount_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringVecu8(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTimepoint_V15(
    const pd_Timepoint_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUnlockChunk_V15(
    const pd_UnlockChunk_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->value, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->era, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu128(&v->value, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->era, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVestingScheduleOf_V15(
    const pd_VestingScheduleOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringBlockNumber(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBlockNumber(&v->period, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->periodCount, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringCompactu128(&v->perPeriod, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBlockNumber(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->periodCount, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringCompactu128(&v->perPeriod, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringWeight_V15(
    const pd_Weight_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountId_V15(
    const pd_VecAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V15);
}

parser_error_t _toStringVecAssetIdOf_V15(
    const pd_VecAssetIdOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdOf_V15);
}

parser_error_t _toStringVecEraIndex_V15(
    const pd_VecEraIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(EraIndex_V15);
}

parser_error_t _toStringVecUnlockChunk_V15(
    const pd_VecUnlockChunk_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(UnlockChunk_V15);
}

parser_error_t _toStringVecVestingScheduleOf_V15(
    const pd_VecVestingScheduleOf_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VestingScheduleOf_V15);
}

parser_error_t _toStringOptionAccountId_V15(
    const pd_OptionAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V15(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V15(
    const pd_OptionProxyType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V15(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V15(
    const pd_OptionTimepoint_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V15(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
