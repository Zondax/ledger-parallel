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
parser_error_t _readAbstractFungible_V15(parser_context_t* c, pd_AbstractFungible_V15_t* v);
parser_error_t _readAbstractNonFungible_V15(parser_context_t* c, pd_AbstractNonFungible_V15_t* v);
parser_error_t _readAccountId32_V15(parser_context_t* c, pd_AccountId32_V15_t* v);
parser_error_t _readAccountIdOfT_V15(parser_context_t* c, pd_AccountIdOfT_V15_t* v);
parser_error_t _readAccountId_V15(parser_context_t* c, pd_AccountId_V15_t* v);
parser_error_t _readAccountIndex64_V15(parser_context_t* c, pd_AccountIndex64_V15_t* v);
parser_error_t _readAccountKey20_V15(parser_context_t* c, pd_AccountKey20_V15_t* v);
parser_error_t _readAccountOfT_V15(parser_context_t* c, pd_AccountOfT_V15_t* v);
parser_error_t _readAccountVoteSplit_V15(parser_context_t* c, pd_AccountVoteSplit_V15_t* v);
parser_error_t _readAccountVoteStandard_V15(parser_context_t* c, pd_AccountVoteStandard_V15_t* v);
parser_error_t _readAccountVote_V15(parser_context_t* c, pd_AccountVote_V15_t* v);
parser_error_t _readAssetIdOfAssetIdOf_V15(parser_context_t* c, pd_AssetIdOfAssetIdOf_V15_t* v);
parser_error_t _readAssetIdOfT_V15(parser_context_t* c, pd_AssetIdOfT_V15_t* v);
parser_error_t _readAssetIdOf_V15(parser_context_t* c, pd_AssetIdOf_V15_t* v);
parser_error_t _readAssetId_V15(parser_context_t* c, pd_AssetId_V15_t* v);
parser_error_t _readAssetInstance_V15(parser_context_t* c, pd_AssetInstance_V15_t* v);
parser_error_t _readAssetType_V15(parser_context_t* c, pd_AssetType_V15_t* v);
parser_error_t _readBalanceOfBalanceOf_V15(parser_context_t* c, pd_BalanceOfBalanceOf_V15_t* v);
parser_error_t _readBalanceOfT_V15(parser_context_t* c, pd_BalanceOfT_V15_t* v);
parser_error_t _readBlockNumberForT_V15(parser_context_t* c, pd_BlockNumberForT_V15_t* v);
parser_error_t _readBodyId_V15(parser_context_t* c, pd_BodyId_V15_t* v);
parser_error_t _readBodyPart_V15(parser_context_t* c, pd_BodyPart_V15_t* v);
parser_error_t _readBoxCallIdOfT_V15(parser_context_t* c, pd_BoxCallIdOfT_V15_t* v);
parser_error_t _readBoxCallOrHashOfT_V15(parser_context_t* c, pd_BoxCallOrHashOfT_V15_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V15(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V15_t* v);
parser_error_t _readBoxMultiLocation_V15(parser_context_t* c, pd_BoxMultiLocation_V15_t* v);
parser_error_t _readBoxPalletsOrigin_V15(parser_context_t* c, pd_BoxPalletsOrigin_V15_t* v);
parser_error_t _readBoxVersionedMultiAsset_V15(parser_context_t* c, pd_BoxVersionedMultiAsset_V15_t* v);
parser_error_t _readBoxVersionedMultiAssets_V15(parser_context_t* c, pd_BoxVersionedMultiAssets_V15_t* v);
parser_error_t _readBoxVersionedMultiLocation_V15(parser_context_t* c, pd_BoxVersionedMultiLocation_V15_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V15(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V15_t* v);
parser_error_t _readBoxVersionedXcmTuple_V15(parser_context_t* c, pd_BoxVersionedXcmTuple_V15_t* v);
parser_error_t _readBridgeToken_V15(parser_context_t* c, pd_BridgeToken_V15_t* v);
parser_error_t _readBridgeType_V15(parser_context_t* c, pd_BridgeType_V15_t* v);
parser_error_t _readCallHashOf_V15(parser_context_t* c, pd_CallHashOf_V15_t* v);
parser_error_t _readChainId_V15(parser_context_t* c, pd_ChainId_V15_t* v);
parser_error_t _readChainNonce_V15(parser_context_t* c, pd_ChainNonce_V15_t* v);
parser_error_t _readCompactAccountIndex_V15(parser_context_t* c, pd_CompactAccountIndex_V15_t* v);
parser_error_t _readConcreteFungible_V15(parser_context_t* c, pd_ConcreteFungible_V15_t* v);
parser_error_t _readConcreteNonFungible_V15(parser_context_t* c, pd_ConcreteNonFungible_V15_t* v);
parser_error_t _readContributionStrategy_V15(parser_context_t* c, pd_ContributionStrategy_V15_t* v);
parser_error_t _readConviction_V15(parser_context_t* c, pd_Conviction_V15_t* v);
parser_error_t _readCurrencyId_V15(parser_context_t* c, pd_CurrencyId_V15_t* v);
parser_error_t _readCurveModel_V15(parser_context_t* c, pd_CurveModel_V15_t* v);
parser_error_t _readDerivativeIndex_V15(parser_context_t* c, pd_DerivativeIndex_V15_t* v);
parser_error_t _readDestroyWitness_V15(parser_context_t* c, pd_DestroyWitness_V15_t* v);
parser_error_t _readDoubleEncodedTuple_V15(parser_context_t* c, pd_DoubleEncodedTuple_V15_t* v);
parser_error_t _readEraIndex_V15(parser_context_t* c, pd_EraIndex_V15_t* v);
parser_error_t _readFraction_V15(parser_context_t* c, pd_Fraction_V15_t* v);
parser_error_t _readFungibility_V15(parser_context_t* c, pd_Fungibility_V15_t* v);
parser_error_t _readFungible_V15(parser_context_t* c, pd_Fungible_V15_t* v);
parser_error_t _readIdentityFields_V15(parser_context_t* c, pd_IdentityFields_V15_t* v);
parser_error_t _readInterestRateModel_V15(parser_context_t* c, pd_InterestRateModel_V15_t* v);
parser_error_t _readJudgementBalanceOfT_V15(parser_context_t* c, pd_JudgementBalanceOfT_V15_t* v);
parser_error_t _readJumpModel_V15(parser_context_t* c, pd_JumpModel_V15_t* v);
parser_error_t _readJunctionX1_V15(parser_context_t* c, pd_JunctionX1_V15_t* v);
parser_error_t _readJunctionX2_V15(parser_context_t* c, pd_JunctionX2_V15_t* v);
parser_error_t _readJunctionX3_V15(parser_context_t* c, pd_JunctionX3_V15_t* v);
parser_error_t _readJunctionX4_V15(parser_context_t* c, pd_JunctionX4_V15_t* v);
parser_error_t _readJunctionX5_V15(parser_context_t* c, pd_JunctionX5_V15_t* v);
parser_error_t _readJunctionX6_V15(parser_context_t* c, pd_JunctionX6_V15_t* v);
parser_error_t _readJunctionX7_V15(parser_context_t* c, pd_JunctionX7_V15_t* v);
parser_error_t _readJunctionX8_V15(parser_context_t* c, pd_JunctionX8_V15_t* v);
parser_error_t _readJunction_V15(parser_context_t* c, pd_Junction_V15_t* v);
parser_error_t _readJunctions_V15(parser_context_t* c, pd_Junctions_V15_t* v);
parser_error_t _readKeyValue_V15(parser_context_t* c, pd_KeyValue_V15_t* v);
parser_error_t _readKey_V15(parser_context_t* c, pd_Key_V15_t* v);
parser_error_t _readKeys_V15(parser_context_t* c, pd_Keys_V15_t* v);
parser_error_t _readLeasePeriod_V15(parser_context_t* c, pd_LeasePeriod_V15_t* v);
parser_error_t _readLookupasStaticLookupSource_V15(parser_context_t* c, pd_LookupasStaticLookupSource_V15_t* v);
parser_error_t _readMarketBalanceOfT_V15(parser_context_t* c, pd_MarketBalanceOfT_V15_t* v);
parser_error_t _readMarketState_V15(parser_context_t* c, pd_MarketState_V15_t* v);
parser_error_t _readMemberCount_V15(parser_context_t* c, pd_MemberCount_V15_t* v);
parser_error_t _readMultiAssetV0_V15(parser_context_t* c, pd_MultiAssetV0_V15_t* v);
parser_error_t _readMultiAssetV1_V15(parser_context_t* c, pd_MultiAssetV1_V15_t* v);
parser_error_t _readMultiLocationV0_V15(parser_context_t* c, pd_MultiLocationV0_V15_t* v);
parser_error_t _readMultiLocationV1_V15(parser_context_t* c, pd_MultiLocationV1_V15_t* v);
parser_error_t _readNetworkId_V15(parser_context_t* c, pd_NetworkId_V15_t* v);
parser_error_t _readOpaqueCall_V15(parser_context_t* c, pd_OpaqueCall_V15_t* v);
parser_error_t _readOptionAccountId_V15(parser_context_t* c, pd_OptionAccountId_V15_t* v);
parser_error_t _readOptionBalanceOfT_V15(parser_context_t* c, pd_OptionBalanceOfT_V15_t* v);
parser_error_t _readOptionBlockNumberForT_V15(parser_context_t* c, pd_OptionBlockNumberForT_V15_t* v);
parser_error_t _readOptionContributionStrategy_V15(parser_context_t* c, pd_OptionContributionStrategy_V15_t* v);
parser_error_t _readOptionProxyType_V15(parser_context_t* c, pd_OptionProxyType_V15_t* v);
parser_error_t _readOptionReferendumIndex_V15(parser_context_t* c, pd_OptionReferendumIndex_V15_t* v);
parser_error_t _readOptionTimepoint_V15(parser_context_t* c, pd_OptionTimepoint_V15_t* v);
parser_error_t _readOptionXcmVersion_V15(parser_context_t* c, pd_OptionXcmVersion_V15_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V15(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V15_t* v);
parser_error_t _readOverweightIndex_V15(parser_context_t* c, pd_OverweightIndex_V15_t* v);
parser_error_t _readParaId_V15(parser_context_t* c, pd_ParaId_V15_t* v);
parser_error_t _readParachainInherentData_V15(parser_context_t* c, pd_ParachainInherentData_V15_t* v);
parser_error_t _readPerbill_V15(parser_context_t* c, pd_Perbill_V15_t* v);
parser_error_t _readPlurality_V15(parser_context_t* c, pd_Plurality_V15_t* v);
parser_error_t _readPrice_V15(parser_context_t* c, pd_Price_V15_t* v);
parser_error_t _readProxyType_V15(parser_context_t* c, pd_ProxyType_V15_t* v);
parser_error_t _readQueryId_V15(parser_context_t* c, pd_QueryId_V15_t* v);
parser_error_t _readRate_V15(parser_context_t* c, pd_Rate_V15_t* v);
parser_error_t _readRatio_V15(parser_context_t* c, pd_Ratio_V15_t* v);
parser_error_t _readReferendumIndex_V15(parser_context_t* c, pd_ReferendumIndex_V15_t* v);
parser_error_t _readRegistrarIndex_V15(parser_context_t* c, pd_RegistrarIndex_V15_t* v);
parser_error_t _readResponse_V15(parser_context_t* c, pd_Response_V15_t* v);
parser_error_t _readRewardDestinationAccountIdOfT_V15(parser_context_t* c, pd_RewardDestinationAccountIdOfT_V15_t* v);
parser_error_t _readRewardDestination_V15(parser_context_t* c, pd_RewardDestination_V15_t* v);
parser_error_t _readStakingLedgerAccountIdBalanceOfT_V15(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V15_t* v);
parser_error_t _readStreamId_V15(parser_context_t* c, pd_StreamId_V15_t* v);
parser_error_t _readTeleAccount_V15(parser_context_t* c, pd_TeleAccount_V15_t* v);
parser_error_t _readTimepoint_V15(parser_context_t* c, pd_Timepoint_V15_t* v);
parser_error_t _readTimestamp_V15(parser_context_t* c, pd_Timestamp_V15_t* v);
parser_error_t _readTupleAccountIdData_V15(parser_context_t* c, pd_TupleAccountIdData_V15_t* v);
parser_error_t _readTupleCurrencyIdBalance_V15(parser_context_t* c, pd_TupleCurrencyIdBalance_V15_t* v);
parser_error_t _readTupleOracleKeyOracleValue_V15(parser_context_t* c, pd_TupleOracleKeyOracleValue_V15_t* v);
parser_error_t _readUnlockChunk_V15(parser_context_t* c, pd_UnlockChunk_V15_t* v);
parser_error_t _readUpwardMessage_V15(parser_context_t* c, pd_UpwardMessage_V15_t* v);
parser_error_t _readVecAccountIdOfT_V15(parser_context_t* c, pd_VecAccountIdOfT_V15_t* v);
parser_error_t _readVecAccountId_V15(parser_context_t* c, pd_VecAccountId_V15_t* v);
parser_error_t _readVecAssetIdOf_V15(parser_context_t* c, pd_VecAssetIdOf_V15_t* v);
parser_error_t _readVecEraIndex_V15(parser_context_t* c, pd_VecEraIndex_V15_t* v);
parser_error_t _readVecKeyValue_V15(parser_context_t* c, pd_VecKeyValue_V15_t* v);
parser_error_t _readVecKey_V15(parser_context_t* c, pd_VecKey_V15_t* v);
parser_error_t _readVecMultiAssetV0_V15(parser_context_t* c, pd_VecMultiAssetV0_V15_t* v);
parser_error_t _readVecMultiAssetV1_V15(parser_context_t* c, pd_VecMultiAssetV1_V15_t* v);
parser_error_t _readVecTupleAccountIdData_V15(parser_context_t* c, pd_VecTupleAccountIdData_V15_t* v);
parser_error_t _readVecTupleCurrencyIdBalance_V15(parser_context_t* c, pd_VecTupleCurrencyIdBalance_V15_t* v);
parser_error_t _readVecTupleOracleKeyOracleValue_V15(parser_context_t* c, pd_VecTupleOracleKeyOracleValue_V15_t* v);
parser_error_t _readVecUnlockChunk_V15(parser_context_t* c, pd_VecUnlockChunk_V15_t* v);
parser_error_t _readVecVestingScheduleOf_V15(parser_context_t* c, pd_VecVestingScheduleOf_V15_t* v);
parser_error_t _readVestingScheduleOf_V15(parser_context_t* c, pd_VestingScheduleOf_V15_t* v);
parser_error_t _readVote_V15(parser_context_t* c, pd_Vote_V15_t* v);
parser_error_t _readWeightLimit_V15(parser_context_t* c, pd_WeightLimit_V15_t* v);
parser_error_t _readWeight_V15(parser_context_t* c, pd_Weight_V15_t* v);
parser_error_t _readXcmCall_V15(parser_context_t* c, pd_XcmCall_V15_t* v);
parser_error_t _readXcmVersion_V15(parser_context_t* c, pd_XcmVersion_V15_t* v);
parser_error_t _readXcmWeightFeeMiscWeightBalanceOfT_V15(parser_context_t* c, pd_XcmWeightFeeMiscWeightBalanceOfT_V15_t* v);
parser_error_t _readschedulePeriodBlockNumber_V15(parser_context_t* c, pd_schedulePeriodBlockNumber_V15_t* v);
parser_error_t _readschedulePriority_V15(parser_context_t* c, pd_schedulePriority_V15_t* v);
parser_error_t _readu8_array_32_V15(parser_context_t* c, pd_u8_array_32_V15_t* v);

// toString functions
parser_error_t _toStringAbstractFungible_V15(
    const pd_AbstractFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible_V15(
    const pd_AbstractNonFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V15(
    const pd_AccountId32_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdOfT_V15(
    const pd_AccountIdOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V15(
    const pd_AccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V15(
    const pd_AccountIndex64_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V15(
    const pd_AccountKey20_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountOfT_V15(
    const pd_AccountOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V15(
    const pd_AccountVoteSplit_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V15(
    const pd_AccountVoteStandard_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V15(
    const pd_AccountVote_V15_t* v,
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

parser_error_t _toStringAssetId_V15(
    const pd_AssetId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance_V15(
    const pd_AssetInstance_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V15(
    const pd_AssetType_V15_t* v,
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

parser_error_t _toStringBalanceOfT_V15(
    const pd_BalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBlockNumberForT_V15(
    const pd_BlockNumberForT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V15(
    const pd_BodyId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V15(
    const pd_BodyPart_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallIdOfT_V15(
    const pd_BoxCallIdOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V15(
    const pd_BoxCallOrHashOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V15(
    const pd_BoxIdentityInfoMaxAdditionalFields_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V15(
    const pd_BoxMultiLocation_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V15(
    const pd_BoxPalletsOrigin_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAsset_V15(
    const pd_BoxVersionedMultiAsset_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V15(
    const pd_BoxVersionedMultiAssets_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V15(
    const pd_BoxVersionedMultiLocation_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V15(
    const pd_BoxVersionedXcmTasSysConfigCall_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V15(
    const pd_BoxVersionedXcmTuple_V15_t* v,
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

parser_error_t _toStringConcreteFungible_V15(
    const pd_ConcreteFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible_V15(
    const pd_ConcreteNonFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringContributionStrategy_V15(
    const pd_ContributionStrategy_V15_t* v,
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

parser_error_t _toStringDoubleEncodedTuple_V15(
    const pd_DoubleEncodedTuple_V15_t* v,
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

parser_error_t _toStringFraction_V15(
    const pd_Fraction_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility_V15(
    const pd_Fungibility_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungible_V15(
    const pd_Fungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V15(
    const pd_IdentityFields_V15_t* v,
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

parser_error_t _toStringJudgementBalanceOfT_V15(
    const pd_JudgementBalanceOfT_V15_t* v,
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

parser_error_t _toStringJunctionX1_V15(
    const pd_JunctionX1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX2_V15(
    const pd_JunctionX2_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX3_V15(
    const pd_JunctionX3_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX4_V15(
    const pd_JunctionX4_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX5_V15(
    const pd_JunctionX5_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX6_V15(
    const pd_JunctionX6_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX7_V15(
    const pd_JunctionX7_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX8_V15(
    const pd_JunctionX8_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunction_V15(
    const pd_Junction_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctions_V15(
    const pd_Junctions_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V15(
    const pd_KeyValue_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V15(
    const pd_Key_V15_t* v,
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

parser_error_t _toStringLeasePeriod_V15(
    const pd_LeasePeriod_V15_t* v,
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

parser_error_t _toStringMultiAssetV0_V15(
    const pd_MultiAssetV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1_V15(
    const pd_MultiAssetV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V15(
    const pd_MultiLocationV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V15(
    const pd_MultiLocationV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V15(
    const pd_NetworkId_V15_t* v,
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

parser_error_t _toStringOptionBalanceOfT_V15(
    const pd_OptionBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBlockNumberForT_V15(
    const pd_OptionBlockNumberForT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionContributionStrategy_V15(
    const pd_OptionContributionStrategy_V15_t* v,
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

parser_error_t _toStringOptionReferendumIndex_V15(
    const pd_OptionReferendumIndex_V15_t* v,
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

parser_error_t _toStringOptionXcmVersion_V15(
    const pd_OptionXcmVersion_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V15(
    const pd_OptionschedulePeriodBlockNumber_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V15(
    const pd_OverweightIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V15(
    const pd_ParaId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V15(
    const pd_ParachainInherentData_V15_t* v,
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

parser_error_t _toStringPlurality_V15(
    const pd_Plurality_V15_t* v,
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

parser_error_t _toStringQueryId_V15(
    const pd_QueryId_V15_t* v,
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

parser_error_t _toStringResponse_V15(
    const pd_Response_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestinationAccountIdOfT_V15(
    const pd_RewardDestinationAccountIdOfT_V15_t* v,
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

parser_error_t _toStringStreamId_V15(
    const pd_StreamId_V15_t* v,
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

parser_error_t _toStringTimestamp_V15(
    const pd_Timestamp_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V15(
    const pd_TupleAccountIdData_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCurrencyIdBalance_V15(
    const pd_TupleCurrencyIdBalance_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleOracleKeyOracleValue_V15(
    const pd_TupleOracleKeyOracleValue_V15_t* v,
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

parser_error_t _toStringUpwardMessage_V15(
    const pd_UpwardMessage_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdOfT_V15(
    const pd_VecAccountIdOfT_V15_t* v,
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

parser_error_t _toStringVecKeyValue_V15(
    const pd_VecKeyValue_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V15(
    const pd_VecKey_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0_V15(
    const pd_VecMultiAssetV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1_V15(
    const pd_VecMultiAssetV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V15(
    const pd_VecTupleAccountIdData_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleCurrencyIdBalance_V15(
    const pd_VecTupleCurrencyIdBalance_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleOracleKeyOracleValue_V15(
    const pd_VecTupleOracleKeyOracleValue_V15_t* v,
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

parser_error_t _toStringVote_V15(
    const pd_Vote_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V15(
    const pd_WeightLimit_V15_t* v,
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

parser_error_t _toStringXcmCall_V15(
    const pd_XcmCall_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V15(
    const pd_XcmVersion_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmWeightFeeMiscWeightBalanceOfT_V15(
    const pd_XcmWeightFeeMiscWeightBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V15(
    const pd_schedulePeriodBlockNumber_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V15(
    const pd_schedulePriority_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V15(
    const pd_u8_array_32_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
