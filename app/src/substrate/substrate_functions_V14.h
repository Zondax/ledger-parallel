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
#include "substrate_methods_V14.h"
#include "substrate_types_V14.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAbstractFungible_V14(parser_context_t* c, pd_AbstractFungible_V14_t* v);
parser_error_t _readAbstractNonFungible_V14(parser_context_t* c, pd_AbstractNonFungible_V14_t* v);
parser_error_t _readAccountId32_V14(parser_context_t* c, pd_AccountId32_V14_t* v);
parser_error_t _readAccountIdOfT_V14(parser_context_t* c, pd_AccountIdOfT_V14_t* v);
parser_error_t _readAccountId_V14(parser_context_t* c, pd_AccountId_V14_t* v);
parser_error_t _readAccountIndex64_V14(parser_context_t* c, pd_AccountIndex64_V14_t* v);
parser_error_t _readAccountKey20_V14(parser_context_t* c, pd_AccountKey20_V14_t* v);
parser_error_t _readAccountOfT_V14(parser_context_t* c, pd_AccountOfT_V14_t* v);
parser_error_t _readAccountVoteSplit_V14(parser_context_t* c, pd_AccountVoteSplit_V14_t* v);
parser_error_t _readAccountVoteStandard_V14(parser_context_t* c, pd_AccountVoteStandard_V14_t* v);
parser_error_t _readAccountVote_V14(parser_context_t* c, pd_AccountVote_V14_t* v);
parser_error_t _readAssetIdOfAssetIdOf_V14(parser_context_t* c, pd_AssetIdOfAssetIdOf_V14_t* v);
parser_error_t _readAssetIdOfT_V14(parser_context_t* c, pd_AssetIdOfT_V14_t* v);
parser_error_t _readAssetIdOf_V14(parser_context_t* c, pd_AssetIdOf_V14_t* v);
parser_error_t _readAssetId_V14(parser_context_t* c, pd_AssetId_V14_t* v);
parser_error_t _readAssetInstance_V14(parser_context_t* c, pd_AssetInstance_V14_t* v);
parser_error_t _readAssetType_V14(parser_context_t* c, pd_AssetType_V14_t* v);
parser_error_t _readBalanceOfBalanceOf_V14(parser_context_t* c, pd_BalanceOfBalanceOf_V14_t* v);
parser_error_t _readBalanceOfT_V14(parser_context_t* c, pd_BalanceOfT_V14_t* v);
parser_error_t _readBlockNumberForT_V14(parser_context_t* c, pd_BlockNumberForT_V14_t* v);
parser_error_t _readBodyId_V14(parser_context_t* c, pd_BodyId_V14_t* v);
parser_error_t _readBodyPart_V14(parser_context_t* c, pd_BodyPart_V14_t* v);
parser_error_t _readBoxCallIdOfT_V14(parser_context_t* c, pd_BoxCallIdOfT_V14_t* v);
parser_error_t _readBoxCallOrHashOfT_V14(parser_context_t* c, pd_BoxCallOrHashOfT_V14_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V14(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V14_t* v);
parser_error_t _readBoxMultiLocation_V14(parser_context_t* c, pd_BoxMultiLocation_V14_t* v);
parser_error_t _readBoxPalletsOrigin_V14(parser_context_t* c, pd_BoxPalletsOrigin_V14_t* v);
parser_error_t _readBoxVersionedMultiAsset_V14(parser_context_t* c, pd_BoxVersionedMultiAsset_V14_t* v);
parser_error_t _readBoxVersionedMultiAssets_V14(parser_context_t* c, pd_BoxVersionedMultiAssets_V14_t* v);
parser_error_t _readBoxVersionedMultiLocation_V14(parser_context_t* c, pd_BoxVersionedMultiLocation_V14_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V14(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V14_t* v);
parser_error_t _readBoxVersionedXcmTuple_V14(parser_context_t* c, pd_BoxVersionedXcmTuple_V14_t* v);
parser_error_t _readBridgeToken_V14(parser_context_t* c, pd_BridgeToken_V14_t* v);
parser_error_t _readBridgeType_V14(parser_context_t* c, pd_BridgeType_V14_t* v);
parser_error_t _readCallHashOf_V14(parser_context_t* c, pd_CallHashOf_V14_t* v);
parser_error_t _readChainId_V14(parser_context_t* c, pd_ChainId_V14_t* v);
parser_error_t _readChainNonce_V14(parser_context_t* c, pd_ChainNonce_V14_t* v);
parser_error_t _readCompactAccountIndex_V14(parser_context_t* c, pd_CompactAccountIndex_V14_t* v);
parser_error_t _readConcreteFungible_V14(parser_context_t* c, pd_ConcreteFungible_V14_t* v);
parser_error_t _readConcreteNonFungible_V14(parser_context_t* c, pd_ConcreteNonFungible_V14_t* v);
parser_error_t _readContributionStrategy_V14(parser_context_t* c, pd_ContributionStrategy_V14_t* v);
parser_error_t _readConviction_V14(parser_context_t* c, pd_Conviction_V14_t* v);
parser_error_t _readCurrencyId_V14(parser_context_t* c, pd_CurrencyId_V14_t* v);
parser_error_t _readCurveModel_V14(parser_context_t* c, pd_CurveModel_V14_t* v);
parser_error_t _readDerivativeIndex_V14(parser_context_t* c, pd_DerivativeIndex_V14_t* v);
parser_error_t _readDestroyWitness_V14(parser_context_t* c, pd_DestroyWitness_V14_t* v);
parser_error_t _readDoubleEncodedTuple_V14(parser_context_t* c, pd_DoubleEncodedTuple_V14_t* v);
parser_error_t _readEraIndex_V14(parser_context_t* c, pd_EraIndex_V14_t* v);
parser_error_t _readFraction_V14(parser_context_t* c, pd_Fraction_V14_t* v);
parser_error_t _readFungibility_V14(parser_context_t* c, pd_Fungibility_V14_t* v);
parser_error_t _readFungible_V14(parser_context_t* c, pd_Fungible_V14_t* v);
parser_error_t _readIdentityFields_V14(parser_context_t* c, pd_IdentityFields_V14_t* v);
parser_error_t _readInterestRateModel_V14(parser_context_t* c, pd_InterestRateModel_V14_t* v);
parser_error_t _readJudgementBalanceOfT_V14(parser_context_t* c, pd_JudgementBalanceOfT_V14_t* v);
parser_error_t _readJumpModel_V14(parser_context_t* c, pd_JumpModel_V14_t* v);
parser_error_t _readJunctionX1_V14(parser_context_t* c, pd_JunctionX1_V14_t* v);
parser_error_t _readJunctionX2_V14(parser_context_t* c, pd_JunctionX2_V14_t* v);
parser_error_t _readJunctionX3_V14(parser_context_t* c, pd_JunctionX3_V14_t* v);
parser_error_t _readJunctionX4_V14(parser_context_t* c, pd_JunctionX4_V14_t* v);
parser_error_t _readJunctionX5_V14(parser_context_t* c, pd_JunctionX5_V14_t* v);
parser_error_t _readJunctionX6_V14(parser_context_t* c, pd_JunctionX6_V14_t* v);
parser_error_t _readJunctionX7_V14(parser_context_t* c, pd_JunctionX7_V14_t* v);
parser_error_t _readJunctionX8_V14(parser_context_t* c, pd_JunctionX8_V14_t* v);
parser_error_t _readJunction_V14(parser_context_t* c, pd_Junction_V14_t* v);
parser_error_t _readJunctions_V14(parser_context_t* c, pd_Junctions_V14_t* v);
parser_error_t _readKeyValue_V14(parser_context_t* c, pd_KeyValue_V14_t* v);
parser_error_t _readKey_V14(parser_context_t* c, pd_Key_V14_t* v);
parser_error_t _readKeys_V14(parser_context_t* c, pd_Keys_V14_t* v);
parser_error_t _readLeasePeriod_V14(parser_context_t* c, pd_LeasePeriod_V14_t* v);
parser_error_t _readLookupasStaticLookupSource_V14(parser_context_t* c, pd_LookupasStaticLookupSource_V14_t* v);
parser_error_t _readMarketBalanceOfT_V14(parser_context_t* c, pd_MarketBalanceOfT_V14_t* v);
parser_error_t _readMarketState_V14(parser_context_t* c, pd_MarketState_V14_t* v);
parser_error_t _readMemberCount_V14(parser_context_t* c, pd_MemberCount_V14_t* v);
parser_error_t _readMultiAssetV0_V14(parser_context_t* c, pd_MultiAssetV0_V14_t* v);
parser_error_t _readMultiAssetV1_V14(parser_context_t* c, pd_MultiAssetV1_V14_t* v);
parser_error_t _readMultiLocationV0_V14(parser_context_t* c, pd_MultiLocationV0_V14_t* v);
parser_error_t _readMultiLocationV1_V14(parser_context_t* c, pd_MultiLocationV1_V14_t* v);
parser_error_t _readNetworkId_V14(parser_context_t* c, pd_NetworkId_V14_t* v);
parser_error_t _readOpaqueCall_V14(parser_context_t* c, pd_OpaqueCall_V14_t* v);
parser_error_t _readOptionAccountId_V14(parser_context_t* c, pd_OptionAccountId_V14_t* v);
parser_error_t _readOptionBalanceOfT_V14(parser_context_t* c, pd_OptionBalanceOfT_V14_t* v);
parser_error_t _readOptionBlockNumberForT_V14(parser_context_t* c, pd_OptionBlockNumberForT_V14_t* v);
parser_error_t _readOptionContributionStrategy_V14(parser_context_t* c, pd_OptionContributionStrategy_V14_t* v);
parser_error_t _readOptionProxyType_V14(parser_context_t* c, pd_OptionProxyType_V14_t* v);
parser_error_t _readOptionReferendumIndex_V14(parser_context_t* c, pd_OptionReferendumIndex_V14_t* v);
parser_error_t _readOptionTimepoint_V14(parser_context_t* c, pd_OptionTimepoint_V14_t* v);
parser_error_t _readOptionXcmVersion_V14(parser_context_t* c, pd_OptionXcmVersion_V14_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V14(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V14_t* v);
parser_error_t _readOverweightIndex_V14(parser_context_t* c, pd_OverweightIndex_V14_t* v);
parser_error_t _readParaId_V14(parser_context_t* c, pd_ParaId_V14_t* v);
parser_error_t _readParachainInherentData_V14(parser_context_t* c, pd_ParachainInherentData_V14_t* v);
parser_error_t _readPerbill_V14(parser_context_t* c, pd_Perbill_V14_t* v);
parser_error_t _readPlurality_V14(parser_context_t* c, pd_Plurality_V14_t* v);
parser_error_t _readPrice_V14(parser_context_t* c, pd_Price_V14_t* v);
parser_error_t _readProxyType_V14(parser_context_t* c, pd_ProxyType_V14_t* v);
parser_error_t _readQueryId_V14(parser_context_t* c, pd_QueryId_V14_t* v);
parser_error_t _readRate_V14(parser_context_t* c, pd_Rate_V14_t* v);
parser_error_t _readRatio_V14(parser_context_t* c, pd_Ratio_V14_t* v);
parser_error_t _readReferendumIndex_V14(parser_context_t* c, pd_ReferendumIndex_V14_t* v);
parser_error_t _readRegistrarIndex_V14(parser_context_t* c, pd_RegistrarIndex_V14_t* v);
parser_error_t _readResponse_V14(parser_context_t* c, pd_Response_V14_t* v);
parser_error_t _readRewardDestinationAccountIdOfT_V14(parser_context_t* c, pd_RewardDestinationAccountIdOfT_V14_t* v);
parser_error_t _readRewardDestination_V14(parser_context_t* c, pd_RewardDestination_V14_t* v);
parser_error_t _readStakingLedgerAccountIdBalanceOfT_V14(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V14_t* v);
parser_error_t _readStreamId_V14(parser_context_t* c, pd_StreamId_V14_t* v);
parser_error_t _readTeleAccount_V14(parser_context_t* c, pd_TeleAccount_V14_t* v);
parser_error_t _readTimepoint_V14(parser_context_t* c, pd_Timepoint_V14_t* v);
parser_error_t _readTimestamp_V14(parser_context_t* c, pd_Timestamp_V14_t* v);
parser_error_t _readTupleAccountIdData_V14(parser_context_t* c, pd_TupleAccountIdData_V14_t* v);
parser_error_t _readTupleCurrencyIdBalance_V14(parser_context_t* c, pd_TupleCurrencyIdBalance_V14_t* v);
parser_error_t _readTupleOracleKeyOracleValue_V14(parser_context_t* c, pd_TupleOracleKeyOracleValue_V14_t* v);
parser_error_t _readUnlockChunk_V14(parser_context_t* c, pd_UnlockChunk_V14_t* v);
parser_error_t _readUpwardMessage_V14(parser_context_t* c, pd_UpwardMessage_V14_t* v);
parser_error_t _readVecAccountIdOfT_V14(parser_context_t* c, pd_VecAccountIdOfT_V14_t* v);
parser_error_t _readVecAccountId_V14(parser_context_t* c, pd_VecAccountId_V14_t* v);
parser_error_t _readVecAssetIdOf_V14(parser_context_t* c, pd_VecAssetIdOf_V14_t* v);
parser_error_t _readVecEraIndex_V14(parser_context_t* c, pd_VecEraIndex_V14_t* v);
parser_error_t _readVecKeyValue_V14(parser_context_t* c, pd_VecKeyValue_V14_t* v);
parser_error_t _readVecKey_V14(parser_context_t* c, pd_VecKey_V14_t* v);
parser_error_t _readVecMultiAssetV0_V14(parser_context_t* c, pd_VecMultiAssetV0_V14_t* v);
parser_error_t _readVecMultiAssetV1_V14(parser_context_t* c, pd_VecMultiAssetV1_V14_t* v);
parser_error_t _readVecTupleAccountIdData_V14(parser_context_t* c, pd_VecTupleAccountIdData_V14_t* v);
parser_error_t _readVecTupleCurrencyIdBalance_V14(parser_context_t* c, pd_VecTupleCurrencyIdBalance_V14_t* v);
parser_error_t _readVecTupleOracleKeyOracleValue_V14(parser_context_t* c, pd_VecTupleOracleKeyOracleValue_V14_t* v);
parser_error_t _readVecUnlockChunk_V14(parser_context_t* c, pd_VecUnlockChunk_V14_t* v);
parser_error_t _readVecVestingScheduleOf_V14(parser_context_t* c, pd_VecVestingScheduleOf_V14_t* v);
parser_error_t _readVestingScheduleOf_V14(parser_context_t* c, pd_VestingScheduleOf_V14_t* v);
parser_error_t _readVote_V14(parser_context_t* c, pd_Vote_V14_t* v);
parser_error_t _readWeightLimit_V14(parser_context_t* c, pd_WeightLimit_V14_t* v);
parser_error_t _readWeight_V14(parser_context_t* c, pd_Weight_V14_t* v);
parser_error_t _readXcmCall_V14(parser_context_t* c, pd_XcmCall_V14_t* v);
parser_error_t _readXcmVersion_V14(parser_context_t* c, pd_XcmVersion_V14_t* v);
parser_error_t _readXcmWeightFeeMiscWeightBalanceOfT_V14(parser_context_t* c, pd_XcmWeightFeeMiscWeightBalanceOfT_V14_t* v);
parser_error_t _readschedulePeriodBlockNumber_V14(parser_context_t* c, pd_schedulePeriodBlockNumber_V14_t* v);
parser_error_t _readschedulePriority_V14(parser_context_t* c, pd_schedulePriority_V14_t* v);
parser_error_t _readu8_array_32_V14(parser_context_t* c, pd_u8_array_32_V14_t* v);

// toString functions
parser_error_t _toStringAbstractFungible_V14(
    const pd_AbstractFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible_V14(
    const pd_AbstractNonFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V14(
    const pd_AccountId32_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdOfT_V14(
    const pd_AccountIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V14(
    const pd_AccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V14(
    const pd_AccountIndex64_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V14(
    const pd_AccountKey20_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountOfT_V14(
    const pd_AccountOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V14(
    const pd_AccountVoteSplit_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V14(
    const pd_AccountVoteStandard_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V14(
    const pd_AccountVote_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfAssetIdOf_V14(
    const pd_AssetIdOfAssetIdOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfT_V14(
    const pd_AssetIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOf_V14(
    const pd_AssetIdOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetId_V14(
    const pd_AssetId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance_V14(
    const pd_AssetInstance_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V14(
    const pd_AssetType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfBalanceOf_V14(
    const pd_BalanceOfBalanceOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfT_V14(
    const pd_BalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBlockNumberForT_V14(
    const pd_BlockNumberForT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V14(
    const pd_BodyId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V14(
    const pd_BodyPart_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallIdOfT_V14(
    const pd_BoxCallIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V14(
    const pd_BoxCallOrHashOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V14(
    const pd_BoxIdentityInfoMaxAdditionalFields_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V14(
    const pd_BoxMultiLocation_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V14(
    const pd_BoxPalletsOrigin_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAsset_V14(
    const pd_BoxVersionedMultiAsset_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V14(
    const pd_BoxVersionedMultiAssets_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V14(
    const pd_BoxVersionedMultiLocation_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V14(
    const pd_BoxVersionedXcmTasSysConfigCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V14(
    const pd_BoxVersionedXcmTuple_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeToken_V14(
    const pd_BridgeToken_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeType_V14(
    const pd_BridgeType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V14(
    const pd_CallHashOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainId_V14(
    const pd_ChainId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainNonce_V14(
    const pd_ChainNonce_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V14(
    const pd_CompactAccountIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible_V14(
    const pd_ConcreteFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible_V14(
    const pd_ConcreteNonFungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringContributionStrategy_V14(
    const pd_ContributionStrategy_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V14(
    const pd_Conviction_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V14(
    const pd_CurrencyId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurveModel_V14(
    const pd_CurveModel_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDerivativeIndex_V14(
    const pd_DerivativeIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V14(
    const pd_DestroyWitness_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDoubleEncodedTuple_V14(
    const pd_DoubleEncodedTuple_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V14(
    const pd_EraIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V14(
    const pd_Fraction_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility_V14(
    const pd_Fungibility_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungible_V14(
    const pd_Fungible_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V14(
    const pd_IdentityFields_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInterestRateModel_V14(
    const pd_InterestRateModel_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V14(
    const pd_JudgementBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJumpModel_V14(
    const pd_JumpModel_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX1_V14(
    const pd_JunctionX1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX2_V14(
    const pd_JunctionX2_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX3_V14(
    const pd_JunctionX3_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX4_V14(
    const pd_JunctionX4_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX5_V14(
    const pd_JunctionX5_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX6_V14(
    const pd_JunctionX6_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX7_V14(
    const pd_JunctionX7_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX8_V14(
    const pd_JunctionX8_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunction_V14(
    const pd_Junction_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctions_V14(
    const pd_Junctions_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V14(
    const pd_KeyValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V14(
    const pd_Key_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V14(
    const pd_Keys_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriod_V14(
    const pd_LeasePeriod_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V14(
    const pd_LookupasStaticLookupSource_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketBalanceOfT_V14(
    const pd_MarketBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketState_V14(
    const pd_MarketState_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V14(
    const pd_MemberCount_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0_V14(
    const pd_MultiAssetV0_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1_V14(
    const pd_MultiAssetV1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V14(
    const pd_MultiLocationV0_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V14(
    const pd_MultiLocationV1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V14(
    const pd_NetworkId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V14(
    const pd_OpaqueCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V14(
    const pd_OptionAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBalanceOfT_V14(
    const pd_OptionBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBlockNumberForT_V14(
    const pd_OptionBlockNumberForT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionContributionStrategy_V14(
    const pd_OptionContributionStrategy_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V14(
    const pd_OptionProxyType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V14(
    const pd_OptionReferendumIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V14(
    const pd_OptionTimepoint_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V14(
    const pd_OptionXcmVersion_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V14(
    const pd_OptionschedulePeriodBlockNumber_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V14(
    const pd_OverweightIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V14(
    const pd_ParaId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V14(
    const pd_ParachainInherentData_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V14(
    const pd_Perbill_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V14(
    const pd_Plurality_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPrice_V14(
    const pd_Price_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V14(
    const pd_ProxyType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringQueryId_V14(
    const pd_QueryId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRate_V14(
    const pd_Rate_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRatio_V14(
    const pd_Ratio_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V14(
    const pd_ReferendumIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V14(
    const pd_RegistrarIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringResponse_V14(
    const pd_Response_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestinationAccountIdOfT_V14(
    const pd_RewardDestinationAccountIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V14(
    const pd_RewardDestination_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V14(
    const pd_StakingLedgerAccountIdBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamId_V14(
    const pd_StreamId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTeleAccount_V14(
    const pd_TeleAccount_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V14(
    const pd_Timepoint_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimestamp_V14(
    const pd_Timestamp_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V14(
    const pd_TupleAccountIdData_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCurrencyIdBalance_V14(
    const pd_TupleCurrencyIdBalance_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleOracleKeyOracleValue_V14(
    const pd_TupleOracleKeyOracleValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUnlockChunk_V14(
    const pd_UnlockChunk_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUpwardMessage_V14(
    const pd_UpwardMessage_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdOfT_V14(
    const pd_VecAccountIdOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V14(
    const pd_VecAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdOf_V14(
    const pd_VecAssetIdOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecEraIndex_V14(
    const pd_VecEraIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V14(
    const pd_VecKeyValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V14(
    const pd_VecKey_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0_V14(
    const pd_VecMultiAssetV0_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1_V14(
    const pd_VecMultiAssetV1_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V14(
    const pd_VecTupleAccountIdData_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleCurrencyIdBalance_V14(
    const pd_VecTupleCurrencyIdBalance_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleOracleKeyOracleValue_V14(
    const pd_VecTupleOracleKeyOracleValue_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecUnlockChunk_V14(
    const pd_VecUnlockChunk_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V14(
    const pd_VecVestingScheduleOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V14(
    const pd_VestingScheduleOf_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V14(
    const pd_Vote_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V14(
    const pd_WeightLimit_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V14(
    const pd_Weight_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmCall_V14(
    const pd_XcmCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V14(
    const pd_XcmVersion_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmWeightFeeMiscWeightBalanceOfT_V14(
    const pd_XcmWeightFeeMiscWeightBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V14(
    const pd_schedulePeriodBlockNumber_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V14(
    const pd_schedulePriority_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V14(
    const pd_u8_array_32_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
