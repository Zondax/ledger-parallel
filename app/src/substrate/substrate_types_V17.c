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
#include "substrate_dispatch_V17.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId32_V17(parser_context_t* c, pd_AccountId32_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V17(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32_V17(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountId_V17(parser_context_t* c, pd_AccountId_V17_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex64_V17(parser_context_t* c, pd_AccountIndex64_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V17(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountKey20_V17(parser_context_t* c, pd_AccountKey20_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V17(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readAssetIdOfAssetIdOf_V17(parser_context_t* c, pd_AssetIdOfAssetIdOf_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetIdOf_V17(c, &v->assetid1))
    CHECK_ERROR(_readAssetIdOf_V17(c, &v->assetid2))
    return parser_ok;
}

parser_error_t _readAssetIdOfT_V17(parser_context_t* c, pd_AssetIdOfT_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetIdOf_V17(parser_context_t* c, pd_AssetIdOf_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readBalanceOfBalanceOf_V17(parser_context_t* c, pd_BalanceOfBalanceOf_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBalance(c, &v->balance1))
    CHECK_ERROR(_readBalance(c, &v->balance2))
    return parser_ok;
}

parser_error_t _readBodyId_V17(parser_context_t* c, pd_BodyId_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unit
        break;
    case 1: // Named
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    case 2: // Index
        CHECK_ERROR(_readCompactu32(c, &v->index))
        break;
    case 3: // Executive
    case 4: // Technical
    case 5: // Legislative
    case 6: // Judicial
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBodyPart_V17(parser_context_t* c, pd_BodyPart_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Voice
        break;
    case 1: // Members
        CHECK_ERROR(_readCompactu32(c, &v->count))
        break;
    case 2: // Fraction
    case 3: // AtleastProportion
    case 4: // MoreThanProportion
        CHECK_ERROR(_readFraction_V17(c, &v->fraction))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoxVersionedMultiLocation_V17(parser_context_t* c, pd_BoxVersionedMultiLocation_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiLocationV0_V17(c, &v->multilocationV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiLocationV1_V17(c, &v->multilocationV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBridgeToken_V17(parser_context_t* c, pd_BridgeToken_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCurrencyId_V17(c, &v->id))
    CHECK_ERROR(_readbool(c, &v->external))
    CHECK_ERROR(_readBalance(c, &v->fee))
    CHECK_ERROR(_readbool(c, &v->enable))
    CHECK_ERROR(_readBalance(c, &v->outCap))
    CHECK_ERROR(_readBalance(c, &v->outAmount))
    CHECK_ERROR(_readBalance(c, &v->inCap))
    CHECK_ERROR(_readBalance(c, &v->inAmount))
    return parser_ok;
}

parser_error_t _readBridgeType_V17(parser_context_t* c, pd_BridgeType_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readCallHashOf_V17(parser_context_t* c, pd_CallHashOf_V17_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChainId_V17(parser_context_t* c, pd_ChainId_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readChainNonce_V17(parser_context_t* c, pd_ChainNonce_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readChildStorageKind_V17(parser_context_t* c, pd_ChildStorageKind_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V17(parser_context_t* c, pd_CompactAccountIndex_V17_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readContributionStrategy_V17(parser_context_t* c, pd_ContributionStrategy_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 0) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readConviction_V17(parser_context_t* c, pd_Conviction_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readCurrencyId_V17(parser_context_t* c, pd_CurrencyId_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readCurveModel_V17(parser_context_t* c, pd_CurveModel_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRate_V17(c, &v->baseRate))
    return parser_ok;
}

parser_error_t _readDerivativeIndex_V17(parser_context_t* c, pd_DerivativeIndex_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readDestroyWitness_V17(parser_context_t* c, pd_DestroyWitness_V17_t* v)
{
    CHECK_ERROR(_readCompactu32(c, &v->accounts))
    CHECK_ERROR(_readCompactu32(c, &v->sufficients))
    CHECK_ERROR(_readCompactu32(c, &v->approvals))
    return parser_ok;
}

parser_error_t _readEraIndex_V17(parser_context_t* c, pd_EraIndex_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readFraction_V17(parser_context_t* c, pd_Fraction_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->nom))
    CHECK_ERROR(_readCompactu32(c, &v->denom))
    return parser_ok;
}

parser_error_t _readInterestRateModel_V17(parser_context_t* c, pd_InterestRateModel_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readJumpModel_V17(c, &v->jump))
        break;
    case 1:
        CHECK_ERROR(_readCurveModel_V17(c, &v->curve))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJumpModel_V17(parser_context_t* c, pd_JumpModel_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRate_V17(c, &v->baseRate))
    CHECK_ERROR(_readRate_V17(c, &v->jumpRate))
    CHECK_ERROR(_readRate_V17(c, &v->fullRate))
    CHECK_ERROR(_readRatio_V17(c, &v->jumpUtilization))
    return parser_ok;
}

parser_error_t _readJunctionV0X1_V17(parser_context_t* c, pd_JunctionV0X1_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV0X2_V17(parser_context_t* c, pd_JunctionV0X2_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV0X3_V17(parser_context_t* c, pd_JunctionV0X3_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV0X4_V17(parser_context_t* c, pd_JunctionV0X4_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV0X5_V17(parser_context_t* c, pd_JunctionV0X5_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV0X6_V17(parser_context_t* c, pd_JunctionV0X6_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV0X7_V17(parser_context_t* c, pd_JunctionV0X7_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction5))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV0X8_V17(parser_context_t* c, pd_JunctionV0X8_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction5))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction6))
    CHECK_ERROR(_readJunctionV0_V17(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionV0_V17(parser_context_t* c, pd_JunctionV0_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parent
        break;
    case 1: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_readAccountId32_V17(c, &v->accountId32))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64_V17(c, &v->accountIndex64))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_readAccountKey20_V17(c, &v->accountKey20))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 8: // OnlyChild
        break;
    case 9: // Plurality
        CHECK_ERROR(_readPlurality_V17(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionV1X1_V17(parser_context_t* c, pd_JunctionV1X1_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV1X2_V17(parser_context_t* c, pd_JunctionV1X2_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV1X3_V17(parser_context_t* c, pd_JunctionV1X3_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV1X4_V17(parser_context_t* c, pd_JunctionV1X4_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV1X5_V17(parser_context_t* c, pd_JunctionV1X5_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV1X6_V17(parser_context_t* c, pd_JunctionV1X6_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV1X7_V17(parser_context_t* c, pd_JunctionV1X7_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction5))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV1X8_V17(parser_context_t* c, pd_JunctionV1X8_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction5))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction6))
    CHECK_ERROR(_readJunctionV1_V17(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionV1_V17(parser_context_t* c, pd_JunctionV1_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_readAccountId32_V17(c, &v->accountId32))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64_V17(c, &v->accountIndex64))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_readAccountKey20_V17(c, &v->accountKey20))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 7: // OnlyChild
        break;
    case 8: // Plurality
        CHECK_ERROR(_readPlurality_V17(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionsV0_V17(parser_context_t* c, pd_JunctionsV0_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Null
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV0X1_V17(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV0X2_V17(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV0X3_V17(c, &v->x3))
        break;
#ifdef JUNCTIONS_FULL
    case 4: // X4
        CHECK_ERROR(_readJunctionV0X4_V17(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV0X5_V17(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV0X6_V17(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV0X7_V17(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV0X8_V17(c, &v->x8))
        break;
#else
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return parser_junction_limit;
#endif
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionsV1_V17(parser_context_t* c, pd_JunctionsV1_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV1X1_V17(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV1X2_V17(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV1X3_V17(c, &v->x3))
        break;
#ifdef JUNCTIONS_FULL
    case 4: // X4
        CHECK_ERROR(_readJunctionV1X4_V17(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV1X5_V17(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV1X6_V17(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV1X7_V17(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV1X8_V17(c, &v->x8))
        break;
#else
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return parser_junction_limit;
#endif
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readKeys_V17(parser_context_t* c, pd_Keys_V17_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLeasePeriod_V17(parser_context_t* c, pd_LeasePeriod_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readLookupasStaticLookupSource_V17(parser_context_t* c, pd_LookupasStaticLookupSource_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V17(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V17(c, &v->index))
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

parser_error_t _readMarketBalanceOfT_V17(parser_context_t* c, pd_MarketBalanceOfT_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRatio_V17(c, &v->collateralFactor))
    CHECK_ERROR(_readRatio_V17(c, &v->liquidationThreshold))
    CHECK_ERROR(_readRatio_V17(c, &v->reserveFactor))
    CHECK_ERROR(_readRatio_V17(c, &v->closeFactor))
    CHECK_ERROR(_readRate_V17(c, &v->liquidateIncentive))
    CHECK_ERROR(_readRatio_V17(c, &v->liquidateIncentiveReservedFactor))
    CHECK_ERROR(_readInterestRateModel_V17(c, &v->rateModel))
    CHECK_ERROR(_readMarketState_V17(c, &v->state))
    CHECK_ERROR(_readBalance(c, &v->supplyCap))
    CHECK_ERROR(_readBalance(c, &v->borrowCap))
    CHECK_ERROR(_readCurrencyId_V17(c, &v->ptokenId))
    return parser_ok;
}

parser_error_t _readMarketState_V17(parser_context_t* c, pd_MarketState_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readMemberCount_V17(parser_context_t* c, pd_MemberCount_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMultiLocationV0_V17(parser_context_t* c, pd_MultiLocationV0_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionsV0_V17(c, &v->junctions))
    return parser_ok;
}

parser_error_t _readMultiLocationV1_V17(parser_context_t* c, pd_MultiLocationV1_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->parents))
    CHECK_ERROR(_readJunctionsV1_V17(c, &v->interior))
    return parser_ok;
}

parser_error_t _readNetworkId_V17(parser_context_t* c, pd_NetworkId_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Any
    case 2: // Polkadot
    case 3: // Kusama
        break;
    case 1: // Index
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOpaqueCall_V17(parser_context_t* c, pd_OpaqueCall_V17_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readOverweightIndex_V17(parser_context_t* c, pd_OverweightIndex_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readParaId_V17(parser_context_t* c, pd_ParaId_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPerbill_V17(parser_context_t* c, pd_Perbill_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPlurality_V17(parser_context_t* c, pd_Plurality_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyId_V17(c, &v->id))
    CHECK_ERROR(_readBodyPart_V17(c, &v->part))
    return parser_ok;
}

parser_error_t _readPrice_V17(parser_context_t* c, pd_Price_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readProxyType_V17(parser_context_t* c, pd_ProxyType_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readRate_V17(parser_context_t* c, pd_Rate_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readRatio_V17(parser_context_t* c, pd_Ratio_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readReferendumIndex_V17(parser_context_t* c, pd_ReferendumIndex_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V17(parser_context_t* c, pd_RegistrarIndex_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRewardDestination_V17(parser_context_t* c, pd_RewardDestination_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId_V17(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readStakingLedgerAccountIdBalanceOfT_V17(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId_V17(c, &v->stash))
    CHECK_ERROR(_readCompactu128(c, &v->total))
    CHECK_ERROR(_readCompactu128(c, &v->active))
    CHECK_ERROR(_readVecUnlockChunk_V17(c, &v->unlocking))
    CHECK_ERROR(_readVecEraIndex_V17(c, &v->claimedRewards))
    return parser_ok;
}

parser_error_t _readTeleAccount_V17(parser_context_t* c, pd_TeleAccount_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTimepoint_V17(parser_context_t* c, pd_Timepoint_V17_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readUnlockChunk_V17(parser_context_t* c, pd_UnlockChunk_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->value))
    CHECK_ERROR(_readCompactu32(c, &v->era))
    return parser_ok;
}

parser_error_t _readUnstakeProvider_V17(parser_context_t* c, pd_UnstakeProvider_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 1) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readVestingScheduleOf_V17(parser_context_t* c, pd_VestingScheduleOf_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBlockNumber(c, &v->start))
    CHECK_ERROR(_readBlockNumber(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->periodCount))
    CHECK_ERROR(_readCompactu128(c, &v->perPeriod));
    return parser_ok;
}

parser_error_t _readWeight_V17(parser_context_t* c, pd_Weight_V17_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readu8_array_32_V17(parser_context_t* c, pd_u8_array_32_V17_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountId_V17(parser_context_t* c, pd_VecAccountId_V17_t* v) {
    GEN_DEF_READVECTOR(AccountId_V17)
}

parser_error_t _readVecAssetIdOf_V17(parser_context_t* c, pd_VecAssetIdOf_V17_t* v) {
    GEN_DEF_READVECTOR(AssetIdOf_V17)
}

parser_error_t _readVecEraIndex_V17(parser_context_t* c, pd_VecEraIndex_V17_t* v) {
    GEN_DEF_READVECTOR(EraIndex_V17)
}

parser_error_t _readVecUnlockChunk_V17(parser_context_t* c, pd_VecUnlockChunk_V17_t* v) {
    GEN_DEF_READVECTOR(UnlockChunk_V17)
}

parser_error_t _readVecVestingScheduleOf_V17(parser_context_t* c, pd_VecVestingScheduleOf_V17_t* v) {
    GEN_DEF_READVECTOR(VestingScheduleOf_V17)
}

parser_error_t _readOptionAccountId_V17(parser_context_t* c, pd_OptionAccountId_V17_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V17(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionContributionStrategy_V17(parser_context_t* c, pd_OptionContributionStrategy_V17_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readContributionStrategy_V17(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V17(parser_context_t* c, pd_OptionProxyType_V17_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V17(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRate_V17(parser_context_t* c, pd_OptionRate_V17_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRate_V17(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRatio_V17(parser_context_t* c, pd_OptionRatio_V17_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRatio_V17(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V17(parser_context_t* c, pd_OptionTimepoint_V17_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V17(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId32_V17(
    const pd_AccountId32_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V17(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32_V17(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V17(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32_V17(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountId_V17(
    const pd_AccountId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex64_V17(
    const pd_AccountIndex64_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V17(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V17(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20_V17(
    const pd_AccountKey20_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V17(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V17(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetIdOfAssetIdOf_V17(
    const pd_AssetIdOfAssetIdOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetIdOf_V17(&v->assetid1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetIdOf_V17(&v->assetid2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetIdOf_V17(&v->assetid1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetIdOf_V17(&v->assetid2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetIdOfT_V17(
    const pd_AssetIdOfT_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdOf_V17(
    const pd_AssetIdOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBalanceOfBalanceOf_V17(
    const pd_BalanceOfBalanceOf_V17_t* v,
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

parser_error_t _toStringBodyId_V17(
    const pd_BodyId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Unit
        snprintf(outValue, outValueLen, "Unit");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Index
        CHECK_ERROR(_toStringCompactu32(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Executive
        snprintf(outValue, outValueLen, "Executive");
        break;
    case 4: // Technical
        snprintf(outValue, outValueLen, "Technical");
        break;
    case 5: // Legislative
        snprintf(outValue, outValueLen, "Legislative");
        break;
    case 6: // Judicial
        snprintf(outValue, outValueLen, "Judicial");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBodyPart_V17(
    const pd_BodyPart_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Voice
        snprintf(outValue, outValueLen, "Voice");
        break;
    case 1: // Members
        CHECK_ERROR(_toStringCompactu32(&v->count, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Fraction
        CHECK_ERROR(_toStringFraction_V17(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AtLeastProportion
        CHECK_ERROR(_toStringFraction_V17(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // MoreThanProportion
        CHECK_ERROR(_toStringFraction_V17(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiLocation_V17(
    const pd_BoxVersionedMultiLocation_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiLocationV0_V17(&v->multilocationV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiLocationV1_V17(&v->multilocationV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBridgeToken_V17(
    const pd_BridgeToken_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringCurrencyId_V17(&v->id, outValue, outValueLen, 0, &pages[0]))
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
        CHECK_ERROR(_toStringCurrencyId_V17(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringBridgeType_V17(
    const pd_BridgeType_V17_t* v,
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

parser_error_t _toStringCallHashOf_V17(
    const pd_CallHashOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChainId_V17(
    const pd_ChainId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChainNonce_V17(
    const pd_ChainNonce_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChildStorageKind_V17(
    const pd_ChildStorageKind_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Pending");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Flying");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Contributed");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringCompactAccountIndex_V17(
    const pd_CompactAccountIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringContributionStrategy_V17(
    const pd_ContributionStrategy_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // XCM
        snprintf(outValue, outValueLen, "XCM");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConviction_V17(
    const pd_Conviction_V17_t* v,
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

parser_error_t _toStringCurrencyId_V17(
    const pd_CurrencyId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurveModel_V17(
    const pd_CurveModel_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringRate_V17(&v->baseRate, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringDerivativeIndex_V17(
    const pd_DerivativeIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDestroyWitness_V17(
    const pd_DestroyWitness_V17_t* v,
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

parser_error_t _toStringEraIndex_V17(
    const pd_EraIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringFraction_V17(
    const pd_Fraction_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringInterestRateModel_V17(
    const pd_InterestRateModel_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringJumpModel_V17(&v->jump, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        CHECK_ERROR(_toStringCurveModel_V17(&v->curve, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJumpModel_V17(
    const pd_JumpModel_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringRate_V17(&v->baseRate, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRate_V17(&v->jumpRate, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringRate_V17(&v->fullRate, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringRatio_V17(&v->jumpUtilization, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringRate_V17(&v->baseRate, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRate_V17(&v->jumpRate, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringRate_V17(&v->fullRate, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringRatio_V17(&v->jumpUtilization, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X1_V17(
    const pd_JunctionV0X1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X2_V17(
    const pd_JunctionV0X2_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X3_V17(
    const pd_JunctionV0X3_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X4_V17(
    const pd_JunctionV0X4_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X5_V17(
    const pd_JunctionV0X5_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X6_V17(
    const pd_JunctionV0X6_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X7_V17(
    const pd_JunctionV0X7_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X8_V17(
    const pd_JunctionV0X8_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV0_V17(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV0_V17(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0_V17(
    const pd_JunctionV0_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parent
        snprintf(outValue, outValueLen, "Parent");
        break;
    case 1: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_toStringAccountId32_V17(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64_V17(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20_V17(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 9: // Plurality
        CHECK_ERROR(_toStringPlurality_V17(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionV1X1_V17(
    const pd_JunctionV1X1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X2_V17(
    const pd_JunctionV1X2_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X3_V17(
    const pd_JunctionV1X3_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X4_V17(
    const pd_JunctionV1X4_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X5_V17(
    const pd_JunctionV1X5_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X6_V17(
    const pd_JunctionV1X6_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X7_V17(
    const pd_JunctionV1X7_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X8_V17(
    const pd_JunctionV1X8_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV1_V17(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV1_V17(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1_V17(
    const pd_JunctionV1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_toStringAccountId32_V17(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64_V17(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20_V17(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 8: // Plurality
        CHECK_ERROR(_toStringPlurality_V17(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionsV0_V17(
    const pd_JunctionsV0_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Null
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Null");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV0X1_V17(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV0X2_V17(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV0X3_V17(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
#ifdef JUNCTIONS_FULL
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV0X4_V17(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV0X5_V17(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV0X6_V17(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV0X7_V17(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV0X8_V17(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
#else
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return parser_junction_limit;
#endif
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionsV1_V17(
    const pd_JunctionsV1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Here
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Here");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV1X1_V17(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV1X2_V17(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV1X3_V17(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
#ifdef JUNCTIONS_FULL
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV1X4_V17(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV1X5_V17(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV1X6_V17(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV1X7_V17(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV1X8_V17(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
#else
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return parser_junction_limit;
#endif
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringKeys_V17(
    const pd_Keys_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLeasePeriod_V17(
    const pd_LeasePeriod_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringLookupasStaticLookupSource_V17(
    const pd_LookupasStaticLookupSource_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V17(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V17(&v->index, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringMarketBalanceOfT_V17(
    const pd_MarketBalanceOfT_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[11] = { 0 };
    CHECK_ERROR(_toStringRatio_V17(&v->collateralFactor, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRatio_V17(&v->liquidationThreshold, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringRatio_V17(&v->reserveFactor, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringRatio_V17(&v->closeFactor, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringRate_V17(&v->liquidateIncentive, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringRatio_V17(&v->liquidateIncentiveReservedFactor, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringInterestRateModel_V17(&v->rateModel, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringMarketState_V17(&v->state, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringBalance(&v->supplyCap, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringBalance(&v->borrowCap, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringCurrencyId_V17(&v->ptokenId, outValue, outValueLen, 0, &pages[10]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringRatio_V17(&v->collateralFactor, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRatio_V17(&v->liquidationThreshold, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringRatio_V17(&v->reserveFactor, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringRatio_V17(&v->closeFactor, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringRate_V17(&v->liquidateIncentive, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringRatio_V17(&v->liquidateIncentiveReservedFactor, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringInterestRateModel_V17(&v->rateModel, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringMarketState_V17(&v->state, outValue, outValueLen, pageIdx, &pages[7]))
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
        CHECK_ERROR(_toStringCurrencyId_V17(&v->ptokenId, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMarketState_V17(
    const pd_MarketState_V17_t* v,
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

parser_error_t _toStringMemberCount_V17(
    const pd_MemberCount_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiLocationV0_V17(
    const pd_MultiLocationV0_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringJunctionsV0_V17(&v->junctions, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringMultiLocationV1_V17(
    const pd_MultiLocationV1_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionsV1_V17(&v->interior, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionsV1_V17(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNetworkId_V17(
    const pd_NetworkId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Any
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Polkadot
        snprintf(outValue, outValueLen, "Polkadot");
        break;
    case 3: // Kusama
        snprintf(outValue, outValueLen, "Kusama");
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOpaqueCall_V17(
    const pd_OpaqueCall_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex_V17(
    const pd_OverweightIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringParaId_V17(
    const pd_ParaId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPerbill_V17(
    const pd_Perbill_V17_t* v,
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

parser_error_t _toStringPlurality_V17(
    const pd_Plurality_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyId_V17(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart_V17(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyId_V17(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart_V17(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPrice_V17(
    const pd_Price_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringProxyType_V17(
    const pd_ProxyType_V17_t* v,
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

parser_error_t _toStringRate_V17(
    const pd_Rate_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringRatio_V17(
    const pd_Ratio_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringReferendumIndex_V17(
    const pd_ReferendumIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V17(
    const pd_RegistrarIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRewardDestination_V17(
    const pd_RewardDestination_V17_t* v,
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
        CHECK_ERROR(_toStringAccountId_V17(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V17(
    const pd_StakingLedgerAccountIdBalanceOfT_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringAccountId_V17(&v->stash, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->total, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu128(&v->active, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringVecUnlockChunk_V17(&v->unlocking, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringVecEraIndex_V17(&v->claimedRewards, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId_V17(&v->stash, outValue, outValueLen, pageIdx, &pages[0]))
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
        CHECK_ERROR(_toStringVecUnlockChunk_V17(&v->unlocking, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringVecEraIndex_V17(&v->claimedRewards, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTeleAccount_V17(
    const pd_TeleAccount_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringVecu8(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTimepoint_V17(
    const pd_Timepoint_V17_t* v,
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

parser_error_t _toStringUnlockChunk_V17(
    const pd_UnlockChunk_V17_t* v,
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

parser_error_t _toStringUnstakeProvider_V17(
    const pd_UnstakeProvider_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "RelayChain");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Loans");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringVestingScheduleOf_V17(
    const pd_VestingScheduleOf_V17_t* v,
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

parser_error_t _toStringWeight_V17(
    const pd_Weight_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringu8_array_32_V17(
    const pd_u8_array_32_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccountId_V17(
    const pd_VecAccountId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V17);
}

parser_error_t _toStringVecAssetIdOf_V17(
    const pd_VecAssetIdOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdOf_V17);
}

parser_error_t _toStringVecEraIndex_V17(
    const pd_VecEraIndex_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(EraIndex_V17);
}

parser_error_t _toStringVecUnlockChunk_V17(
    const pd_VecUnlockChunk_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(UnlockChunk_V17);
}

parser_error_t _toStringVecVestingScheduleOf_V17(
    const pd_VecVestingScheduleOf_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VestingScheduleOf_V17);
}

parser_error_t _toStringOptionAccountId_V17(
    const pd_OptionAccountId_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V17(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionContributionStrategy_V17(
    const pd_OptionContributionStrategy_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringContributionStrategy_V17(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V17(
    const pd_OptionProxyType_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V17(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionRate_V17(
    const pd_OptionRate_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringRate_V17(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionRatio_V17(
    const pd_OptionRatio_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringRatio_V17(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V17(
    const pd_OptionTimepoint_V17_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V17(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
