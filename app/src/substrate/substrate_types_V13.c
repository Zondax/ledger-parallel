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
#include "substrate_dispatch_V13.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAbstractFungible_V13(parser_context_t* c, pd_AbstractFungible_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu8(c, &v->id))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    return parser_ok;
}

parser_error_t _readAbstractNonFungible_V13(parser_context_t* c, pd_AbstractNonFungible_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu8(c, &v->_class))
    CHECK_ERROR(_readAssetInstance_V13(c, &v->instance))
    return parser_ok;
}

parser_error_t _readAccountId32_V13(parser_context_t* c, pd_AccountId32_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V13(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32_V13(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountIdOfT_V13(parser_context_t* c, pd_AccountIdOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAccountId_V13(parser_context_t* c, pd_AccountId_V13_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex64_V13(parser_context_t* c, pd_AccountIndex64_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V13(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountKey20_V13(parser_context_t* c, pd_AccountKey20_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId_V13(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountOfT_V13(parser_context_t* c, pd_AccountOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAccountVoteSplit_V13(parser_context_t* c, pd_AccountVoteSplit_V13_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->aye));
    CHECK_ERROR(_readBalanceOf(c, &v->nay));
    return parser_ok;
}

parser_error_t _readAccountVoteStandard_V13(parser_context_t* c, pd_AccountVoteStandard_V13_t* v)
{
    CHECK_ERROR(_readVote_V13(c, &v->vote));
    CHECK_ERROR(_readBalanceOf(c, &v->balance));
    return parser_ok;
}

parser_error_t _readAccountVote_V13(parser_context_t* c, pd_AccountVote_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readAccountVoteStandard_V13(c, &v->voteStandard))
        break;
    case 1:
        CHECK_ERROR(_readAccountVoteSplit_V13(c, &v->voteSplit))
        break;
    default:
        break;
    }

    return parser_ok;
}

parser_error_t _readAssetIdOfTIAssetIdOfTI_V13(parser_context_t* c, pd_AssetIdOfTIAssetIdOfTI_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAssetIdOfTI_V13(parser_context_t* c, pd_AssetIdOfTI_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetIdOfT_V13(parser_context_t* c, pd_AssetIdOfT_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetId_V13(parser_context_t* c, pd_AssetId_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Concrete
        CHECK_ERROR(_readBoxVersionedMultiLocation_V13(c, &v->concrete))
        break;
    case 1: // Abstract
        CHECK_ERROR(_readVecu8(c, &v->abstract))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAssetInstance_V13(parser_context_t* c, pd_AssetInstance_V13_t* v)
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

parser_error_t _readAssetType_V13(parser_context_t* c, pd_AssetType_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBalanceOfTIBalanceOfTI_V13(parser_context_t* c, pd_BalanceOfTIBalanceOfTI_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBalanceOfT_V13(parser_context_t* c, pd_BalanceOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBlockNumberForT_V13(parser_context_t* c, pd_BlockNumberForT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBodyId_V13(parser_context_t* c, pd_BodyId_V13_t* v)
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

parser_error_t _readBodyPart_V13(parser_context_t* c, pd_BodyPart_V13_t* v)
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
        CHECK_ERROR(_readFraction_V13(c, &v->fraction))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoxCallIdOfT_V13(parser_context_t* c, pd_BoxCallIdOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxCallOrHashOfT_V13(parser_context_t* c, pd_BoxCallOrHashOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V13(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxMultiLocation_V13(parser_context_t* c, pd_BoxMultiLocation_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxPalletsOrigin_V13(parser_context_t* c, pd_BoxPalletsOrigin_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiAsset_V13(parser_context_t* c, pd_BoxVersionedMultiAsset_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiAssetV0_V13(c, &v->multiassetV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiAssetV1_V13(c, &v->multiassetV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedMultiAssets_V13(parser_context_t* c, pd_BoxVersionedMultiAssets_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readVecMultiAssetV0_V13(c, &v->vecMultiassetV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readVecMultiAssetV1_V13(c, &v->vecMultiassetV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedMultiLocation_V13(parser_context_t* c, pd_BoxVersionedMultiLocation_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiLocationV0_V13(c, &v->multilocationV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiLocationV1_V13(c, &v->multilocationV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedXcmTasSysConfigCall_V13(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTuple_V13(parser_context_t* c, pd_BoxVersionedXcmTuple_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBridgeToken_V13(parser_context_t* c, pd_BridgeToken_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBridgeType_V13(parser_context_t* c, pd_BridgeType_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V13(parser_context_t* c, pd_CallHashOf_V13_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChainId_V13(parser_context_t* c, pd_ChainId_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readChainNonce_V13(parser_context_t* c, pd_ChainNonce_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCompactAccountIndex_V13(parser_context_t* c, pd_CompactAccountIndex_V13_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConcreteFungible_V13(parser_context_t* c, pd_ConcreteFungible_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiLocationV0_V13(c, &v->id))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    return parser_ok;
}

parser_error_t _readConcreteNonFungible_V13(parser_context_t* c, pd_ConcreteNonFungible_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiLocationV0_V13(c, &v->_class))
    CHECK_ERROR(_readAssetInstance_V13(c, &v->instance))
    return parser_ok;
}

parser_error_t _readContributionStrategy_V13(parser_context_t* c, pd_ContributionStrategy_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readConviction_V13(parser_context_t* c, pd_Conviction_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readCurrencyId_V13(parser_context_t* c, pd_CurrencyId_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDerivativeIndex_V13(parser_context_t* c, pd_DerivativeIndex_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readDestroyWitness_V13(parser_context_t* c, pd_DestroyWitness_V13_t* v)
{
    CHECK_ERROR(_readCompactu32(c, &v->accounts))
    CHECK_ERROR(_readCompactu32(c, &v->sufficients))
    CHECK_ERROR(_readCompactu32(c, &v->approvals))
    return parser_ok;
}

parser_error_t _readDoubleEncodedTuple_V13(parser_context_t* c, pd_DoubleEncodedTuple_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V13(parser_context_t* c, pd_EraIndex_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readFraction_V13(parser_context_t* c, pd_Fraction_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->nom))
    CHECK_ERROR(_readCompactu32(c, &v->denom))
    return parser_ok;
}

parser_error_t _readFungibility_V13(parser_context_t* c, pd_Fungibility_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        CHECK_ERROR(_readFungible_V13(c, &v->fungible))
        break;
    case 1: // Index
        CHECK_ERROR(_readAssetInstance_V13(c, &v->nonFungible))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readFungible_V13(parser_context_t* c, pd_Fungible_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->value))
    return parser_ok;
}

parser_error_t _readIdentityFields_V13(parser_context_t* c, pd_IdentityFields_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readInterestRateModel_V13(parser_context_t* c, pd_InterestRateModel_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readJudgementBalanceOfT_V13(parser_context_t* c, pd_JudgementBalanceOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readJunctionX1_V13(parser_context_t* c, pd_JunctionX1_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionX2_V13(parser_context_t* c, pd_JunctionX2_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionX3_V13(parser_context_t* c, pd_JunctionX3_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    CHECK_ERROR(_readJunction_V13(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionX4_V13(parser_context_t* c, pd_JunctionX4_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    CHECK_ERROR(_readJunction_V13(c, &v->junction2))
    CHECK_ERROR(_readJunction_V13(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionX5_V13(parser_context_t* c, pd_JunctionX5_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    CHECK_ERROR(_readJunction_V13(c, &v->junction2))
    CHECK_ERROR(_readJunction_V13(c, &v->junction3))
    CHECK_ERROR(_readJunction_V13(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionX6_V13(parser_context_t* c, pd_JunctionX6_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    CHECK_ERROR(_readJunction_V13(c, &v->junction2))
    CHECK_ERROR(_readJunction_V13(c, &v->junction3))
    CHECK_ERROR(_readJunction_V13(c, &v->junction4))
    CHECK_ERROR(_readJunction_V13(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionX7_V13(parser_context_t* c, pd_JunctionX7_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    CHECK_ERROR(_readJunction_V13(c, &v->junction2))
    CHECK_ERROR(_readJunction_V13(c, &v->junction3))
    CHECK_ERROR(_readJunction_V13(c, &v->junction4))
    CHECK_ERROR(_readJunction_V13(c, &v->junction5))
    CHECK_ERROR(_readJunction_V13(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionX8_V13(parser_context_t* c, pd_JunctionX8_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunction_V13(c, &v->junction0))
    CHECK_ERROR(_readJunction_V13(c, &v->junction1))
    CHECK_ERROR(_readJunction_V13(c, &v->junction2))
    CHECK_ERROR(_readJunction_V13(c, &v->junction3))
    CHECK_ERROR(_readJunction_V13(c, &v->junction4))
    CHECK_ERROR(_readJunction_V13(c, &v->junction5))
    CHECK_ERROR(_readJunction_V13(c, &v->junction6))
    CHECK_ERROR(_readJunction_V13(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunction_V13(parser_context_t* c, pd_Junction_V13_t* v)
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
        CHECK_ERROR(_readAccountId32_V13(c, &v->accountId32))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64_V13(c, &v->accountIndex64))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_readAccountKey20_V13(c, &v->accountKey20))
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
        CHECK_ERROR(_readPlurality_V13(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctions_V13(parser_context_t* c, pd_Junctions_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionX1_V13(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionX2_V13(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionX3_V13(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionX4_V13(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionX5_V13(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionX6_V13(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionX7_V13(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionX8_V13(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readKeyValue_V13(parser_context_t* c, pd_KeyValue_V13_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V13(parser_context_t* c, pd_Key_V13_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V13(parser_context_t* c, pd_Keys_V13_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLeasePeriod_V13(parser_context_t* c, pd_LeasePeriod_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLookupasStaticLookupSource_V13(parser_context_t* c, pd_LookupasStaticLookupSource_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V13(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V13(c, &v->index))
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

parser_error_t _readMarketBalanceOfT_V13(parser_context_t* c, pd_MarketBalanceOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMemberCount_V13(parser_context_t* c, pd_MemberCount_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMultiAssetV0_V13(parser_context_t* c, pd_MultiAssetV0_V13_t* v)
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
        CHECK_ERROR(_readMultiLocationV0_V13(c, &v->concrete))
        break;
    case 8: // AbstractFungible
        CHECK_ERROR(_readAbstractFungible_V13(c, &v->abstractFungible))
        break;
    case 9: // AbstractNonFungible
        CHECK_ERROR(_readAbstractNonFungible_V13(c, &v->abstractNonFungible))
        break;
    case 10: // ConcreteFungible
        CHECK_ERROR(_readConcreteFungible_V13(c, &v->concreteFungible))
        break;
    case 11: // ConcreteNonFungible
        CHECK_ERROR(_readConcreteNonFungible_V13(c, &v->concreteNonFungible))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMultiAssetV1_V13(parser_context_t* c, pd_MultiAssetV1_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId_V13(c, &v->assetId))
    CHECK_ERROR(_readFungibility_V13(c, &v->fungibility))
    return parser_ok;
}

parser_error_t _readMultiLocationV0_V13(parser_context_t* c, pd_MultiLocationV0_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctions_V13(c, &v->junctions))
    return parser_ok;
}

parser_error_t _readMultiLocationV1_V13(parser_context_t* c, pd_MultiLocationV1_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->parents))
    CHECK_ERROR(_readJunctions_V13(c, &v->interior))
    return parser_ok;
}

parser_error_t _readNetworkId_V13(parser_context_t* c, pd_NetworkId_V13_t* v)
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

parser_error_t _readOpaqueCall_V13(parser_context_t* c, pd_OpaqueCall_V13_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readOverweightIndex_V13(parser_context_t* c, pd_OverweightIndex_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParaId_V13(parser_context_t* c, pd_ParaId_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParachainInherentData_V13(parser_context_t* c, pd_ParachainInherentData_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V13(parser_context_t* c, pd_Perbill_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPlurality_V13(parser_context_t* c, pd_Plurality_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyId_V13(c, &v->id))
    CHECK_ERROR(_readBodyPart_V13(c, &v->part))
    return parser_ok;
}

parser_error_t _readPrice_V13(parser_context_t* c, pd_Price_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readProxyType_V13(parser_context_t* c, pd_ProxyType_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readQueryId_V13(parser_context_t* c, pd_QueryId_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readRate_V13(parser_context_t* c, pd_Rate_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRatio_V13(parser_context_t* c, pd_Ratio_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readReferendumIndex_V13(parser_context_t* c, pd_ReferendumIndex_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V13(parser_context_t* c, pd_RegistrarIndex_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readResponse_V13(parser_context_t* c, pd_Response_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestinationAccountIdOfT_V13(parser_context_t* c, pd_RewardDestinationAccountIdOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V13(parser_context_t* c, pd_RewardDestination_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId_V13(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readStakingLedgerAccountIdBalanceOfT_V13(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStreamId_V13(parser_context_t* c, pd_StreamId_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTeleAccount_V13(parser_context_t* c, pd_TeleAccount_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTimepoint_V13(parser_context_t* c, pd_Timepoint_V13_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTimestamp_V13(parser_context_t* c, pd_Timestamp_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleAccountIdData_V13(parser_context_t* c, pd_TupleAccountIdData_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleCurrencyIdBalance_V13(parser_context_t* c, pd_TupleCurrencyIdBalance_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleOracleKeyOracleValue_V13(parser_context_t* c, pd_TupleOracleKeyOracleValue_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readUpwardMessage_V13(parser_context_t* c, pd_UpwardMessage_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVestingScheduleOf_V13(parser_context_t* c, pd_VestingScheduleOf_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBlockNumber(c, &v->start))
    CHECK_ERROR(_readBlockNumber(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->periodCount))
    CHECK_ERROR(_readCompactu128(c, &v->perPeriod));
    return parser_ok;
}

parser_error_t _readVote_V13(parser_context_t* c, pd_Vote_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value & 0x7F) {
        return parser_value_out_of_range;
    }
    v->value = (v->value & 0x80u) >> 7u;

    return parser_ok;
}

parser_error_t _readWeightLimit_V13(parser_context_t* c, pd_WeightLimit_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readWeight_V13(parser_context_t* c, pd_Weight_V13_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readXcmCall_V13(parser_context_t* c, pd_XcmCall_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readXcmVersion_V13(parser_context_t* c, pd_XcmVersion_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readXcmWeightFeeMiscWeightBalanceOfT_V13(parser_context_t* c, pd_XcmWeightFeeMiscWeightBalanceOfT_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePeriodBlockNumber_V13(parser_context_t* c, pd_schedulePeriodBlockNumber_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePriority_V13(parser_context_t* c, pd_schedulePriority_V13_t* v)
{
    return parser_not_supported;
}

parser_error_t _readu8_array_32_V13(parser_context_t* c, pd_u8_array_32_V13_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountIdOfT_V13(parser_context_t* c, pd_VecAccountIdOfT_V13_t* v) {
    GEN_DEF_READVECTOR(AccountIdOfT_V13)
}

parser_error_t _readVecAccountId_V13(parser_context_t* c, pd_VecAccountId_V13_t* v) {
    GEN_DEF_READVECTOR(AccountId_V13)
}

parser_error_t _readVecAssetIdOfTI_V13(parser_context_t* c, pd_VecAssetIdOfTI_V13_t* v) {
    GEN_DEF_READVECTOR(AssetIdOfTI_V13)
}

parser_error_t _readVecKeyValue_V13(parser_context_t* c, pd_VecKeyValue_V13_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V13)
}

parser_error_t _readVecKey_V13(parser_context_t* c, pd_VecKey_V13_t* v) {
    GEN_DEF_READVECTOR(Key_V13)
}

parser_error_t _readVecMultiAssetV0_V13(parser_context_t* c, pd_VecMultiAssetV0_V13_t* v) {
    GEN_DEF_READVECTOR(MultiAssetV0_V13)
}

parser_error_t _readVecMultiAssetV1_V13(parser_context_t* c, pd_VecMultiAssetV1_V13_t* v) {
    GEN_DEF_READVECTOR(MultiAssetV1_V13)
}

parser_error_t _readVecTupleAccountIdData_V13(parser_context_t* c, pd_VecTupleAccountIdData_V13_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V13)
}

parser_error_t _readVecTupleCurrencyIdBalance_V13(parser_context_t* c, pd_VecTupleCurrencyIdBalance_V13_t* v) {
    GEN_DEF_READVECTOR(TupleCurrencyIdBalance_V13)
}

parser_error_t _readVecTupleOracleKeyOracleValue_V13(parser_context_t* c, pd_VecTupleOracleKeyOracleValue_V13_t* v) {
    GEN_DEF_READVECTOR(TupleOracleKeyOracleValue_V13)
}

parser_error_t _readVecVestingScheduleOf_V13(parser_context_t* c, pd_VecVestingScheduleOf_V13_t* v) {
    GEN_DEF_READVECTOR(VestingScheduleOf_V13)
}

parser_error_t _readOptionAccountId_V13(parser_context_t* c, pd_OptionAccountId_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBalanceOfT_V13(parser_context_t* c, pd_OptionBalanceOfT_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBalanceOfT_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBlockNumberForT_V13(parser_context_t* c, pd_OptionBlockNumberForT_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBlockNumberForT_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionContributionStrategy_V13(parser_context_t* c, pd_OptionContributionStrategy_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readContributionStrategy_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V13(parser_context_t* c, pd_OptionProxyType_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V13(parser_context_t* c, pd_OptionReferendumIndex_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V13(parser_context_t* c, pd_OptionTimepoint_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionXcmVersion_V13(parser_context_t* c, pd_OptionXcmVersion_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readXcmVersion_V13(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionschedulePeriodBlockNumber_V13(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V13_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readschedulePeriodBlockNumber_V13(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAbstractFungible_V13(
    const pd_AbstractFungible_V13_t* v,
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

parser_error_t _toStringAbstractNonFungible_V13(
    const pd_AbstractNonFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringVecu8(&v->_class, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetInstance_V13(&v->instance, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringAssetInstance_V13(&v->instance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountId32_V13(
    const pd_AccountId32_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V13(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32_V13(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V13(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32_V13(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIdOfT_V13(
    const pd_AccountIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAccountId_V13(
    const pd_AccountId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex64_V13(
    const pd_AccountIndex64_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V13(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V13(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20_V13(
    const pd_AccountKey20_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId_V13(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId_V13(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountOfT_V13(
    const pd_AccountOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAccountVoteSplit_V13(
    const pd_AccountVoteSplit_V13_t* v,
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

parser_error_t _toStringAccountVoteStandard_V13(
    const pd_AccountVoteStandard_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote_V13(&v->vote, outValue, outValueLen, 0, &pages[1]))
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
        CHECK_ERROR(_toStringVote_V13(&v->vote, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote_V13(
    const pd_AccountVote_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringAccountVoteStandard_V13(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1:
        CHECK_ERROR(_toStringAccountVoteSplit_V13(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringAssetIdOfTIAssetIdOfTI_V13(
    const pd_AssetIdOfTIAssetIdOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAssetIdOfTI_V13(
    const pd_AssetIdOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdOfT_V13(
    const pd_AssetIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetId_V13(
    const pd_AssetId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Concrete
        CHECK_ERROR(_toStringBoxVersionedMultiLocation_V13(&v->concrete, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Abstract
        CHECK_ERROR(_toStringVecu8(&v->abstract, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAssetInstance_V13(
    const pd_AssetInstance_V13_t* v,
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

parser_error_t _toStringAssetType_V13(
    const pd_AssetType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBalanceOfTIBalanceOfTI_V13(
    const pd_BalanceOfTIBalanceOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBalanceOfT_V13(
    const pd_BalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBlockNumberForT_V13(
    const pd_BlockNumberForT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBodyId_V13(
    const pd_BodyId_V13_t* v,
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

parser_error_t _toStringBodyPart_V13(
    const pd_BodyPart_V13_t* v,
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
        CHECK_ERROR(_toStringFraction_V13(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AtLeastProportion
        // Print something?
        CHECK_ERROR(_toStringFraction_V13(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // MoreThanProportion
        // Print something?
        CHECK_ERROR(_toStringFraction_V13(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoxCallIdOfT_V13(
    const pd_BoxCallIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxCallOrHashOfT_V13(
    const pd_BoxCallOrHashOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V13(
    const pd_BoxIdentityInfoMaxAdditionalFields_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxMultiLocation_V13(
    const pd_BoxMultiLocation_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxPalletsOrigin_V13(
    const pd_BoxPalletsOrigin_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiAsset_V13(
    const pd_BoxVersionedMultiAsset_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiAssetV0_V13(&v->multiassetV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiAssetV1_V13(&v->multiassetV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiAssets_V13(
    const pd_BoxVersionedMultiAssets_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringVecMultiAssetV0_V13(&v->vecMultiassetV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringVecMultiAssetV1_V13(&v->vecMultiassetV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiLocation_V13(
    const pd_BoxVersionedMultiLocation_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiLocationV0_V13(&v->multilocationV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiLocationV1_V13(&v->multilocationV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V13(
    const pd_BoxVersionedXcmTasSysConfigCall_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTuple_V13(
    const pd_BoxVersionedXcmTuple_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBridgeToken_V13(
    const pd_BridgeToken_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBridgeType_V13(
    const pd_BridgeType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V13(
    const pd_CallHashOf_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChainId_V13(
    const pd_ChainId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringChainNonce_V13(
    const pd_ChainNonce_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCompactAccountIndex_V13(
    const pd_CompactAccountIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConcreteFungible_V13(
    const pd_ConcreteFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiLocationV0_V13(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiLocationV0_V13(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringConcreteNonFungible_V13(
    const pd_ConcreteNonFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiLocationV0_V13(&v->_class, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetInstance_V13(&v->instance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiLocationV0_V13(&v->_class, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetInstance_V13(&v->instance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringContributionStrategy_V13(
    const pd_ContributionStrategy_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringConviction_V13(
    const pd_Conviction_V13_t* v,
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

parser_error_t _toStringCurrencyId_V13(
    const pd_CurrencyId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDerivativeIndex_V13(
    const pd_DerivativeIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDestroyWitness_V13(
    const pd_DestroyWitness_V13_t* v,
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

parser_error_t _toStringDoubleEncodedTuple_V13(
    const pd_DoubleEncodedTuple_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V13(
    const pd_EraIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringFraction_V13(
    const pd_Fraction_V13_t* v,
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

parser_error_t _toStringFungibility_V13(
    const pd_Fungibility_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Undefined
        CHECK_ERROR(_toStringFungible_V13(&v->fungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringAssetInstance_V13(&v->nonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringFungible_V13(
    const pd_Fungible_V13_t* v,
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

parser_error_t _toStringIdentityFields_V13(
    const pd_IdentityFields_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringInterestRateModel_V13(
    const pd_InterestRateModel_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringJudgementBalanceOfT_V13(
    const pd_JudgementBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringJunctionX1_V13(
    const pd_JunctionX1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX2_V13(
    const pd_JunctionX2_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX3_V13(
    const pd_JunctionX3_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX4_V13(
    const pd_JunctionX4_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX5_V13(
    const pd_JunctionX5_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX6_V13(
    const pd_JunctionX6_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX7_V13(
    const pd_JunctionX7_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionX8_V13(
    const pd_JunctionX8_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunction_V13(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunction_V13(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunction_V13(
    const pd_Junction_V13_t* v,
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
        CHECK_ERROR(_toStringAccountId32_V13(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64_V13(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20_V13(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
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
        CHECK_ERROR(_toStringPlurality_V13(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctions_V13(
    const pd_Junctions_V13_t* v,
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
        CHECK_ERROR(_toStringJunctionX1_V13(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionX2_V13(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionX3_V13(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionX4_V13(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionX5_V13(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionX6_V13(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionX7_V13(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionX8_V13(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringKeyValue_V13(
    const pd_KeyValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V13(
    const pd_Key_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V13(
    const pd_Keys_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLeasePeriod_V13(
    const pd_LeasePeriod_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupasStaticLookupSource_V13(
    const pd_LookupasStaticLookupSource_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V13(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V13(&v->index, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringMarketBalanceOfT_V13(
    const pd_MarketBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMemberCount_V13(
    const pd_MemberCount_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiAssetV0_V13(
    const pd_MultiAssetV0_V13_t* v,
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
        CHECK_ERROR(_toStringMultiLocationV0_V13(&v->concrete, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // AbstractFungible
        CHECK_ERROR(_toStringAbstractFungible_V13(&v->abstractFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 9: // AbstractNonFungible
        CHECK_ERROR(_toStringAbstractNonFungible_V13(&v->abstractNonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 10: // ConcreteFungible
        CHECK_ERROR(_toStringConcreteFungible_V13(&v->concreteFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 11: // ConcreteNonFungible
        CHECK_ERROR(_toStringConcreteNonFungible_V13(&v->concreteNonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringMultiAssetV1_V13(
    const pd_MultiAssetV1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetId_V13(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringFungibility_V13(&v->fungibility, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId_V13(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringFungibility_V13(&v->fungibility, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMultiLocationV0_V13(
    const pd_MultiLocationV0_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringJunctions_V13(&v->junctions, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringMultiLocationV1_V13(
    const pd_MultiLocationV1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctions_V13(&v->interior, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringJunctions_V13(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNetworkId_V13(
    const pd_NetworkId_V13_t* v,
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

parser_error_t _toStringOpaqueCall_V13(
    const pd_OpaqueCall_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex_V13(
    const pd_OverweightIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParaId_V13(
    const pd_ParaId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParachainInherentData_V13(
    const pd_ParachainInherentData_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V13(
    const pd_Perbill_V13_t* v,
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

parser_error_t _toStringPlurality_V13(
    const pd_Plurality_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyId_V13(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart_V13(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyId_V13(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart_V13(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPrice_V13(
    const pd_Price_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringProxyType_V13(
    const pd_ProxyType_V13_t* v,
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
        snprintf(outValue, outValueLen, "NonTransfer");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Governance");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Staking");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringQueryId_V13(
    const pd_QueryId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRate_V13(
    const pd_Rate_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRatio_V13(
    const pd_Ratio_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringReferendumIndex_V13(
    const pd_ReferendumIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V13(
    const pd_RegistrarIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringResponse_V13(
    const pd_Response_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestinationAccountIdOfT_V13(
    const pd_RewardDestinationAccountIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V13(
    const pd_RewardDestination_V13_t* v,
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
        CHECK_ERROR(_toStringAccountId_V13(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V13(
    const pd_StakingLedgerAccountIdBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStreamId_V13(
    const pd_StreamId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTeleAccount_V13(
    const pd_TeleAccount_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint_V13(
    const pd_Timepoint_V13_t* v,
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

parser_error_t _toStringTimestamp_V13(
    const pd_Timestamp_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleAccountIdData_V13(
    const pd_TupleAccountIdData_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleCurrencyIdBalance_V13(
    const pd_TupleCurrencyIdBalance_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleOracleKeyOracleValue_V13(
    const pd_TupleOracleKeyOracleValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringUpwardMessage_V13(
    const pd_UpwardMessage_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVestingScheduleOf_V13(
    const pd_VestingScheduleOf_V13_t* v,
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

parser_error_t _toStringVote_V13(
    const pd_Vote_V13_t* v,
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

parser_error_t _toStringWeightLimit_V13(
    const pd_WeightLimit_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringWeight_V13(
    const pd_Weight_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcmCall_V13(
    const pd_XcmCall_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringXcmVersion_V13(
    const pd_XcmVersion_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringXcmWeightFeeMiscWeightBalanceOfT_V13(
    const pd_XcmWeightFeeMiscWeightBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePeriodBlockNumber_V13(
    const pd_schedulePeriodBlockNumber_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePriority_V13(
    const pd_schedulePriority_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringu8_array_32_V13(
    const pd_u8_array_32_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccountIdOfT_V13(
    const pd_VecAccountIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountIdOfT_V13);
}

parser_error_t _toStringVecAccountId_V13(
    const pd_VecAccountId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V13);
}

parser_error_t _toStringVecAssetIdOfTI_V13(
    const pd_VecAssetIdOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdOfTI_V13);
}

parser_error_t _toStringVecKeyValue_V13(
    const pd_VecKeyValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V13);
}

parser_error_t _toStringVecKey_V13(
    const pd_VecKey_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V13);
}

parser_error_t _toStringVecMultiAssetV0_V13(
    const pd_VecMultiAssetV0_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAssetV0_V13);
}

parser_error_t _toStringVecMultiAssetV1_V13(
    const pd_VecMultiAssetV1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAssetV1_V13);
}

parser_error_t _toStringVecTupleAccountIdData_V13(
    const pd_VecTupleAccountIdData_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V13);
}

parser_error_t _toStringVecTupleCurrencyIdBalance_V13(
    const pd_VecTupleCurrencyIdBalance_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleCurrencyIdBalance_V13);
}

parser_error_t _toStringVecTupleOracleKeyOracleValue_V13(
    const pd_VecTupleOracleKeyOracleValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleOracleKeyOracleValue_V13);
}

parser_error_t _toStringVecVestingScheduleOf_V13(
    const pd_VecVestingScheduleOf_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VestingScheduleOf_V13);
}

parser_error_t _toStringOptionAccountId_V13(
    const pd_OptionAccountId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionBalanceOfT_V13(
    const pd_OptionBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBalanceOfT_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionBlockNumberForT_V13(
    const pd_OptionBlockNumberForT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBlockNumberForT_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionContributionStrategy_V13(
    const pd_OptionContributionStrategy_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringContributionStrategy_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V13(
    const pd_OptionProxyType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V13(
    const pd_OptionReferendumIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V13(
    const pd_OptionTimepoint_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionXcmVersion_V13(
    const pd_OptionXcmVersion_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringXcmVersion_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionschedulePeriodBlockNumber_V13(
    const pd_OptionschedulePeriodBlockNumber_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringschedulePeriodBlockNumber_V13(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
