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
#include "substrate_methods_V13.h"
#include "substrate_types_V13.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAbstractFungible_V13(parser_context_t* c, pd_AbstractFungible_V13_t* v);
parser_error_t _readAbstractNonFungible_V13(parser_context_t* c, pd_AbstractNonFungible_V13_t* v);
parser_error_t _readAccountId32_V13(parser_context_t* c, pd_AccountId32_V13_t* v);
parser_error_t _readAccountIdOfT_V13(parser_context_t* c, pd_AccountIdOfT_V13_t* v);
parser_error_t _readAccountId_V13(parser_context_t* c, pd_AccountId_V13_t* v);
parser_error_t _readAccountIndex64_V13(parser_context_t* c, pd_AccountIndex64_V13_t* v);
parser_error_t _readAccountKey20_V13(parser_context_t* c, pd_AccountKey20_V13_t* v);
parser_error_t _readAccountOfT_V13(parser_context_t* c, pd_AccountOfT_V13_t* v);
parser_error_t _readAccountVoteSplit_V13(parser_context_t* c, pd_AccountVoteSplit_V13_t* v);
parser_error_t _readAccountVoteStandard_V13(parser_context_t* c, pd_AccountVoteStandard_V13_t* v);
parser_error_t _readAccountVote_V13(parser_context_t* c, pd_AccountVote_V13_t* v);
parser_error_t _readAssetIdOfTIAssetIdOfTI_V13(parser_context_t* c, pd_AssetIdOfTIAssetIdOfTI_V13_t* v);
parser_error_t _readAssetIdOfTI_V13(parser_context_t* c, pd_AssetIdOfTI_V13_t* v);
parser_error_t _readAssetIdOfT_V13(parser_context_t* c, pd_AssetIdOfT_V13_t* v);
parser_error_t _readAssetId_V13(parser_context_t* c, pd_AssetId_V13_t* v);
parser_error_t _readAssetInstance_V13(parser_context_t* c, pd_AssetInstance_V13_t* v);
parser_error_t _readAssetType_V13(parser_context_t* c, pd_AssetType_V13_t* v);
parser_error_t _readBalanceOfTIBalanceOfTI_V13(parser_context_t* c, pd_BalanceOfTIBalanceOfTI_V13_t* v);
parser_error_t _readBalanceOfT_V13(parser_context_t* c, pd_BalanceOfT_V13_t* v);
parser_error_t _readBlockNumberForT_V13(parser_context_t* c, pd_BlockNumberForT_V13_t* v);
parser_error_t _readBodyId_V13(parser_context_t* c, pd_BodyId_V13_t* v);
parser_error_t _readBodyPart_V13(parser_context_t* c, pd_BodyPart_V13_t* v);
parser_error_t _readBoxCallIdOfT_V13(parser_context_t* c, pd_BoxCallIdOfT_V13_t* v);
parser_error_t _readBoxCallOrHashOfT_V13(parser_context_t* c, pd_BoxCallOrHashOfT_V13_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V13(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V13_t* v);
parser_error_t _readBoxMultiLocation_V13(parser_context_t* c, pd_BoxMultiLocation_V13_t* v);
parser_error_t _readBoxPalletsOrigin_V13(parser_context_t* c, pd_BoxPalletsOrigin_V13_t* v);
parser_error_t _readBoxVersionedMultiAsset_V13(parser_context_t* c, pd_BoxVersionedMultiAsset_V13_t* v);
parser_error_t _readBoxVersionedMultiAssets_V13(parser_context_t* c, pd_BoxVersionedMultiAssets_V13_t* v);
parser_error_t _readBoxVersionedMultiLocation_V13(parser_context_t* c, pd_BoxVersionedMultiLocation_V13_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V13(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V13_t* v);
parser_error_t _readBoxVersionedXcmTuple_V13(parser_context_t* c, pd_BoxVersionedXcmTuple_V13_t* v);
parser_error_t _readBridgeToken_V13(parser_context_t* c, pd_BridgeToken_V13_t* v);
parser_error_t _readBridgeType_V13(parser_context_t* c, pd_BridgeType_V13_t* v);
parser_error_t _readCallHashOf_V13(parser_context_t* c, pd_CallHashOf_V13_t* v);
parser_error_t _readChainId_V13(parser_context_t* c, pd_ChainId_V13_t* v);
parser_error_t _readChainNonce_V13(parser_context_t* c, pd_ChainNonce_V13_t* v);
parser_error_t _readCompactAccountIndex_V13(parser_context_t* c, pd_CompactAccountIndex_V13_t* v);
parser_error_t _readConcreteFungible_V13(parser_context_t* c, pd_ConcreteFungible_V13_t* v);
parser_error_t _readConcreteNonFungible_V13(parser_context_t* c, pd_ConcreteNonFungible_V13_t* v);
parser_error_t _readContributionStrategy_V13(parser_context_t* c, pd_ContributionStrategy_V13_t* v);
parser_error_t _readConviction_V13(parser_context_t* c, pd_Conviction_V13_t* v);
parser_error_t _readCurrencyId_V13(parser_context_t* c, pd_CurrencyId_V13_t* v);
parser_error_t _readCurveModel_V13(parser_context_t* c, pd_CurveModel_V13_t* v);
parser_error_t _readDerivativeIndex_V13(parser_context_t* c, pd_DerivativeIndex_V13_t* v);
parser_error_t _readDestroyWitness_V13(parser_context_t* c, pd_DestroyWitness_V13_t* v);
parser_error_t _readDoubleEncodedTuple_V13(parser_context_t* c, pd_DoubleEncodedTuple_V13_t* v);
parser_error_t _readEraIndex_V13(parser_context_t* c, pd_EraIndex_V13_t* v);
parser_error_t _readFraction_V13(parser_context_t* c, pd_Fraction_V13_t* v);
parser_error_t _readFungibility_V13(parser_context_t* c, pd_Fungibility_V13_t* v);
parser_error_t _readFungible_V13(parser_context_t* c, pd_Fungible_V13_t* v);
parser_error_t _readIdentityFields_V13(parser_context_t* c, pd_IdentityFields_V13_t* v);
parser_error_t _readInterestRateModel_V13(parser_context_t* c, pd_InterestRateModel_V13_t* v);
parser_error_t _readJudgementBalanceOfT_V13(parser_context_t* c, pd_JudgementBalanceOfT_V13_t* v);
parser_error_t _readJumpModel_V13(parser_context_t* c, pd_JumpModel_V13_t* v);
parser_error_t _readJunctionX1_V13(parser_context_t* c, pd_JunctionX1_V13_t* v);
parser_error_t _readJunctionX2_V13(parser_context_t* c, pd_JunctionX2_V13_t* v);
parser_error_t _readJunctionX3_V13(parser_context_t* c, pd_JunctionX3_V13_t* v);
parser_error_t _readJunctionX4_V13(parser_context_t* c, pd_JunctionX4_V13_t* v);
parser_error_t _readJunctionX5_V13(parser_context_t* c, pd_JunctionX5_V13_t* v);
parser_error_t _readJunctionX6_V13(parser_context_t* c, pd_JunctionX6_V13_t* v);
parser_error_t _readJunctionX7_V13(parser_context_t* c, pd_JunctionX7_V13_t* v);
parser_error_t _readJunctionX8_V13(parser_context_t* c, pd_JunctionX8_V13_t* v);
parser_error_t _readJunction_V13(parser_context_t* c, pd_Junction_V13_t* v);
parser_error_t _readJunctions_V13(parser_context_t* c, pd_Junctions_V13_t* v);
parser_error_t _readKeyValue_V13(parser_context_t* c, pd_KeyValue_V13_t* v);
parser_error_t _readKey_V13(parser_context_t* c, pd_Key_V13_t* v);
parser_error_t _readKeys_V13(parser_context_t* c, pd_Keys_V13_t* v);
parser_error_t _readLeasePeriod_V13(parser_context_t* c, pd_LeasePeriod_V13_t* v);
parser_error_t _readLookupasStaticLookupSource_V13(parser_context_t* c, pd_LookupasStaticLookupSource_V13_t* v);
parser_error_t _readMarketBalanceOfT_V13(parser_context_t* c, pd_MarketBalanceOfT_V13_t* v);
parser_error_t _readMarketState_V13(parser_context_t* c, pd_MarketState_V13_t* v);
parser_error_t _readMemberCount_V13(parser_context_t* c, pd_MemberCount_V13_t* v);
parser_error_t _readMultiAssetV0_V13(parser_context_t* c, pd_MultiAssetV0_V13_t* v);
parser_error_t _readMultiAssetV1_V13(parser_context_t* c, pd_MultiAssetV1_V13_t* v);
parser_error_t _readMultiLocationV0_V13(parser_context_t* c, pd_MultiLocationV0_V13_t* v);
parser_error_t _readMultiLocationV1_V13(parser_context_t* c, pd_MultiLocationV1_V13_t* v);
parser_error_t _readNetworkId_V13(parser_context_t* c, pd_NetworkId_V13_t* v);
parser_error_t _readOpaqueCall_V13(parser_context_t* c, pd_OpaqueCall_V13_t* v);
parser_error_t _readOptionAccountId_V13(parser_context_t* c, pd_OptionAccountId_V13_t* v);
parser_error_t _readOptionBalanceOfT_V13(parser_context_t* c, pd_OptionBalanceOfT_V13_t* v);
parser_error_t _readOptionBlockNumberForT_V13(parser_context_t* c, pd_OptionBlockNumberForT_V13_t* v);
parser_error_t _readOptionContributionStrategy_V13(parser_context_t* c, pd_OptionContributionStrategy_V13_t* v);
parser_error_t _readOptionProxyType_V13(parser_context_t* c, pd_OptionProxyType_V13_t* v);
parser_error_t _readOptionReferendumIndex_V13(parser_context_t* c, pd_OptionReferendumIndex_V13_t* v);
parser_error_t _readOptionTimepoint_V13(parser_context_t* c, pd_OptionTimepoint_V13_t* v);
parser_error_t _readOptionXcmVersion_V13(parser_context_t* c, pd_OptionXcmVersion_V13_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V13(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V13_t* v);
parser_error_t _readOverweightIndex_V13(parser_context_t* c, pd_OverweightIndex_V13_t* v);
parser_error_t _readParaId_V13(parser_context_t* c, pd_ParaId_V13_t* v);
parser_error_t _readParachainInherentData_V13(parser_context_t* c, pd_ParachainInherentData_V13_t* v);
parser_error_t _readPerbill_V13(parser_context_t* c, pd_Perbill_V13_t* v);
parser_error_t _readPlurality_V13(parser_context_t* c, pd_Plurality_V13_t* v);
parser_error_t _readPrice_V13(parser_context_t* c, pd_Price_V13_t* v);
parser_error_t _readProxyType_V13(parser_context_t* c, pd_ProxyType_V13_t* v);
parser_error_t _readQueryId_V13(parser_context_t* c, pd_QueryId_V13_t* v);
parser_error_t _readRate_V13(parser_context_t* c, pd_Rate_V13_t* v);
parser_error_t _readRatio_V13(parser_context_t* c, pd_Ratio_V13_t* v);
parser_error_t _readReferendumIndex_V13(parser_context_t* c, pd_ReferendumIndex_V13_t* v);
parser_error_t _readRegistrarIndex_V13(parser_context_t* c, pd_RegistrarIndex_V13_t* v);
parser_error_t _readResponse_V13(parser_context_t* c, pd_Response_V13_t* v);
parser_error_t _readRewardDestinationAccountIdOfT_V13(parser_context_t* c, pd_RewardDestinationAccountIdOfT_V13_t* v);
parser_error_t _readRewardDestination_V13(parser_context_t* c, pd_RewardDestination_V13_t* v);
parser_error_t _readStakingLedgerAccountIdBalanceOfT_V13(parser_context_t* c, pd_StakingLedgerAccountIdBalanceOfT_V13_t* v);
parser_error_t _readStreamId_V13(parser_context_t* c, pd_StreamId_V13_t* v);
parser_error_t _readTeleAccount_V13(parser_context_t* c, pd_TeleAccount_V13_t* v);
parser_error_t _readTimepoint_V13(parser_context_t* c, pd_Timepoint_V13_t* v);
parser_error_t _readTimestamp_V13(parser_context_t* c, pd_Timestamp_V13_t* v);
parser_error_t _readTupleAccountIdData_V13(parser_context_t* c, pd_TupleAccountIdData_V13_t* v);
parser_error_t _readTupleCurrencyIdBalance_V13(parser_context_t* c, pd_TupleCurrencyIdBalance_V13_t* v);
parser_error_t _readTupleOracleKeyOracleValue_V13(parser_context_t* c, pd_TupleOracleKeyOracleValue_V13_t* v);
parser_error_t _readUnlockChunk_V13(parser_context_t* c, pd_UnlockChunk_V13_t* v);
parser_error_t _readUpwardMessage_V13(parser_context_t* c, pd_UpwardMessage_V13_t* v);
parser_error_t _readVecAccountIdOfT_V13(parser_context_t* c, pd_VecAccountIdOfT_V13_t* v);
parser_error_t _readVecAccountId_V13(parser_context_t* c, pd_VecAccountId_V13_t* v);
parser_error_t _readVecAssetIdOfTI_V13(parser_context_t* c, pd_VecAssetIdOfTI_V13_t* v);
parser_error_t _readVecEraIndex_V13(parser_context_t* c, pd_VecEraIndex_V13_t* v);
parser_error_t _readVecKeyValue_V13(parser_context_t* c, pd_VecKeyValue_V13_t* v);
parser_error_t _readVecKey_V13(parser_context_t* c, pd_VecKey_V13_t* v);
parser_error_t _readVecMultiAssetV0_V13(parser_context_t* c, pd_VecMultiAssetV0_V13_t* v);
parser_error_t _readVecMultiAssetV1_V13(parser_context_t* c, pd_VecMultiAssetV1_V13_t* v);
parser_error_t _readVecTupleAccountIdData_V13(parser_context_t* c, pd_VecTupleAccountIdData_V13_t* v);
parser_error_t _readVecTupleCurrencyIdBalance_V13(parser_context_t* c, pd_VecTupleCurrencyIdBalance_V13_t* v);
parser_error_t _readVecTupleOracleKeyOracleValue_V13(parser_context_t* c, pd_VecTupleOracleKeyOracleValue_V13_t* v);
parser_error_t _readVecUnlockChunk_V13(parser_context_t* c, pd_VecUnlockChunk_V13_t* v);
parser_error_t _readVecVestingScheduleOf_V13(parser_context_t* c, pd_VecVestingScheduleOf_V13_t* v);
parser_error_t _readVestingScheduleOf_V13(parser_context_t* c, pd_VestingScheduleOf_V13_t* v);
parser_error_t _readVote_V13(parser_context_t* c, pd_Vote_V13_t* v);
parser_error_t _readWeightLimit_V13(parser_context_t* c, pd_WeightLimit_V13_t* v);
parser_error_t _readWeight_V13(parser_context_t* c, pd_Weight_V13_t* v);
parser_error_t _readXcmCall_V13(parser_context_t* c, pd_XcmCall_V13_t* v);
parser_error_t _readXcmVersion_V13(parser_context_t* c, pd_XcmVersion_V13_t* v);
parser_error_t _readXcmWeightFeeMiscWeightBalanceOfT_V13(parser_context_t* c, pd_XcmWeightFeeMiscWeightBalanceOfT_V13_t* v);
parser_error_t _readschedulePeriodBlockNumber_V13(parser_context_t* c, pd_schedulePeriodBlockNumber_V13_t* v);
parser_error_t _readschedulePriority_V13(parser_context_t* c, pd_schedulePriority_V13_t* v);
parser_error_t _readu8_array_32_V13(parser_context_t* c, pd_u8_array_32_V13_t* v);

// toString functions
parser_error_t _toStringAbstractFungible_V13(
    const pd_AbstractFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible_V13(
    const pd_AbstractNonFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V13(
    const pd_AccountId32_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdOfT_V13(
    const pd_AccountIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V13(
    const pd_AccountId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V13(
    const pd_AccountIndex64_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V13(
    const pd_AccountKey20_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountOfT_V13(
    const pd_AccountOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V13(
    const pd_AccountVoteSplit_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V13(
    const pd_AccountVoteStandard_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V13(
    const pd_AccountVote_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfTIAssetIdOfTI_V13(
    const pd_AssetIdOfTIAssetIdOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfTI_V13(
    const pd_AssetIdOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdOfT_V13(
    const pd_AssetIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetId_V13(
    const pd_AssetId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance_V13(
    const pd_AssetInstance_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V13(
    const pd_AssetType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfTIBalanceOfTI_V13(
    const pd_BalanceOfTIBalanceOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOfT_V13(
    const pd_BalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBlockNumberForT_V13(
    const pd_BlockNumberForT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V13(
    const pd_BodyId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V13(
    const pd_BodyPart_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallIdOfT_V13(
    const pd_BoxCallIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V13(
    const pd_BoxCallOrHashOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V13(
    const pd_BoxIdentityInfoMaxAdditionalFields_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V13(
    const pd_BoxMultiLocation_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V13(
    const pd_BoxPalletsOrigin_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAsset_V13(
    const pd_BoxVersionedMultiAsset_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V13(
    const pd_BoxVersionedMultiAssets_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V13(
    const pd_BoxVersionedMultiLocation_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V13(
    const pd_BoxVersionedXcmTasSysConfigCall_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V13(
    const pd_BoxVersionedXcmTuple_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeToken_V13(
    const pd_BridgeToken_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeType_V13(
    const pd_BridgeType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V13(
    const pd_CallHashOf_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainId_V13(
    const pd_ChainId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainNonce_V13(
    const pd_ChainNonce_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V13(
    const pd_CompactAccountIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible_V13(
    const pd_ConcreteFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible_V13(
    const pd_ConcreteNonFungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringContributionStrategy_V13(
    const pd_ContributionStrategy_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V13(
    const pd_Conviction_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V13(
    const pd_CurrencyId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurveModel_V13(
    const pd_CurveModel_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDerivativeIndex_V13(
    const pd_DerivativeIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V13(
    const pd_DestroyWitness_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDoubleEncodedTuple_V13(
    const pd_DoubleEncodedTuple_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V13(
    const pd_EraIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V13(
    const pd_Fraction_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility_V13(
    const pd_Fungibility_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungible_V13(
    const pd_Fungible_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V13(
    const pd_IdentityFields_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInterestRateModel_V13(
    const pd_InterestRateModel_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V13(
    const pd_JudgementBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJumpModel_V13(
    const pd_JumpModel_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX1_V13(
    const pd_JunctionX1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX2_V13(
    const pd_JunctionX2_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX3_V13(
    const pd_JunctionX3_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX4_V13(
    const pd_JunctionX4_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX5_V13(
    const pd_JunctionX5_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX6_V13(
    const pd_JunctionX6_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX7_V13(
    const pd_JunctionX7_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionX8_V13(
    const pd_JunctionX8_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunction_V13(
    const pd_Junction_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctions_V13(
    const pd_Junctions_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V13(
    const pd_KeyValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V13(
    const pd_Key_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V13(
    const pd_Keys_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriod_V13(
    const pd_LeasePeriod_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V13(
    const pd_LookupasStaticLookupSource_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketBalanceOfT_V13(
    const pd_MarketBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMarketState_V13(
    const pd_MarketState_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V13(
    const pd_MemberCount_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0_V13(
    const pd_MultiAssetV0_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1_V13(
    const pd_MultiAssetV1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V13(
    const pd_MultiLocationV0_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V13(
    const pd_MultiLocationV1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V13(
    const pd_NetworkId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V13(
    const pd_OpaqueCall_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V13(
    const pd_OptionAccountId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBalanceOfT_V13(
    const pd_OptionBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBlockNumberForT_V13(
    const pd_OptionBlockNumberForT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionContributionStrategy_V13(
    const pd_OptionContributionStrategy_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V13(
    const pd_OptionProxyType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V13(
    const pd_OptionReferendumIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V13(
    const pd_OptionTimepoint_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V13(
    const pd_OptionXcmVersion_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V13(
    const pd_OptionschedulePeriodBlockNumber_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V13(
    const pd_OverweightIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V13(
    const pd_ParaId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V13(
    const pd_ParachainInherentData_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V13(
    const pd_Perbill_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V13(
    const pd_Plurality_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPrice_V13(
    const pd_Price_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V13(
    const pd_ProxyType_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringQueryId_V13(
    const pd_QueryId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRate_V13(
    const pd_Rate_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRatio_V13(
    const pd_Ratio_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V13(
    const pd_ReferendumIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V13(
    const pd_RegistrarIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringResponse_V13(
    const pd_Response_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestinationAccountIdOfT_V13(
    const pd_RewardDestinationAccountIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V13(
    const pd_RewardDestination_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStakingLedgerAccountIdBalanceOfT_V13(
    const pd_StakingLedgerAccountIdBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamId_V13(
    const pd_StreamId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTeleAccount_V13(
    const pd_TeleAccount_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V13(
    const pd_Timepoint_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimestamp_V13(
    const pd_Timestamp_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V13(
    const pd_TupleAccountIdData_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCurrencyIdBalance_V13(
    const pd_TupleCurrencyIdBalance_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleOracleKeyOracleValue_V13(
    const pd_TupleOracleKeyOracleValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUnlockChunk_V13(
    const pd_UnlockChunk_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUpwardMessage_V13(
    const pd_UpwardMessage_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdOfT_V13(
    const pd_VecAccountIdOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V13(
    const pd_VecAccountId_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdOfTI_V13(
    const pd_VecAssetIdOfTI_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecEraIndex_V13(
    const pd_VecEraIndex_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V13(
    const pd_VecKeyValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V13(
    const pd_VecKey_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0_V13(
    const pd_VecMultiAssetV0_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1_V13(
    const pd_VecMultiAssetV1_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V13(
    const pd_VecTupleAccountIdData_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleCurrencyIdBalance_V13(
    const pd_VecTupleCurrencyIdBalance_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleOracleKeyOracleValue_V13(
    const pd_VecTupleOracleKeyOracleValue_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecUnlockChunk_V13(
    const pd_VecUnlockChunk_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V13(
    const pd_VecVestingScheduleOf_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V13(
    const pd_VestingScheduleOf_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V13(
    const pd_Vote_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V13(
    const pd_WeightLimit_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V13(
    const pd_Weight_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmCall_V13(
    const pd_XcmCall_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V13(
    const pd_XcmVersion_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmWeightFeeMiscWeightBalanceOfT_V13(
    const pd_XcmWeightFeeMiscWeightBalanceOfT_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V13(
    const pd_schedulePeriodBlockNumber_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V13(
    const pd_schedulePriority_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V13(
    const pd_u8_array_32_V13_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
