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
#include "substrate_dispatch_V14.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAbstractFungible_V14(parser_context_t* c, pd_AbstractFungible_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu8(c, &v->id))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    return parser_ok;
}

parser_error_t _readAbstractNonFungible_V14(parser_context_t* c, pd_AbstractNonFungible_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu8(c, &v->_class))
    CHECK_ERROR(_readAssetInstance_V14(c, &v->instance))
    return parser_ok;
}

parser_error_t _readAccountId32_V14(parser_context_t* c, pd_AccountId32_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V14(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32_V14(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountIdOfT_V14(parser_context_t* c, pd_AccountIdOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAccountId_V14(parser_context_t* c, pd_AccountId_V14_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex64_V14(parser_context_t* c, pd_AccountIndex64_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V14(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountKey20_V14(parser_context_t* c, pd_AccountKey20_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V14(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountOfT_V14(parser_context_t* c, pd_AccountOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAccountVoteSplit_V14(parser_context_t* c, pd_AccountVoteSplit_V14_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->aye));
    CHECK_ERROR(_readBalanceOf(c, &v->nay));
    return parser_ok;
}

parser_error_t _readAccountVoteStandard_V14(parser_context_t* c, pd_AccountVoteStandard_V14_t* v)
{
    CHECK_ERROR(_readVote_V14(c, &v->vote));
    CHECK_ERROR(_readBalanceOf(c, &v->balance));
    return parser_ok;
}

parser_error_t _readAccountVote_V14(parser_context_t* c, pd_AccountVote_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readAccountVoteStandard_V14(c, &v->voteStandard))
        break;
    case 1:
        CHECK_ERROR(_readAccountVoteSplit_V14(c, &v->voteSplit))
        break;
    default:
        break;
    }

    return parser_ok;
}

parser_error_t _readAssetIdOfTIAssetIdOfTI_V14(parser_context_t* c, pd_AssetIdOfTIAssetIdOfTI_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAssetIdOfTI_V14(parser_context_t* c, pd_AssetIdOfTI_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetIdOfT_V14(parser_context_t* c, pd_AssetIdOfT_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetId_V14(parser_context_t* c, pd_AssetId_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Concrete
        CHECK_ERROR(_readBoxVersionedMultiLocation_V14(c, &v->concrete))
        break;
    case 1: // Abstract
        CHECK_ERROR(_readVecu8(c, &v->abstract))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAssetInstance_V14(parser_context_t* c, pd_AssetInstance_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        // Empty
        break;
    case 1: // Index
        CHECK_ERROR(_readu128(c, &v->index))
        break;
    case 2: // array4
        GEN_DEF_READARRAY(4)
        break;
    case 3: // array8
        GEN_DEF_READARRAY(8)
        break;
    case 4: // array16
        GEN_DEF_READARRAY(16)
        break;
    case 5: // array32
        GEN_DEF_READARRAY(32)
        break;
    case 6: // blob
        CHECK_ERROR(_readBytes(c, &v->blob))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAssetType_V14(parser_context_t* c, pd_AssetType_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBalanceOfTIBalanceOfTI_V14(parser_context_t* c, pd_BalanceOfTIBalanceOfTI_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBalanceOfT_V14(parser_context_t* c, pd_BalanceOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBlockNumberForT_V14(parser_context_t* c, pd_BlockNumberForT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBodyId_V14(parser_context_t* c, pd_BodyId_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unit
        break;
    case 1: // Named
        CHECK_ERROR(_readVecu8(c, &v->named))
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

parser_error_t _readBodyPart_V14(parser_context_t* c, pd_BodyPart_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Voice
        break;
    case 1: // Named
        CHECK_ERROR(_readCompactu32(c, &v->count))
        break;
    case 2: // Fraction
    case 3: // AtleastProportion
    case 4: // MoreThanProportion
        CHECK_ERROR(_readFraction_V14(c, &v->fraction))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoxCallIdOfT_V14(parser_context_t* c, pd_BoxCallIdOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxCallOrHashOfT_V14(parser_context_t* c, pd_BoxCallOrHashOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V14(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxMultiLocation_V14(parser_context_t* c, pd_BoxMultiLocation_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxPalletsOrigin_V14(parser_context_t* c, pd_BoxPalletsOrigin_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiAsset_V14(parser_context_t* c, pd_BoxVersionedMultiAsset_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiAssetV0_V14(c, &v->multiassetV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiAssetV1_V14(c, &v->multiassetV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedMultiAssets_V14(parser_context_t* c, pd_BoxVersionedMultiAssets_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readVecMultiAssetV0_V14(c, &v->vecMultiassetV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readVecMultiAssetV1_V14(c, &v->vecMultiassetV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedMultiLocation_V14(parser_context_t* c, pd_BoxVersionedMultiLocation_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiLocationV0_V14(c, &v->multilocationV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiLocationV1_V14(c, &v->multilocationV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedXcmTasSysConfigCall_V14(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTuple_V14(parser_context_t* c, pd_BoxVersionedXcmTuple_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBridgeToken_V14(parser_context_t* c, pd_BridgeToken_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBridgeType_V14(parser_context_t* c, pd_BridgeType_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V14(parser_context_t* c, pd_CallHashOf_V14_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChainId_V14(parser_context_t* c, pd_ChainId_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readChainNonce_V14(parser_context_t* c, pd_ChainNonce_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCompactAccountIndex_V14(parser_context_t* c, pd_CompactAccountIndex_V14_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConcreteFungible_V14(parser_context_t* c, pd_ConcreteFungible_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiLocationV0_V14(c, &v->id))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    return parser_ok;
}

parser_error_t _readConcreteNonFungible_V14(parser_context_t* c, pd_ConcreteNonFungible_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiLocationV0_V14(c, &v->_class))
    CHECK_ERROR(_readAssetInstance_V14(c, &v->instance))
    return parser_ok;
}

parser_error_t _readContributionStrategy_V14(parser_context_t* c, pd_ContributionStrategy_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readConviction_V14(parser_context_t* c, pd_Conviction_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readCurrencyId_V14(parser_context_t* c, pd_CurrencyId_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readCurveModel_V14(parser_context_t* c, pd_CurveModel_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRate_V14(c, &v->baseRate))
    return parser_ok;
}

parser_error_t _readDerivativeIndex_V14(parser_context_t* c, pd_DerivativeIndex_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readDestroyWitness_V14(parser_context_t* c, pd_DestroyWitness_V14_t* v)
{
    CHECK_ERROR(_readCompactu32(c, &v->accounts))
    CHECK_ERROR(_readCompactu32(c, &v->sufficients))
    CHECK_ERROR(_readCompactu32(c, &v->approvals))
    return parser_ok;
}

parser_error_t _readDoubleEncodedTuple_V14(parser_context_t* c, pd_DoubleEncodedTuple_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V14(parser_context_t* c, pd_EraIndex_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readFraction_V14(parser_context_t* c, pd_Fraction_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->nom))
    CHECK_ERROR(_readCompactu32(c, &v->denom))
    return parser_ok;
}

parser_error_t _readFungibility_V14(parser_context_t* c, pd_Fungibility_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        CHECK_ERROR(_readFungible_V14(c, &v->fungible))
        break;
    case 1: // Index
        CHECK_ERROR(_readAssetInstance_V14(c, &v->nonFungible))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readFungible_V14(parser_context_t* c, pd_Fungible_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readIdentityFields_V14(parser_context_t* c, pd_IdentityFields_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readInterestRateModel_V14(parser_context_t* c, pd_InterestRateModel_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readJumpModel_V14(c, &v->jump))
        break;
    case 1:
        CHECK_ERROR(_readCurveModel_V14(c, &v->curve))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJudgementBalanceOfT_V14(parser_context_t* c, pd_JudgementBalanceOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readJumpModel_V14(parser_context_t* c, pd_JumpModel_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRate_V14(c, &v->baseRate))
    CHECK_ERROR(_readRate_V14(c, &v->jumpRate))
    CHECK_ERROR(_readRate_V14(c, &v->fullRate))
    CHECK_ERROR(_readRatio_V14(c, &v->jumpUtilization))
    return parser_ok;
}

parser_error_t _readJunctionX1_V14(parser_context_t* c, pd_JunctionX1_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionX2_V14(parser_context_t* c, pd_JunctionX2_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionX3_V14(parser_context_t* c, pd_JunctionX3_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    CHECK_ERROR(_readJunction_V14(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionX4_V14(parser_context_t* c, pd_JunctionX4_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    CHECK_ERROR(_readJunction_V14(c, &v->junction2))
    CHECK_ERROR(_readJunction_V14(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionX5_V14(parser_context_t* c, pd_JunctionX5_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    CHECK_ERROR(_readJunction_V14(c, &v->junction2))
    CHECK_ERROR(_readJunction_V14(c, &v->junction3))
    CHECK_ERROR(_readJunction_V14(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionX6_V14(parser_context_t* c, pd_JunctionX6_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    CHECK_ERROR(_readJunction_V14(c, &v->junction2))
    CHECK_ERROR(_readJunction_V14(c, &v->junction3))
    CHECK_ERROR(_readJunction_V14(c, &v->junction4))
    CHECK_ERROR(_readJunction_V14(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionX7_V14(parser_context_t* c, pd_JunctionX7_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    CHECK_ERROR(_readJunction_V14(c, &v->junction2))
    CHECK_ERROR(_readJunction_V14(c, &v->junction3))
    CHECK_ERROR(_readJunction_V14(c, &v->junction4))
    CHECK_ERROR(_readJunction_V14(c, &v->junction5))
    CHECK_ERROR(_readJunction_V14(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionX8_V14(parser_context_t* c, pd_JunctionX8_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V14(c, &v->junction0))
    CHECK_ERROR(_readJunction_V14(c, &v->junction1))
    CHECK_ERROR(_readJunction_V14(c, &v->junction2))
    CHECK_ERROR(_readJunction_V14(c, &v->junction3))
    CHECK_ERROR(_readJunction_V14(c, &v->junction4))
    CHECK_ERROR(_readJunction_V14(c, &v->junction5))
    CHECK_ERROR(_readJunction_V14(c, &v->junction6))
    CHECK_ERROR(_readJunction_V14(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunction_V14(parser_context_t* c, pd_Junction_V14_t* v)
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
        CHECK_ERROR(_readAccountId32_V14(c, &v->accountId32))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64_V14(c, &v->accountIndex64))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_readAccountKey20_V14(c, &v->accountKey20))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_readVecu8(c, &v->generalKey))
        break;
    case 8: // OnlyChild
        break;
    case 9: // Plurality
        CHECK_ERROR(_readPlurality_V14(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctions_V14(parser_context_t* c, pd_Junctions_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionX1_V14(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionX2_V14(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionX3_V14(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionX4_V14(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionX5_V14(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionX6_V14(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionX7_V14(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionX8_V14(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readKeyValue_V14(parser_context_t* c, pd_KeyValue_V14_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V14(parser_context_t* c, pd_Key_V14_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V14(parser_context_t* c, pd_Keys_V14_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLeasePeriod_V14(parser_context_t* c, pd_LeasePeriod_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLookupasStaticLookupSource_V14(parser_context_t* c, pd_LookupasStaticLookupSource_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V14(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V14(c, &v->index))
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

parser_error_t _readMarketBalanceOfT_V14(parser_context_t* c, pd_MarketBalanceOfT_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readRatio_V14(c, &v->collateralFactor))
    CHECK_ERROR(_readRatio_V14(c, &v->liquidationThreshold))
    CHECK_ERROR(_readRatio_V14(c, &v->reserveFactor))
    CHECK_ERROR(_readRatio_V14(c, &v->closeFactor))
    CHECK_ERROR(_readRate_V14(c, &v->liquidateIncentive))
    CHECK_ERROR(_readRatio_V14(c, &v->liquidateIncentiveReservedFactor))
    CHECK_ERROR(_readInterestRateModel_V14(c, &v->rateModel))
    CHECK_ERROR(_readMarketState_V14(c, &v->state))
    CHECK_ERROR(_readBalance(c, &v->supplyCap))
    CHECK_ERROR(_readBalance(c, &v->borrowCap))
    CHECK_ERROR(_readCurrencyId_V14(c, &v->ptokenId))
    return parser_ok;
}

parser_error_t _readMarketState_V14(parser_context_t* c, pd_MarketState_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMemberCount_V14(parser_context_t* c, pd_MemberCount_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMultiAssetV0_V14(parser_context_t* c, pd_MultiAssetV0_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // None
    case 1: // All
    case 2: // AllFungible
    case 3: // AllNonFungible
        break;
    case 4: // AllAbstractFungible
    case 5: // AllAbstractNonFungible
        CHECK_ERROR(_readVecu8(c, &v->abstract))
        break;
    case 6: // AllConcreteFungible
    case 7: // AllConcreteNonFungible
        CHECK_ERROR(_readMultiLocationV0_V14(c, &v->concrete))
        break;
    case 8: // AbstractFungible
        CHECK_ERROR(_readAbstractFungible_V14(c, &v->abstractFungible))
        break;
    case 9: // AbstractNonFungible
        CHECK_ERROR(_readAbstractNonFungible_V14(c, &v->abstractNonFungible))
        break;
    case 10: // ConcreteFungible
        CHECK_ERROR(_readConcreteFungible_V14(c, &v->concreteFungible))
        break;
    case 11: // ConcreteNonFungible
        CHECK_ERROR(_readConcreteNonFungible_V14(c, &v->concreteNonFungible))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMultiAssetV1_V14(parser_context_t* c, pd_MultiAssetV1_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId_V14(c, &v->assetId))
    CHECK_ERROR(_readFungibility_V14(c, &v->fungibility))
    return parser_ok;
}

parser_error_t _readMultiLocationV0_V14(parser_context_t* c, pd_MultiLocationV0_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctions_V14(c, &v->junctions))
    return parser_ok;
}

parser_error_t _readMultiLocationV1_V14(parser_context_t* c, pd_MultiLocationV1_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->parents))
    CHECK_ERROR(_readJunctions_V14(c, &v->interior))
    return parser_ok;
}

parser_error_t _readNetworkId_V14(parser_context_t* c, pd_NetworkId_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Any
    case 2: // Polkadot
    case 3: // Kusama
        break;
    case 1: // Index
        CHECK_ERROR(_readVecu8(c, &v->named))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOpaqueCall_V14(parser_context_t* c, pd_OpaqueCall_V14_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readOverweightIndex_V14(parser_context_t* c, pd_OverweightIndex_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParaId_V14(parser_context_t* c, pd_ParaId_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readParachainInherentData_V14(parser_context_t* c, pd_ParachainInherentData_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V14(parser_context_t* c, pd_Perbill_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPlurality_V14(parser_context_t* c, pd_Plurality_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyId_V14(c, &v->id))
    CHECK_ERROR(_readBodyPart_V14(c, &v->part))
    return parser_ok;
}

parser_error_t _readPrice_V14(parser_context_t* c, pd_Price_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readProxyType_V14(parser_context_t* c, pd_ProxyType_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readQueryId_V14(parser_context_t* c, pd_QueryId_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readRate_V14(parser_context_t* c, pd_Rate_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readRatio_V14(parser_context_t* c, pd_Ratio_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readReferendumIndex_V14(parser_context_t* c, pd_ReferendumIndex_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V14(parser_context_t* c, pd_RegistrarIndex_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readResponse_V14(parser_context_t* c, pd_Response_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestinationAccountIdOfT_V14(parser_context_t* c, pd_RewardDestinationAccountIdOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V14(parser_context_t* c, pd_RewardDestination_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId_V14(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readStakingLedgerAccountIdBalanceOfT_V14(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId_V14(c, &v->stash))
    CHECK_ERROR(_readCompactu128(c, &v->total))
    CHECK_ERROR(_readCompactu128(c, &v->active))
    CHECK_ERROR(_readVecUnlockChunk_V14(c, &v->unlocking))
    CHECK_ERROR(_readVecEraIndex_V14(c, &v->claimedRewards))
    return parser_ok;
}

parser_error_t _readStreamId_V14(parser_context_t* c, pd_StreamId_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTeleAccount_V14(parser_context_t* c, pd_TeleAccount_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTimepoint_V14(parser_context_t* c, pd_Timepoint_V14_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTimestamp_V14(parser_context_t* c, pd_Timestamp_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleAccountIdData_V14(parser_context_t* c, pd_TupleAccountIdData_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleCurrencyIdBalance_V14(parser_context_t* c, pd_TupleCurrencyIdBalance_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleOracleKeyOracleValue_V14(parser_context_t* c, pd_TupleOracleKeyOracleValue_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readUnlockChunk_V14(parser_context_t* c, pd_UnlockChunk_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->value))
    CHECK_ERROR(_readCompactu32(c, &v->era))
    return parser_ok;
}

parser_error_t _readUpwardMessage_V14(parser_context_t* c, pd_UpwardMessage_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVestingScheduleOf_V14(parser_context_t* c, pd_VestingScheduleOf_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBlockNumber(c, &v->start))
    CHECK_ERROR(_readBlockNumber(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->periodCount))
    CHECK_ERROR(_readCompactu128(c, &v->perPeriod));
    return parser_ok;
}

parser_error_t _readVote_V14(parser_context_t* c, pd_Vote_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value & 0x7F) {
        return parser_value_out_of_range;
    }
    v->value = (v->value & 0x80u) >> 7u;

    return parser_ok;
}

parser_error_t _readWeightLimit_V14(parser_context_t* c, pd_WeightLimit_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readWeight_V14(parser_context_t* c, pd_Weight_V14_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readXcmCall_V14(parser_context_t* c, pd_XcmCall_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readXcmVersion_V14(parser_context_t* c, pd_XcmVersion_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readXcmWeightFeeMiscWeightBalanceOfT_V14(parser_context_t* c, pd_XcmWeightFeeMiscWeightBalanceOfT_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePeriodBlockNumber_V14(parser_context_t* c, pd_schedulePeriodBlockNumber_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePriority_V14(parser_context_t* c, pd_schedulePriority_V14_t* v)
{
    return parser_not_supported;
}

parser_error_t _readu8_array_32_V14(parser_context_t* c, pd_u8_array_32_V14_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountIdOfT_V14(parser_context_t* c, pd_VecAccountIdOfT_V14_t* v) {
    GEN_DEF_READVECTOR(AccountIdOfT_V14)
}

parser_error_t _readVecAccountId_V14(parser_context_t* c, pd_VecAccountId_V14_t* v) {
    GEN_DEF_READVECTOR(AccountId_V14)
}

parser_error_t _readVecAssetIdOfTI_V14(parser_context_t* c, pd_VecAssetIdOfTI_V14_t* v) {
    GEN_DEF_READVECTOR(AssetIdOfTI_V14)
}

parser_error_t _readVecEraIndex_V14(parser_context_t* c, pd_VecEraIndex_V14_t* v) {
    GEN_DEF_READVECTOR(EraIndex_V14)
}

parser_error_t _readVecKeyValue_V14(parser_context_t* c, pd_VecKeyValue_V14_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V14)
}

parser_error_t _readVecKey_V14(parser_context_t* c, pd_VecKey_V14_t* v) {
    GEN_DEF_READVECTOR(Key_V14)
}

parser_error_t _readVecMultiAssetV0_V14(parser_context_t* c, pd_VecMultiAssetV0_V14_t* v) {
    GEN_DEF_READVECTOR(MultiAssetV0_V14)
}

parser_error_t _readVecMultiAssetV1_V14(parser_context_t* c, pd_VecMultiAssetV1_V14_t* v) {
    GEN_DEF_READVECTOR(MultiAssetV1_V14)
}

parser_error_t _readVecTupleAccountIdData_V14(parser_context_t* c, pd_VecTupleAccountIdData_V14_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V14)
}

parser_error_t _readVecTupleCurrencyIdBalance_V14(parser_context_t* c, pd_VecTupleCurrencyIdBalance_V14_t* v) {
    GEN_DEF_READVECTOR(TupleCurrencyIdBalance_V14)
}

parser_error_t _readVecTupleOracleKeyOracleValue_V14(parser_context_t* c, pd_VecTupleOracleKeyOracleValue_V14_t* v) {
    GEN_DEF_READVECTOR(TupleOracleKeyOracleValue_V14)
}

parser_error_t _readVecUnlockChunk_V14(parser_context_t* c, pd_VecUnlockChunk_V14_t* v) {
    GEN_DEF_READVECTOR(UnlockChunk_V14)
}

parser_error_t _readVecVestingScheduleOf_V14(parser_context_t* c, pd_VecVestingScheduleOf_V14_t* v) {
    GEN_DEF_READVECTOR(VestingScheduleOf_V14)
}

parser_error_t _readOptionAccountId_V14(parser_context_t* c, pd_OptionAccountId_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBalanceOfT_V14(parser_context_t* c, pd_OptionBalanceOfT_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBalanceOfT_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBlockNumberForT_V14(parser_context_t* c, pd_OptionBlockNumberForT_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBlockNumberForT_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionContributionStrategy_V14(parser_context_t* c, pd_OptionContributionStrategy_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readContributionStrategy_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V14(parser_context_t* c, pd_OptionProxyType_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V14(parser_context_t* c, pd_OptionReferendumIndex_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V14(parser_context_t* c, pd_OptionTimepoint_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionXcmVersion_V14(parser_context_t* c, pd_OptionXcmVersion_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readXcmVersion_V14(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionschedulePeriodBlockNumber_V14(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V14_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readschedulePeriodBlockNumber_V14(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAbstractFungible_V14(
    const pd_AbstractFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringVecu8(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecu8(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAbstractNonFungible_V14(
    const pd_AbstractNonFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringVecu8(&v->_class, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetInstance_V14(&v->instance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecu8(&v->_class, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetInstance_V14(&v->instance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountId32_V14(
    const pd_AccountId32_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V14(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32_V14(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V14(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32_V14(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIdOfT_V14(
    const pd_AccountIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAccountId_V14(
    const pd_AccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex64_V14(
    const pd_AccountIndex64_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V14(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V14(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20_V14(
    const pd_AccountKey20_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V14(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V14(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountOfT_V14(
    const pd_AccountOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAccountVoteSplit_V14(
    const pd_AccountVoteSplit_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Split");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVoteStandard_V14(
    const pd_AccountVoteStandard_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote_V14(&v->vote, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Standard");
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVote_V14(&v->vote, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote_V14(
    const pd_AccountVote_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringAccountVoteStandard_V14(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1:
        CHECK_ERROR(_toStringAccountVoteSplit_V14(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringAssetIdOfTIAssetIdOfTI_V14(
    const pd_AssetIdOfTIAssetIdOfTI_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAssetIdOfTI_V14(
    const pd_AssetIdOfTI_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdOfT_V14(
    const pd_AssetIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetId_V14(
    const pd_AssetId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Concrete
        CHECK_ERROR(_toStringBoxVersionedMultiLocation_V14(&v->concrete, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Abstract
        CHECK_ERROR(_toStringVecu8(&v->abstract, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAssetInstance_V14(
    const pd_AssetInstance_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Undefined
        break;
    case 1: // Index
        CHECK_ERROR(_toStringu128(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Array4
    {
        GEN_DEF_TOSTRING_ARRAY(4)
    }
    case 3: // Array8
    {
        GEN_DEF_TOSTRING_ARRAY(8)
    }
    case 4: // Array16
    {
        GEN_DEF_TOSTRING_ARRAY(16)
    }
    case 5: // Array32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 6: // Blob
    {
        CHECK_ERROR(_toStringBytes(&v->blob, outValue, outValueLen, pageIdx, pageCount))
        break;
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAssetType_V14(
    const pd_AssetType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBalanceOfTIBalanceOfTI_V14(
    const pd_BalanceOfTIBalanceOfTI_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBalanceOfT_V14(
    const pd_BalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBlockNumberForT_V14(
    const pd_BlockNumberForT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBodyId_V14(
    const pd_BodyId_V14_t* v,
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
        CHECK_ERROR(_toStringVecu8(&v->named, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringBodyPart_V14(
    const pd_BodyPart_V14_t* v,
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
        // Print something?
        CHECK_ERROR(_toStringFraction_V14(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AtLeastProportion
        // Print something?
        CHECK_ERROR(_toStringFraction_V14(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // MoreThanProportion
        // Print something?
        CHECK_ERROR(_toStringFraction_V14(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoxCallIdOfT_V14(
    const pd_BoxCallIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxCallOrHashOfT_V14(
    const pd_BoxCallOrHashOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V14(
    const pd_BoxIdentityInfoMaxAdditionalFields_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxMultiLocation_V14(
    const pd_BoxMultiLocation_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxPalletsOrigin_V14(
    const pd_BoxPalletsOrigin_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiAsset_V14(
    const pd_BoxVersionedMultiAsset_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiAssetV0_V14(&v->multiassetV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiAssetV1_V14(&v->multiassetV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiAssets_V14(
    const pd_BoxVersionedMultiAssets_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringVecMultiAssetV0_V14(&v->vecMultiassetV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringVecMultiAssetV1_V14(&v->vecMultiassetV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiLocation_V14(
    const pd_BoxVersionedMultiLocation_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiLocationV0_V14(&v->multilocationV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiLocationV1_V14(&v->multilocationV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V14(
    const pd_BoxVersionedXcmTasSysConfigCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTuple_V14(
    const pd_BoxVersionedXcmTuple_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBridgeToken_V14(
    const pd_BridgeToken_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBridgeType_V14(
    const pd_BridgeType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V14(
    const pd_CallHashOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChainId_V14(
    const pd_ChainId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringChainNonce_V14(
    const pd_ChainNonce_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCompactAccountIndex_V14(
    const pd_CompactAccountIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConcreteFungible_V14(
    const pd_ConcreteFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiLocationV0_V14(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiLocationV0_V14(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringConcreteNonFungible_V14(
    const pd_ConcreteNonFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiLocationV0_V14(&v->_class, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetInstance_V14(&v->instance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiLocationV0_V14(&v->_class, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetInstance_V14(&v->instance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringContributionStrategy_V14(
    const pd_ContributionStrategy_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringConviction_V14(
    const pd_Conviction_V14_t* v,
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

parser_error_t _toStringCurrencyId_V14(
    const pd_CurrencyId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurveModel_V14(
    const pd_CurveModel_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringRate_V14(&v->baseRate, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringDerivativeIndex_V14(
    const pd_DerivativeIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDestroyWitness_V14(
    const pd_DestroyWitness_V14_t* v,
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

parser_error_t _toStringDoubleEncodedTuple_V14(
    const pd_DoubleEncodedTuple_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V14(
    const pd_EraIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringFraction_V14(
    const pd_Fraction_V14_t* v,
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

parser_error_t _toStringFungibility_V14(
    const pd_Fungibility_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Undefined
        CHECK_ERROR(_toStringFungible_V14(&v->fungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringAssetInstance_V14(&v->nonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringFungible_V14(
    const pd_Fungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->value, outValue, outValueLen, 0, &pages[0]))

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

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringIdentityFields_V14(
    const pd_IdentityFields_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringInterestRateModel_V14(
    const pd_InterestRateModel_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringJumpModel_V14(&v->jump, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        CHECK_ERROR(_toStringCurveModel_V14(&v->curve, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJudgementBalanceOfT_V14(
    const pd_JudgementBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringJumpModel_V14(
    const pd_JumpModel_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringRate_V14(&v->baseRate, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRate_V14(&v->jumpRate, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringRate_V14(&v->fullRate, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringRatio_V14(&v->jumpUtilization, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringRate_V14(&v->baseRate, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRate_V14(&v->jumpRate, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringRate_V14(&v->fullRate, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringRatio_V14(&v->jumpUtilization, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX1_V14(
    const pd_JunctionX1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX2_V14(
    const pd_JunctionX2_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX3_V14(
    const pd_JunctionX3_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX4_V14(
    const pd_JunctionX4_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX5_V14(
    const pd_JunctionX5_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX6_V14(
    const pd_JunctionX6_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX7_V14(
    const pd_JunctionX7_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX8_V14(
    const pd_JunctionX8_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunction_V14(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunction_V14(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunction_V14(
    const pd_Junction_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Parent
        // Print Parent
        break;
    case 1: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_toStringAccountId32_V14(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64_V14(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20_V14(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_toStringVecu8(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // OnlyChild
        // Print OnlyChild
        break;
    case 9: // Plurality
        CHECK_ERROR(_toStringPlurality_V14(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctions_V14(
    const pd_Junctions_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionX1_V14(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionX2_V14(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionX3_V14(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionX4_V14(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionX5_V14(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionX6_V14(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionX7_V14(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionX8_V14(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringKeyValue_V14(
    const pd_KeyValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V14(
    const pd_Key_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V14(
    const pd_Keys_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLeasePeriod_V14(
    const pd_LeasePeriod_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupasStaticLookupSource_V14(
    const pd_LookupasStaticLookupSource_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V14(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V14(&v->index, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringMarketBalanceOfT_V14(
    const pd_MarketBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[11] = { 0 };
    CHECK_ERROR(_toStringRatio_V14(&v->collateralFactor, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRatio_V14(&v->liquidationThreshold, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringRatio_V14(&v->reserveFactor, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringRatio_V14(&v->closeFactor, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringRate_V14(&v->liquidateIncentive, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringRatio_V14(&v->liquidateIncentiveReservedFactor, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringInterestRateModel_V14(&v->rateModel, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringMarketState_V14(&v->state, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringBalance(&v->supplyCap, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringBalance(&v->borrowCap, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringCurrencyId_V14(&v->ptokenId, outValue, outValueLen, 0, &pages[10]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringRatio_V14(&v->collateralFactor, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRatio_V14(&v->liquidationThreshold, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringRatio_V14(&v->reserveFactor, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringRatio_V14(&v->closeFactor, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringRate_V14(&v->liquidateIncentive, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringRatio_V14(&v->liquidateIncentiveReservedFactor, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringInterestRateModel_V14(&v->rateModel, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringMarketState_V14(&v->state, outValue, outValueLen, pageIdx, &pages[7]))
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
        CHECK_ERROR(_toStringCurrencyId_V14(&v->ptokenId, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMarketState_V14(
    const pd_MarketState_V14_t* v,
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

parser_error_t _toStringMemberCount_V14(
    const pd_MemberCount_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiAssetV0_V14(
    const pd_MultiAssetV0_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // None
        snprintf(outValue, outValueLen, "None");
        break;
    case 1: // All
        snprintf(outValue, outValueLen, "All");
        break;
    case 2: // AllFungible
        snprintf(outValue, outValueLen, "AllFungible");
        break;
    case 3: // AllNonFungible
        snprintf(outValue, outValueLen, "AllNonFungible");
        break;
    case 4: // AllAbstractFungible
    case 5: // AllAbstractNonFungible
        CHECK_ERROR(_toStringVecu8(&v->abstract, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // AllConcreteFungible
    case 7: // AllConcreteNonFungible
        CHECK_ERROR(_toStringMultiLocationV0_V14(&v->concrete, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // AbstractFungible
        CHECK_ERROR(_toStringAbstractFungible_V14(&v->abstractFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 9: // AbstractNonFungible
        CHECK_ERROR(_toStringAbstractNonFungible_V14(&v->abstractNonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 10: // ConcreteFungible
        CHECK_ERROR(_toStringConcreteFungible_V14(&v->concreteFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 11: // ConcreteNonFungible
        CHECK_ERROR(_toStringConcreteNonFungible_V14(&v->concreteNonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringMultiAssetV1_V14(
    const pd_MultiAssetV1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetId_V14(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringFungibility_V14(&v->fungibility, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId_V14(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringFungibility_V14(&v->fungibility, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMultiLocationV0_V14(
    const pd_MultiLocationV0_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringJunctions_V14(&v->junctions, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringMultiLocationV1_V14(
    const pd_MultiLocationV1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctions_V14(&v->interior, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringJunctions_V14(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNetworkId_V14(
    const pd_NetworkId_V14_t* v,
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
        CHECK_ERROR(_toStringVecu8(&v->named, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringOpaqueCall_V14(
    const pd_OpaqueCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex_V14(
    const pd_OverweightIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParaId_V14(
    const pd_ParaId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringParachainInherentData_V14(
    const pd_ParachainInherentData_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V14(
    const pd_Perbill_V14_t* v,
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

parser_error_t _toStringPlurality_V14(
    const pd_Plurality_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyId_V14(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart_V14(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyId_V14(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart_V14(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPrice_V14(
    const pd_Price_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringProxyType_V14(
    const pd_ProxyType_V14_t* v,
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

parser_error_t _toStringQueryId_V14(
    const pd_QueryId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRate_V14(
    const pd_Rate_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringRatio_V14(
    const pd_Ratio_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringReferendumIndex_V14(
    const pd_ReferendumIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V14(
    const pd_RegistrarIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringResponse_V14(
    const pd_Response_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestinationAccountIdOfT_V14(
    const pd_RewardDestinationAccountIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V14(
    const pd_RewardDestination_V14_t* v,
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
        CHECK_ERROR(_toStringAccountId_V14(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V14(
    const pd_StakingLedgerAccountIdBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringAccountId_V14(&v->stash, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->total, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu128(&v->active, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringVecUnlockChunk_V14(&v->unlocking, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringVecEraIndex_V14(&v->claimedRewards, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId_V14(&v->stash, outValue, outValueLen, pageIdx, &pages[0]))
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
        CHECK_ERROR(_toStringVecUnlockChunk_V14(&v->unlocking, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringVecEraIndex_V14(&v->claimedRewards, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringStreamId_V14(
    const pd_StreamId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTeleAccount_V14(
    const pd_TeleAccount_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint_V14(
    const pd_Timepoint_V14_t* v,
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

parser_error_t _toStringTimestamp_V14(
    const pd_Timestamp_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleAccountIdData_V14(
    const pd_TupleAccountIdData_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleCurrencyIdBalance_V14(
    const pd_TupleCurrencyIdBalance_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleOracleKeyOracleValue_V14(
    const pd_TupleOracleKeyOracleValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringUnlockChunk_V14(
    const pd_UnlockChunk_V14_t* v,
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

parser_error_t _toStringUpwardMessage_V14(
    const pd_UpwardMessage_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVestingScheduleOf_V14(
    const pd_VestingScheduleOf_V14_t* v,
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

parser_error_t _toStringVote_V14(
    const pd_Vote_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Nay");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Aye");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringWeightLimit_V14(
    const pd_WeightLimit_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringWeight_V14(
    const pd_Weight_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcmCall_V14(
    const pd_XcmCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringXcmVersion_V14(
    const pd_XcmVersion_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringXcmWeightFeeMiscWeightBalanceOfT_V14(
    const pd_XcmWeightFeeMiscWeightBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePeriodBlockNumber_V14(
    const pd_schedulePeriodBlockNumber_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePriority_V14(
    const pd_schedulePriority_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringu8_array_32_V14(
    const pd_u8_array_32_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccountIdOfT_V14(
    const pd_VecAccountIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountIdOfT_V14);
}

parser_error_t _toStringVecAccountId_V14(
    const pd_VecAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V14);
}

parser_error_t _toStringVecAssetIdOfTI_V14(
    const pd_VecAssetIdOfTI_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdOfTI_V14);
}

parser_error_t _toStringVecEraIndex_V14(
    const pd_VecEraIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(EraIndex_V14);
}

parser_error_t _toStringVecKeyValue_V14(
    const pd_VecKeyValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V14);
}

parser_error_t _toStringVecKey_V14(
    const pd_VecKey_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V14);
}

parser_error_t _toStringVecMultiAssetV0_V14(
    const pd_VecMultiAssetV0_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAssetV0_V14);
}

parser_error_t _toStringVecMultiAssetV1_V14(
    const pd_VecMultiAssetV1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAssetV1_V14);
}

parser_error_t _toStringVecTupleAccountIdData_V14(
    const pd_VecTupleAccountIdData_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V14);
}

parser_error_t _toStringVecTupleCurrencyIdBalance_V14(
    const pd_VecTupleCurrencyIdBalance_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleCurrencyIdBalance_V14);
}

parser_error_t _toStringVecTupleOracleKeyOracleValue_V14(
    const pd_VecTupleOracleKeyOracleValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleOracleKeyOracleValue_V14);
}

parser_error_t _toStringVecUnlockChunk_V14(
    const pd_VecUnlockChunk_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(UnlockChunk_V14);
}

parser_error_t _toStringVecVestingScheduleOf_V14(
    const pd_VecVestingScheduleOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VestingScheduleOf_V14);
}

parser_error_t _toStringOptionAccountId_V14(
    const pd_OptionAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionBalanceOfT_V14(
    const pd_OptionBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBalanceOfT_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionBlockNumberForT_V14(
    const pd_OptionBlockNumberForT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBlockNumberForT_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionContributionStrategy_V14(
    const pd_OptionContributionStrategy_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringContributionStrategy_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V14(
    const pd_OptionProxyType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V14(
    const pd_OptionReferendumIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V14(
    const pd_OptionTimepoint_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionXcmVersion_V14(
    const pd_OptionXcmVersion_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringXcmVersion_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionschedulePeriodBlockNumber_V14(
    const pd_OptionschedulePeriodBlockNumber_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringschedulePeriodBlockNumber_V14(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
