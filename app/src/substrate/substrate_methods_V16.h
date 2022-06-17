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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V16.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V16 0
#define PD_CALL_TIMESTAMP_V16 1
#define PD_CALL_UTILITY_V16 2
#define PD_CALL_MULTISIG_V16 3
#define PD_CALL_BALANCES_V16 4
#define PD_CALL_ASSETS_V16 6
#define PD_CALL_PROXY_V16 7
#define PD_CALL_IDENTITY_V16 8
#define PD_CALL_DEMOCRACY_V16 11
#define PD_CALL_GENERALCOUNCIL_V16 12
#define PD_CALL_TECHNICALCOMMITTEE_V16 13
#define PD_CALL_TREASURY_V16 14
#define PD_CALL_PREIMAGE_V16 16
#define PD_CALL_XCMPQUEUE_V16 22
#define PD_CALL_DMPQUEUE_V16 23
#define PD_CALL_COLLATORSELECTION_V16 31
#define PD_CALL_SESSION_V16 32
#define PD_CALL_XTOKENS_V16 43
#define PD_CALL_VESTING_V16 46
#define PD_CALL_LOANS_V16 50
#define PD_CALL_PRICES_V16 51
#define PD_CALL_CROWDLOANS_V16 52
#define PD_CALL_LIQUIDSTAKING_V16 60
#define PD_CALL_GENERALCOUNCILMEMBERSHIP_V16 70
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V16 71
#define PD_CALL_ORACLEMEMBERSHIP_V16 72
#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_V16 73
#define PD_CALL_BRIDGEMEMBERSHIP_V16 74
#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_V16 75
#define PD_CALL_AMM_V16 80
#define PD_CALL_AMMROUTE_V16 81
#define PD_CALL_CURRENCYADAPTER_V16 82
#define PD_CALL_BRIDGE_V16 90
#define PD_CALL_EMERGENCYSHUTDOWN_V16 91
#define PD_CALL_FARMING_V16 92
#define PD_CALL_STREAMING_V16 94
#define PD_CALL_PARACHAINSYSTEM_V16 20

#define PD_CALL_UTILITY_BATCH_V16 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V16_t;

#define PD_CALL_UTILITY_BATCH_ALL_V16 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V16_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V16 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V16_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V16 4
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V16_t;

#define PD_CALL_SESSION_SET_KEYS_V16 0
typedef struct {
    pd_Keys_V16_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V16_t;

#define PD_CALL_SESSION_PURGE_KEYS_V16 1
typedef struct {
} pd_session_purge_keys_V16_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V16 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V16_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V16 5
typedef struct {
    pd_LookupasStaticLookupSource_V16_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V16_t;

#define PD_CALL_ASSETS_CREATE_V16 0
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t admin;
    pd_Balance_t min_balance;
} pd_assets_create_V16_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V16 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t owner;
    pd_bool_t is_sufficient;
    pd_Compactu128_t min_balance;
} pd_assets_force_create_V16_t;

#define PD_CALL_ASSETS_DESTROY_V16 2
typedef struct {
    pd_Compactu32_t id;
    pd_DestroyWitness_V16_t witness;
} pd_assets_destroy_V16_t;

#define PD_CALL_ASSETS_MINT_V16 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t beneficiary;
    pd_Compactu128_t amount;
} pd_assets_mint_V16_t;

#define PD_CALL_ASSETS_BURN_V16 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t who;
    pd_Compactu128_t amount;
} pd_assets_burn_V16_t;

#define PD_CALL_ASSETS_TRANSFER_V16 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t target;
    pd_Compactu128_t amount;
} pd_assets_transfer_V16_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V16 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t target;
    pd_Compactu128_t amount;
} pd_assets_transfer_keep_alive_V16_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V16 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t source;
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_Compactu128_t amount;
} pd_assets_force_transfer_V16_t;

#define PD_CALL_ASSETS_FREEZE_V16 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t who;
} pd_assets_freeze_V16_t;

#define PD_CALL_ASSETS_THAW_V16 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t who;
} pd_assets_thaw_V16_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V16 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V16_t;

#define PD_CALL_ASSETS_THAW_ASSET_V16 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V16_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V16 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t owner;
} pd_assets_transfer_ownership_V16_t;

#define PD_CALL_ASSETS_SET_TEAM_V16 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t issuer;
    pd_LookupasStaticLookupSource_V16_t admin;
    pd_LookupasStaticLookupSource_V16_t freezer;
} pd_assets_set_team_V16_t;

#define PD_CALL_ASSETS_SET_METADATA_V16 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V16_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V16 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V16_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V16 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V16_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V16 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V16_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V16 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t owner;
    pd_LookupasStaticLookupSource_V16_t issuer;
    pd_LookupasStaticLookupSource_V16_t admin;
    pd_LookupasStaticLookupSource_V16_t freezer;
    pd_Compactu128_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V16_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V16 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t delegate;
    pd_Compactu128_t amount;
} pd_assets_approve_transfer_V16_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V16 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t delegate;
} pd_assets_cancel_approval_V16_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V16 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t owner;
    pd_LookupasStaticLookupSource_V16_t delegate;
} pd_assets_force_cancel_approval_V16_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V16 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V16_t owner;
    pd_LookupasStaticLookupSource_V16_t destination;
    pd_Compactu128_t amount;
} pd_assets_transfer_approved_V16_t;

#define PD_CALL_ASSETS_TOUCH_V16 23
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V16_t;

#define PD_CALL_ASSETS_REFUND_V16 24
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V16_t;

#define PD_CALL_PROXY_ADD_PROXY_V16 1
typedef struct {
    pd_AccountId_V16_t delegate;
    pd_ProxyType_V16_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V16_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V16 2
typedef struct {
    pd_AccountId_V16_t delegate;
    pd_ProxyType_V16_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V16_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V16 3
typedef struct {
} pd_proxy_remove_proxies_V16_t;

#define PD_CALL_PROXY_ANONYMOUS_V16 4
typedef struct {
    pd_ProxyType_V16_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V16_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V16 5
typedef struct {
    pd_AccountId_V16_t spawner;
    pd_ProxyType_V16_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V16_t;

#define PD_CALL_PROXY_ANNOUNCE_V16 6
typedef struct {
    pd_AccountId_V16_t real;
    pd_CallHashOf_V16_t call_hash;
} pd_proxy_announce_V16_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V16 7
typedef struct {
    pd_AccountId_V16_t real;
    pd_CallHashOf_V16_t call_hash;
} pd_proxy_remove_announcement_V16_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V16 8
typedef struct {
    pd_AccountId_V16_t delegate;
    pd_CallHashOf_V16_t call_hash;
} pd_proxy_reject_announcement_V16_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V16 9
typedef struct {
    pd_AccountId_V16_t delegate;
    pd_AccountId_V16_t real;
    pd_OptionProxyType_V16_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V16_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V16 0
typedef struct {
    pd_AccountId_V16_t account;
} pd_identity_add_registrar_V16_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V16 3
typedef struct {
} pd_identity_clear_identity_V16_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V16 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V16_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V16 5
typedef struct {
    pd_RegistrarIndex_V16_t reg_index;
} pd_identity_cancel_request_V16_t;

#define PD_CALL_IDENTITY_SET_FEE_V16 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V16_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V16 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V16_t new_;
} pd_identity_set_account_id_V16_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V16 10
typedef struct {
    pd_LookupasStaticLookupSource_V16_t target;
} pd_identity_kill_identity_V16_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V16 13
typedef struct {
    pd_LookupasStaticLookupSource_V16_t sub;
} pd_identity_remove_sub_V16_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V16 14
typedef struct {
} pd_identity_quit_sub_V16_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V16 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V16_t;

#define PD_CALL_DEMOCRACY_SECOND_V16 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V16_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V16 3
typedef struct {
    pd_ReferendumIndex_V16_t ref_index;
} pd_democracy_emergency_cancel_V16_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V16 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V16_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V16 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V16_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V16 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V16_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V16 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V16_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V16 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V16_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V16 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V16_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V16 10
typedef struct {
    pd_ReferendumIndex_V16_t which;
} pd_democracy_cancel_queued_V16_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V16 11
typedef struct {
    pd_AccountId_V16_t to;
    pd_Conviction_V16_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V16_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V16 12
typedef struct {
} pd_democracy_undelegate_V16_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V16 13
typedef struct {
} pd_democracy_clear_public_proposals_V16_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V16 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V16_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V16 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V16_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V16 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V16_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V16 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V16_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V16 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V16_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V16 19
typedef struct {
    pd_AccountId_V16_t target;
} pd_democracy_unlock_V16_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V16 20
typedef struct {
    pd_ReferendumIndex_V16_t index;
} pd_democracy_remove_vote_V16_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V16 21
typedef struct {
    pd_AccountId_V16_t target;
    pd_ReferendumIndex_V16_t index;
} pd_democracy_remove_other_vote_V16_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V16 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V16_t index;
} pd_democracy_enact_proposal_V16_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V16 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V16_t;

#define PD_CALL_GENERALCOUNCIL_SET_MEMBERS_V16 0
typedef struct {
    pd_VecAccountId_V16_t new_members;
    pd_OptionAccountId_V16_t prime;
    pd_MemberCount_V16_t old_count;
} pd_generalcouncil_set_members_V16_t;

#define PD_CALL_GENERALCOUNCIL_EXECUTE_V16 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_execute_V16_t;

#define PD_CALL_GENERALCOUNCIL_PROPOSE_V16 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_propose_V16_t;

#define PD_CALL_GENERALCOUNCIL_VOTE_V16 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_generalcouncil_vote_V16_t;

#define PD_CALL_GENERALCOUNCIL_CLOSE_V16 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_close_V16_t;

#define PD_CALL_GENERALCOUNCIL_DISAPPROVE_PROPOSAL_V16 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_generalcouncil_disapprove_proposal_V16_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V16 0
typedef struct {
    pd_VecAccountId_V16_t new_members;
    pd_OptionAccountId_V16_t prime;
    pd_MemberCount_V16_t old_count;
} pd_technicalcommittee_set_members_V16_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V16 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V16_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V16 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V16_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V16 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V16_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V16 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V16_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V16 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V16_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V16 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V16_t beneficiary;
} pd_treasury_propose_spend_V16_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V16 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V16_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V16 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V16_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V16 3
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V16_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V16 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V16_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V16 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V16_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V16 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V16_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V16 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V16_t;

#define PD_CALL_XCMPQUEUE_SERVICE_OVERWEIGHT_V16 0
typedef struct {
    pd_OverweightIndex_V16_t index;
    pd_Weight_V16_t weight_limit;
} pd_xcmpqueue_service_overweight_V16_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V16 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V16_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V16 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V16_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V16 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V16_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V16 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V16_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V16 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V16_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V16 6
typedef struct {
    pd_Weight_V16_t new_;
} pd_xcmpqueue_update_threshold_weight_V16_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V16 7
typedef struct {
    pd_Weight_V16_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V16_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V16 8
typedef struct {
    pd_Weight_V16_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V16_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V16 0
typedef struct {
    pd_OverweightIndex_V16_t index;
    pd_Weight_V16_t weight_limit;
} pd_dmpqueue_service_overweight_V16_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V16 0
typedef struct {
    pd_VecAccountId_V16_t new_;
} pd_collatorselection_set_invulnerables_V16_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V16 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V16_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V16 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V16_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V16 3
typedef struct {
} pd_collatorselection_register_as_candidate_V16_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V16 4
typedef struct {
} pd_collatorselection_leave_intent_V16_t;

#define PD_CALL_XTOKENS_TRANSFER_V16 0
typedef struct {
    pd_CurrencyId_V16_t currency_id;
    pd_Balance_t amount;
    pd_BoxVersionedMultiLocation_V16_t dest;
    pd_Weight_V16_t dest_weight;
} pd_xtokens_transfer_V16_t;

#define PD_CALL_VESTING_CLAIM_V16 0
typedef struct {
} pd_vesting_claim_V16_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V16 1
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_VestingScheduleOf_V16_t schedule;
} pd_vesting_vested_transfer_V16_t;

#define PD_CALL_VESTING_UPDATE_VESTING_SCHEDULES_V16 2
typedef struct {
    pd_LookupasStaticLookupSource_V16_t who;
    pd_VecVestingScheduleOf_V16_t vesting_schedules;
} pd_vesting_update_vesting_schedules_V16_t;

#define PD_CALL_VESTING_CLAIM_FOR_V16 3
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
} pd_vesting_claim_for_V16_t;

#define PD_CALL_LOANS_ADD_MARKET_V16 0
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_MarketBalanceOfT_V16_t market;
} pd_loans_add_market_V16_t;

#define PD_CALL_LOANS_ACTIVATE_MARKET_V16 1
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
} pd_loans_activate_market_V16_t;

#define PD_CALL_LOANS_UPDATE_RATE_MODEL_V16 2
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_InterestRateModel_V16_t rate_model;
} pd_loans_update_rate_model_V16_t;

#define PD_CALL_LOANS_UPDATE_MARKET_V16 3
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_OptionRatio_V16_t collateral_factor;
    pd_OptionRatio_V16_t liquidation_threshold;
    pd_OptionRatio_V16_t reserve_factor;
    pd_OptionRatio_V16_t close_factor;
    pd_OptionRatio_V16_t liquidate_incentive_reserved_factor;
    pd_OptionRate_V16_t liquidate_incentive;
    pd_OptionBalance_t supply_cap;
    pd_OptionBalance_t borrow_cap;
} pd_loans_update_market_V16_t;

#define PD_CALL_LOANS_FORCE_UPDATE_MARKET_V16 4
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_MarketBalanceOfT_V16_t market;
} pd_loans_force_update_market_V16_t;

#define PD_CALL_LOANS_ADD_REWARD_V16 5
typedef struct {
    pd_Balance_t amount;
} pd_loans_add_reward_V16_t;

#define PD_CALL_LOANS_WITHDRAW_MISSING_REWARD_V16 6
typedef struct {
    pd_LookupasStaticLookupSource_V16_t target_account;
    pd_Balance_t amount;
} pd_loans_withdraw_missing_reward_V16_t;

#define PD_CALL_LOANS_UPDATE_MARKET_REWARD_SPEED_V16 7
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_OptionBalance_t supply_reward_per_block;
    pd_OptionBalance_t borrow_reward_per_block;
} pd_loans_update_market_reward_speed_V16_t;

#define PD_CALL_LOANS_CLAIM_REWARD_V16 8
typedef struct {
} pd_loans_claim_reward_V16_t;

#define PD_CALL_LOANS_CLAIM_REWARD_FOR_MARKET_V16 9
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
} pd_loans_claim_reward_for_market_V16_t;

#define PD_CALL_LOANS_MINT_V16 10
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t mint_amount;
} pd_loans_mint_V16_t;

#define PD_CALL_LOANS_REDEEM_V16 11
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t redeem_amount;
} pd_loans_redeem_V16_t;

#define PD_CALL_LOANS_REDEEM_ALL_V16 12
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
} pd_loans_redeem_all_V16_t;

#define PD_CALL_LOANS_BORROW_V16 13
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t borrow_amount;
} pd_loans_borrow_V16_t;

#define PD_CALL_LOANS_REPAY_BORROW_V16 14
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t repay_amount;
} pd_loans_repay_borrow_V16_t;

#define PD_CALL_LOANS_REPAY_BORROW_ALL_V16 15
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
} pd_loans_repay_borrow_all_V16_t;

#define PD_CALL_LOANS_COLLATERAL_ASSET_V16 16
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_bool_t enable;
} pd_loans_collateral_asset_V16_t;

#define PD_CALL_LOANS_LIQUIDATE_BORROW_V16 17
typedef struct {
    pd_AccountId_V16_t borrower;
    pd_AssetIdOfT_V16_t liquidation_asset_id;
    pd_Compactu128_t repay_amount;
    pd_AssetIdOfT_V16_t collateral_asset_id;
} pd_loans_liquidate_borrow_V16_t;

#define PD_CALL_LOANS_ADD_RESERVES_V16 18
typedef struct {
    pd_LookupasStaticLookupSource_V16_t payer;
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t add_amount;
} pd_loans_add_reserves_V16_t;

#define PD_CALL_LOANS_REDUCE_RESERVES_V16 19
typedef struct {
    pd_LookupasStaticLookupSource_V16_t receiver;
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t reduce_amount;
} pd_loans_reduce_reserves_V16_t;

#define PD_CALL_LOANS_REDUCE_INCENTIVE_RESERVES_V16 20
typedef struct {
    pd_LookupasStaticLookupSource_V16_t receiver;
    pd_AssetIdOfT_V16_t asset_id;
    pd_Compactu128_t redeem_amount;
} pd_loans_reduce_incentive_reserves_V16_t;

#define PD_CALL_LOANS_UPDATE_LIQUIDATION_FREE_COLLATERAL_V16 21
typedef struct {
    pd_VecAssetIdOf_V16_t collaterals;
} pd_loans_update_liquidation_free_collateral_V16_t;

#define PD_CALL_PRICES_SET_PRICE_V16 0
typedef struct {
    pd_CurrencyId_V16_t asset_id;
    pd_Price_V16_t price;
} pd_prices_set_price_V16_t;

#define PD_CALL_PRICES_RESET_PRICE_V16 1
typedef struct {
    pd_CurrencyId_V16_t asset_id;
} pd_prices_reset_price_V16_t;

#define PD_CALL_CROWDLOANS_CREATE_VAULT_V16 0
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_AssetIdOfT_V16_t ctoken;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
    pd_ContributionStrategy_V16_t contribution_strategy;
    pd_CompactBalance_t cap;
    pd_BlockNumber_t end_block;
} pd_crowdloans_create_vault_V16_t;

#define PD_CALL_CROWDLOANS_UPDATE_VAULT_V16 1
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_OptionBalance_t cap;
    pd_OptionBlockNumber_t end_block;
    pd_OptionContributionStrategy_V16_t contribution_strategy;
} pd_crowdloans_update_vault_V16_t;

#define PD_CALL_CROWDLOANS_OPEN_V16 2
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_open_V16_t;

#define PD_CALL_CROWDLOANS_CONTRIBUTE_V16 3
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_CompactBalance_t amount;
    pd_Vecu8_t referral_code;
} pd_crowdloans_contribute_V16_t;

#define PD_CALL_CROWDLOANS_SET_VRF_V16 4
typedef struct {
    pd_bool_t flag;
} pd_crowdloans_set_vrf_V16_t;

#define PD_CALL_CROWDLOANS_CLOSE_V16 5
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_close_V16_t;

#define PD_CALL_CROWDLOANS_REOPEN_V16 6
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_reopen_V16_t;

#define PD_CALL_CROWDLOANS_AUCTION_SUCCEEDED_V16 7
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_auction_succeeded_V16_t;

#define PD_CALL_CROWDLOANS_AUCTION_FAILED_V16 8
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_auction_failed_V16_t;

#define PD_CALL_CROWDLOANS_CLAIM_V16 9
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_claim_V16_t;

#define PD_CALL_CROWDLOANS_CLAIM_FOR_V16 10
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_claim_for_V16_t;

#define PD_CALL_CROWDLOANS_WITHDRAW_V16 11
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_withdraw_V16_t;

#define PD_CALL_CROWDLOANS_WITHDRAW_FOR_V16 12
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_withdraw_for_V16_t;

#define PD_CALL_CROWDLOANS_REDEEM_V16 13
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
    pd_CompactBalance_t amount;
} pd_crowdloans_redeem_V16_t;

#define PD_CALL_CROWDLOANS_SLOT_EXPIRED_V16 14
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_slot_expired_V16_t;

#define PD_CALL_CROWDLOANS_MIGRATE_PENDING_V16 15
typedef struct {
    pd_ParaId_V16_t crowdloan;
} pd_crowdloans_migrate_pending_V16_t;

#define PD_CALL_CROWDLOANS_REFUND_V16 17
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_refund_V16_t;

#define PD_CALL_CROWDLOANS_DISSOLVE_VAULT_V16 18
typedef struct {
    pd_ParaId_V16_t crowdloan;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_dissolve_vault_V16_t;

#define PD_CALL_CROWDLOANS_REFUND_FOR_V16 19
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_ParaId_V16_t crowdloan;
    pd_ChildStorageKind_V16_t kind;
    pd_CompactBalance_t amount;
    pd_LeasePeriod_V16_t lease_start;
    pd_LeasePeriod_V16_t lease_end;
} pd_crowdloans_refund_for_V16_t;

#define PD_CALL_LIQUIDSTAKING_STAKE_V16 0
typedef struct {
    pd_Compactu128_t amount;
} pd_liquidstaking_stake_V16_t;

#define PD_CALL_LIQUIDSTAKING_UNSTAKE_V16 1
typedef struct {
    pd_Compactu128_t liquid_amount;
} pd_liquidstaking_unstake_V16_t;

#define PD_CALL_LIQUIDSTAKING_UPDATE_RESERVE_FACTOR_V16 2
typedef struct {
    pd_Ratio_V16_t reserve_factor;
} pd_liquidstaking_update_reserve_factor_V16_t;

#define PD_CALL_LIQUIDSTAKING_UPDATE_STAKING_LEDGER_CAP_V16 3
typedef struct {
    pd_Compactu128_t cap;
} pd_liquidstaking_update_staking_ledger_cap_V16_t;

#define PD_CALL_LIQUIDSTAKING_BOND_V16 4
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_Compactu128_t amount;
    pd_RewardDestination_V16_t payee;
} pd_liquidstaking_bond_V16_t;

#define PD_CALL_LIQUIDSTAKING_BOND_EXTRA_V16 5
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_Compactu128_t amount;
} pd_liquidstaking_bond_extra_V16_t;

#define PD_CALL_LIQUIDSTAKING_UNBOND_V16 6
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_Compactu128_t amount;
} pd_liquidstaking_unbond_V16_t;

#define PD_CALL_LIQUIDSTAKING_REBOND_V16 7
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_Compactu128_t amount;
} pd_liquidstaking_rebond_V16_t;

#define PD_CALL_LIQUIDSTAKING_WITHDRAW_UNBONDED_V16 8
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_u32_t num_slashing_spans;
} pd_liquidstaking_withdraw_unbonded_V16_t;

#define PD_CALL_LIQUIDSTAKING_NOMINATE_V16 9
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_VecAccountId_V16_t targets;
} pd_liquidstaking_nominate_V16_t;

#define PD_CALL_LIQUIDSTAKING_CLAIM_FOR_V16 11
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
} pd_liquidstaking_claim_for_V16_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_ERA_START_BLOCK_V16 12
typedef struct {
    pd_BlockNumber_t block_number;
} pd_liquidstaking_force_set_era_start_block_V16_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_CURRENT_ERA_V16 13
typedef struct {
    pd_EraIndex_V16_t era;
} pd_liquidstaking_force_set_current_era_V16_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_ADVANCE_ERA_V16 14
typedef struct {
    pd_EraIndex_V16_t offset;
} pd_liquidstaking_force_advance_era_V16_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_MATCHING_V16 15
typedef struct {
} pd_liquidstaking_force_matching_V16_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_STAKING_LEDGER_V16 16
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_StakingLedgerAccountIdBalanceOfT_V16_t staking_ledger;
} pd_liquidstaking_force_set_staking_ledger_V16_t;

#define PD_CALL_LIQUIDSTAKING_SET_CURRENT_ERA_V16 17
typedef struct {
    pd_EraIndex_V16_t era;
    pd_VecVecu8_t proof;
} pd_liquidstaking_set_current_era_V16_t;

#define PD_CALL_LIQUIDSTAKING_SET_STAKING_LEDGER_V16 18
typedef struct {
    pd_DerivativeIndex_V16_t derivative_index;
    pd_StakingLedgerAccountIdBalanceOfT_V16_t staking_ledger;
    pd_VecVecu8_t proof;
} pd_liquidstaking_set_staking_ledger_V16_t;

#define PD_CALL_LIQUIDSTAKING_REDUCE_RESERVES_V16 19
typedef struct {
    pd_LookupasStaticLookupSource_V16_t receiver;
    pd_Compactu128_t reduce_amount;
} pd_liquidstaking_reduce_reserves_V16_t;

#define PD_CALL_LIQUIDSTAKING_CANCEL_UNSTAKE_V16 20
typedef struct {
    pd_Compactu128_t amount;
} pd_liquidstaking_cancel_unstake_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_ADD_MEMBER_V16 0
typedef struct {
    pd_AccountId_V16_t who;
} pd_generalcouncilmembership_add_member_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_REMOVE_MEMBER_V16 1
typedef struct {
    pd_AccountId_V16_t who;
} pd_generalcouncilmembership_remove_member_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_SWAP_MEMBER_V16 2
typedef struct {
    pd_AccountId_V16_t remove;
    pd_AccountId_V16_t add;
} pd_generalcouncilmembership_swap_member_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_RESET_MEMBERS_V16 3
typedef struct {
    pd_VecAccountId_V16_t members;
} pd_generalcouncilmembership_reset_members_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_CHANGE_KEY_V16 4
typedef struct {
    pd_AccountId_V16_t new_;
} pd_generalcouncilmembership_change_key_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_SET_PRIME_V16 5
typedef struct {
    pd_AccountId_V16_t who;
} pd_generalcouncilmembership_set_prime_V16_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_CLEAR_PRIME_V16 6
typedef struct {
} pd_generalcouncilmembership_clear_prime_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V16 0
typedef struct {
    pd_AccountId_V16_t who;
} pd_technicalcommitteemembership_add_member_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V16 1
typedef struct {
    pd_AccountId_V16_t who;
} pd_technicalcommitteemembership_remove_member_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V16 2
typedef struct {
    pd_AccountId_V16_t remove;
    pd_AccountId_V16_t add;
} pd_technicalcommitteemembership_swap_member_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V16 3
typedef struct {
    pd_VecAccountId_V16_t members;
} pd_technicalcommitteemembership_reset_members_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_CHANGE_KEY_V16 4
typedef struct {
    pd_AccountId_V16_t new_;
} pd_technicalcommitteemembership_change_key_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_PRIME_V16 5
typedef struct {
    pd_AccountId_V16_t who;
} pd_technicalcommitteemembership_set_prime_V16_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_CLEAR_PRIME_V16 6
typedef struct {
} pd_technicalcommitteemembership_clear_prime_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_ADD_MEMBER_V16 0
typedef struct {
    pd_AccountId_V16_t who;
} pd_oraclemembership_add_member_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_REMOVE_MEMBER_V16 1
typedef struct {
    pd_AccountId_V16_t who;
} pd_oraclemembership_remove_member_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_SWAP_MEMBER_V16 2
typedef struct {
    pd_AccountId_V16_t remove;
    pd_AccountId_V16_t add;
} pd_oraclemembership_swap_member_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_RESET_MEMBERS_V16 3
typedef struct {
    pd_VecAccountId_V16_t members;
} pd_oraclemembership_reset_members_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_CHANGE_KEY_V16 4
typedef struct {
    pd_AccountId_V16_t new_;
} pd_oraclemembership_change_key_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_SET_PRIME_V16 5
typedef struct {
    pd_AccountId_V16_t who;
} pd_oraclemembership_set_prime_V16_t;

#define PD_CALL_ORACLEMEMBERSHIP_CLEAR_PRIME_V16 6
typedef struct {
} pd_oraclemembership_clear_prime_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_ADD_MEMBER_V16 0
typedef struct {
    pd_AccountId_V16_t who;
} pd_liquidstakingagentsmembership_add_member_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_REMOVE_MEMBER_V16 1
typedef struct {
    pd_AccountId_V16_t who;
} pd_liquidstakingagentsmembership_remove_member_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_SWAP_MEMBER_V16 2
typedef struct {
    pd_AccountId_V16_t remove;
    pd_AccountId_V16_t add;
} pd_liquidstakingagentsmembership_swap_member_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_RESET_MEMBERS_V16 3
typedef struct {
    pd_VecAccountId_V16_t members;
} pd_liquidstakingagentsmembership_reset_members_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_CHANGE_KEY_V16 4
typedef struct {
    pd_AccountId_V16_t new_;
} pd_liquidstakingagentsmembership_change_key_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_SET_PRIME_V16 5
typedef struct {
    pd_AccountId_V16_t who;
} pd_liquidstakingagentsmembership_set_prime_V16_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_CLEAR_PRIME_V16 6
typedef struct {
} pd_liquidstakingagentsmembership_clear_prime_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_ADD_MEMBER_V16 0
typedef struct {
    pd_AccountId_V16_t who;
} pd_bridgemembership_add_member_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_REMOVE_MEMBER_V16 1
typedef struct {
    pd_AccountId_V16_t who;
} pd_bridgemembership_remove_member_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_SWAP_MEMBER_V16 2
typedef struct {
    pd_AccountId_V16_t remove;
    pd_AccountId_V16_t add;
} pd_bridgemembership_swap_member_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_RESET_MEMBERS_V16 3
typedef struct {
    pd_VecAccountId_V16_t members;
} pd_bridgemembership_reset_members_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_CHANGE_KEY_V16 4
typedef struct {
    pd_AccountId_V16_t new_;
} pd_bridgemembership_change_key_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_SET_PRIME_V16 5
typedef struct {
    pd_AccountId_V16_t who;
} pd_bridgemembership_set_prime_V16_t;

#define PD_CALL_BRIDGEMEMBERSHIP_CLEAR_PRIME_V16 6
typedef struct {
} pd_bridgemembership_clear_prime_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_ADD_MEMBER_V16 0
typedef struct {
    pd_AccountId_V16_t who;
} pd_crowdloansautomatorsmembership_add_member_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_REMOVE_MEMBER_V16 1
typedef struct {
    pd_AccountId_V16_t who;
} pd_crowdloansautomatorsmembership_remove_member_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_SWAP_MEMBER_V16 2
typedef struct {
    pd_AccountId_V16_t remove;
    pd_AccountId_V16_t add;
} pd_crowdloansautomatorsmembership_swap_member_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_RESET_MEMBERS_V16 3
typedef struct {
    pd_VecAccountId_V16_t members;
} pd_crowdloansautomatorsmembership_reset_members_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_CHANGE_KEY_V16 4
typedef struct {
    pd_AccountId_V16_t new_;
} pd_crowdloansautomatorsmembership_change_key_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_SET_PRIME_V16 5
typedef struct {
    pd_AccountId_V16_t who;
} pd_crowdloansautomatorsmembership_set_prime_V16_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_CLEAR_PRIME_V16 6
typedef struct {
} pd_crowdloansautomatorsmembership_clear_prime_V16_t;

#define PD_CALL_AMM_ADD_LIQUIDITY_V16 0
typedef struct {
    pd_AssetIdOfAssetIdOf_V16_t pair;
    pd_BalanceOfBalanceOf_V16_t desired_amounts;
    pd_BalanceOfBalanceOf_V16_t minimum_amounts;
} pd_amm_add_liquidity_V16_t;

#define PD_CALL_AMM_REMOVE_LIQUIDITY_V16 1
typedef struct {
    pd_AssetIdOfAssetIdOf_V16_t pair;
    pd_Compactu128_t liquidity;
} pd_amm_remove_liquidity_V16_t;

#define PD_CALL_AMM_CREATE_POOL_V16 2
typedef struct {
    pd_AssetIdOfAssetIdOf_V16_t pair;
    pd_BalanceOfBalanceOf_V16_t liquidity_amounts;
    pd_AccountId_V16_t lptoken_receiver;
    pd_AssetIdOf_V16_t lp_token_id;
} pd_amm_create_pool_V16_t;

#define PD_CALL_AMMROUTE_SWAP_EXACT_TOKENS_FOR_TOKENS_V16 0
typedef struct {
    pd_VecAssetIdOf_V16_t route;
    pd_Compactu128_t amount_in;
    pd_Compactu128_t min_amount_out;
} pd_ammroute_swap_exact_tokens_for_tokens_V16_t;

#define PD_CALL_AMMROUTE_SWAP_TOKENS_FOR_EXACT_TOKENS_V16 1
typedef struct {
    pd_VecAssetIdOf_V16_t route;
    pd_Compactu128_t amount_out;
    pd_Compactu128_t max_amount_in;
} pd_ammroute_swap_tokens_for_exact_tokens_V16_t;

#define PD_CALL_CURRENCYADAPTER_FORCE_SET_LOCK_V16 0
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AccountId_V16_t who;
    pd_Compactu128_t amount;
} pd_currencyadapter_force_set_lock_V16_t;

#define PD_CALL_CURRENCYADAPTER_FORCE_REMOVE_LOCK_V16 1
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AccountId_V16_t who;
} pd_currencyadapter_force_remove_lock_V16_t;

#define PD_CALL_BRIDGE_REGISTER_CHAIN_V16 0
typedef struct {
    pd_ChainId_V16_t chain_id;
} pd_bridge_register_chain_V16_t;

#define PD_CALL_BRIDGE_UNREGISTER_CHAIN_V16 1
typedef struct {
    pd_ChainId_V16_t chain_id;
} pd_bridge_unregister_chain_V16_t;

#define PD_CALL_BRIDGE_REGISTER_BRIDGE_TOKEN_V16 2
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_BridgeToken_V16_t bridge_token;
} pd_bridge_register_bridge_token_V16_t;

#define PD_CALL_BRIDGE_UNREGISTER_BRIDGE_TOKEN_V16 3
typedef struct {
    pd_CurrencyId_V16_t bridge_token_id;
} pd_bridge_unregister_bridge_token_V16_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_FEE_V16 4
typedef struct {
    pd_CurrencyId_V16_t bridge_token_id;
    pd_Balance_t new_fee;
} pd_bridge_set_bridge_token_fee_V16_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_STATUS_V16 5
typedef struct {
    pd_CurrencyId_V16_t bridge_token_id;
    pd_bool_t enable;
} pd_bridge_set_bridge_token_status_V16_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_CAP_V16 6
typedef struct {
    pd_CurrencyId_V16_t bridge_token_id;
    pd_BridgeType_V16_t bridge_type;
    pd_Balance_t new_cap;
} pd_bridge_set_bridge_token_cap_V16_t;

#define PD_CALL_BRIDGE_CLEAN_CAP_ACCUMULATED_VALUE_V16 7
typedef struct {
    pd_CurrencyId_V16_t bridge_token_id;
    pd_BridgeType_V16_t bridge_type;
} pd_bridge_clean_cap_accumulated_value_V16_t;

#define PD_CALL_BRIDGE_TELEPORT_V16 8
typedef struct {
    pd_ChainId_V16_t dest_id;
    pd_CurrencyId_V16_t bridge_token_id;
    pd_TeleAccount_V16_t to;
    pd_Balance_t amount;
} pd_bridge_teleport_V16_t;

#define PD_CALL_BRIDGE_MATERIALIZE_V16 9
typedef struct {
    pd_ChainId_V16_t src_id;
    pd_ChainNonce_V16_t src_nonce;
    pd_CurrencyId_V16_t bridge_token_id;
    pd_AccountId_V16_t to;
    pd_Balance_t amount;
    pd_bool_t favour;
} pd_bridge_materialize_V16_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_PALLET_V16 0
typedef struct {
    pd_u8_t pallet_idx;
} pd_emergencyshutdown_toggle_pallet_V16_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_CALL_V16 1
typedef struct {
    pd_u8_t pallet_idx;
    pd_u8_t call_idx;
} pd_emergencyshutdown_toggle_call_V16_t;

#define PD_CALL_FARMING_CREATE_V16 0
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_BlockNumber_t cool_down_duration;
} pd_farming_create_V16_t;

#define PD_CALL_FARMING_SET_POOL_STATUS_V16 1
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_bool_t is_active;
} pd_farming_set_pool_status_V16_t;

#define PD_CALL_FARMING_SET_POOL_COOL_DOWN_DURATION_V16 2
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_BlockNumber_t cool_down_duration;
} pd_farming_set_pool_cool_down_duration_V16_t;

#define PD_CALL_FARMING_RESET_POOL_UNLOCK_HEIGHT_V16 3
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_reset_pool_unlock_height_V16_t;

#define PD_CALL_FARMING_DEPOSIT_V16 4
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_Balance_t amount;
} pd_farming_deposit_V16_t;

#define PD_CALL_FARMING_WITHDRAW_V16 5
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_Balance_t amount;
} pd_farming_withdraw_V16_t;

#define PD_CALL_FARMING_REDEEM_V16 6
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_redeem_V16_t;

#define PD_CALL_FARMING_CLAIM_V16 7
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_claim_V16_t;

#define PD_CALL_FARMING_DISPATCH_REWARD_V16 8
typedef struct {
    pd_AssetIdOfT_V16_t asset;
    pd_AssetIdOfT_V16_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_LookupasStaticLookupSource_V16_t payer;
    pd_Balance_t amount;
    pd_BlockNumber_t reward_duration;
} pd_farming_dispatch_reward_V16_t;

#define PD_CALL_STREAMING_SET_MINIMUM_DEPOSIT_V16 3
typedef struct {
    pd_AssetIdOfT_V16_t asset_id;
    pd_Balance_t minimum_deposit;
} pd_streaming_set_minimum_deposit_V16_t;

#define PD_CALL_PARACHAINSYSTEM_AUTHORIZE_UPGRADE_V16 2
typedef struct {
    pd_Hash_t code_hash;
} pd_parachainsystem_authorize_upgrade_V16_t;

#define PD_CALL_PARACHAINSYSTEM_ENACT_AUTHORIZED_UPGRADE_V16 3
typedef struct {
    pd_Vecu8_t code;
} pd_parachainsystem_enact_authorized_upgrade_V16_t;

#endif

typedef union {
    pd_utility_batch_V16_t utility_batch_V16;
    pd_utility_batch_all_V16_t utility_batch_all_V16;
    pd_utility_force_batch_V16_t utility_force_batch_V16;
    pd_balances_transfer_all_V16_t balances_transfer_all_V16;
    pd_session_set_keys_V16_t session_set_keys_V16;
    pd_session_purge_keys_V16_t session_purge_keys_V16;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V16_t timestamp_set_V16;
    pd_balances_force_unreserve_V16_t balances_force_unreserve_V16;
    pd_assets_create_V16_t assets_create_V16;
    pd_assets_force_create_V16_t assets_force_create_V16;
    pd_assets_destroy_V16_t assets_destroy_V16;
    pd_assets_mint_V16_t assets_mint_V16;
    pd_assets_burn_V16_t assets_burn_V16;
    pd_assets_transfer_V16_t assets_transfer_V16;
    pd_assets_transfer_keep_alive_V16_t assets_transfer_keep_alive_V16;
    pd_assets_force_transfer_V16_t assets_force_transfer_V16;
    pd_assets_freeze_V16_t assets_freeze_V16;
    pd_assets_thaw_V16_t assets_thaw_V16;
    pd_assets_freeze_asset_V16_t assets_freeze_asset_V16;
    pd_assets_thaw_asset_V16_t assets_thaw_asset_V16;
    pd_assets_transfer_ownership_V16_t assets_transfer_ownership_V16;
    pd_assets_set_team_V16_t assets_set_team_V16;
    pd_assets_set_metadata_V16_t assets_set_metadata_V16;
    pd_assets_clear_metadata_V16_t assets_clear_metadata_V16;
    pd_assets_force_set_metadata_V16_t assets_force_set_metadata_V16;
    pd_assets_force_clear_metadata_V16_t assets_force_clear_metadata_V16;
    pd_assets_force_asset_status_V16_t assets_force_asset_status_V16;
    pd_assets_approve_transfer_V16_t assets_approve_transfer_V16;
    pd_assets_cancel_approval_V16_t assets_cancel_approval_V16;
    pd_assets_force_cancel_approval_V16_t assets_force_cancel_approval_V16;
    pd_assets_transfer_approved_V16_t assets_transfer_approved_V16;
    pd_assets_touch_V16_t assets_touch_V16;
    pd_assets_refund_V16_t assets_refund_V16;
    pd_proxy_add_proxy_V16_t proxy_add_proxy_V16;
    pd_proxy_remove_proxy_V16_t proxy_remove_proxy_V16;
    pd_proxy_remove_proxies_V16_t proxy_remove_proxies_V16;
    pd_proxy_anonymous_V16_t proxy_anonymous_V16;
    pd_proxy_kill_anonymous_V16_t proxy_kill_anonymous_V16;
    pd_proxy_announce_V16_t proxy_announce_V16;
    pd_proxy_remove_announcement_V16_t proxy_remove_announcement_V16;
    pd_proxy_reject_announcement_V16_t proxy_reject_announcement_V16;
    pd_proxy_proxy_announced_V16_t proxy_proxy_announced_V16;
    pd_identity_add_registrar_V16_t identity_add_registrar_V16;
    pd_identity_clear_identity_V16_t identity_clear_identity_V16;
    pd_identity_request_judgement_V16_t identity_request_judgement_V16;
    pd_identity_cancel_request_V16_t identity_cancel_request_V16;
    pd_identity_set_fee_V16_t identity_set_fee_V16;
    pd_identity_set_account_id_V16_t identity_set_account_id_V16;
    pd_identity_kill_identity_V16_t identity_kill_identity_V16;
    pd_identity_remove_sub_V16_t identity_remove_sub_V16;
    pd_identity_quit_sub_V16_t identity_quit_sub_V16;
    pd_democracy_propose_V16_t democracy_propose_V16;
    pd_democracy_second_V16_t democracy_second_V16;
    pd_democracy_emergency_cancel_V16_t democracy_emergency_cancel_V16;
    pd_democracy_external_propose_V16_t democracy_external_propose_V16;
    pd_democracy_external_propose_majority_V16_t democracy_external_propose_majority_V16;
    pd_democracy_external_propose_default_V16_t democracy_external_propose_default_V16;
    pd_democracy_fast_track_V16_t democracy_fast_track_V16;
    pd_democracy_veto_external_V16_t democracy_veto_external_V16;
    pd_democracy_cancel_referendum_V16_t democracy_cancel_referendum_V16;
    pd_democracy_cancel_queued_V16_t democracy_cancel_queued_V16;
    pd_democracy_delegate_V16_t democracy_delegate_V16;
    pd_democracy_undelegate_V16_t democracy_undelegate_V16;
    pd_democracy_clear_public_proposals_V16_t democracy_clear_public_proposals_V16;
    pd_democracy_note_preimage_V16_t democracy_note_preimage_V16;
    pd_democracy_note_preimage_operational_V16_t democracy_note_preimage_operational_V16;
    pd_democracy_note_imminent_preimage_V16_t democracy_note_imminent_preimage_V16;
    pd_democracy_note_imminent_preimage_operational_V16_t democracy_note_imminent_preimage_operational_V16;
    pd_democracy_reap_preimage_V16_t democracy_reap_preimage_V16;
    pd_democracy_unlock_V16_t democracy_unlock_V16;
    pd_democracy_remove_vote_V16_t democracy_remove_vote_V16;
    pd_democracy_remove_other_vote_V16_t democracy_remove_other_vote_V16;
    pd_democracy_enact_proposal_V16_t democracy_enact_proposal_V16;
    pd_democracy_cancel_proposal_V16_t democracy_cancel_proposal_V16;
    pd_generalcouncil_set_members_V16_t generalcouncil_set_members_V16;
    pd_generalcouncil_execute_V16_t generalcouncil_execute_V16;
    pd_generalcouncil_propose_V16_t generalcouncil_propose_V16;
    pd_generalcouncil_vote_V16_t generalcouncil_vote_V16;
    pd_generalcouncil_close_V16_t generalcouncil_close_V16;
    pd_generalcouncil_disapprove_proposal_V16_t generalcouncil_disapprove_proposal_V16;
    pd_technicalcommittee_set_members_V16_t technicalcommittee_set_members_V16;
    pd_technicalcommittee_execute_V16_t technicalcommittee_execute_V16;
    pd_technicalcommittee_propose_V16_t technicalcommittee_propose_V16;
    pd_technicalcommittee_vote_V16_t technicalcommittee_vote_V16;
    pd_technicalcommittee_close_V16_t technicalcommittee_close_V16;
    pd_technicalcommittee_disapprove_proposal_V16_t technicalcommittee_disapprove_proposal_V16;
    pd_treasury_propose_spend_V16_t treasury_propose_spend_V16;
    pd_treasury_reject_proposal_V16_t treasury_reject_proposal_V16;
    pd_treasury_approve_proposal_V16_t treasury_approve_proposal_V16;
    pd_treasury_remove_approval_V16_t treasury_remove_approval_V16;
    pd_preimage_note_preimage_V16_t preimage_note_preimage_V16;
    pd_preimage_unnote_preimage_V16_t preimage_unnote_preimage_V16;
    pd_preimage_request_preimage_V16_t preimage_request_preimage_V16;
    pd_preimage_unrequest_preimage_V16_t preimage_unrequest_preimage_V16;
    pd_xcmpqueue_service_overweight_V16_t xcmpqueue_service_overweight_V16;
    pd_xcmpqueue_suspend_xcm_execution_V16_t xcmpqueue_suspend_xcm_execution_V16;
    pd_xcmpqueue_resume_xcm_execution_V16_t xcmpqueue_resume_xcm_execution_V16;
    pd_xcmpqueue_update_suspend_threshold_V16_t xcmpqueue_update_suspend_threshold_V16;
    pd_xcmpqueue_update_drop_threshold_V16_t xcmpqueue_update_drop_threshold_V16;
    pd_xcmpqueue_update_resume_threshold_V16_t xcmpqueue_update_resume_threshold_V16;
    pd_xcmpqueue_update_threshold_weight_V16_t xcmpqueue_update_threshold_weight_V16;
    pd_xcmpqueue_update_weight_restrict_decay_V16_t xcmpqueue_update_weight_restrict_decay_V16;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V16_t xcmpqueue_update_xcmp_max_individual_weight_V16;
    pd_dmpqueue_service_overweight_V16_t dmpqueue_service_overweight_V16;
    pd_collatorselection_set_invulnerables_V16_t collatorselection_set_invulnerables_V16;
    pd_collatorselection_set_desired_candidates_V16_t collatorselection_set_desired_candidates_V16;
    pd_collatorselection_set_candidacy_bond_V16_t collatorselection_set_candidacy_bond_V16;
    pd_collatorselection_register_as_candidate_V16_t collatorselection_register_as_candidate_V16;
    pd_collatorselection_leave_intent_V16_t collatorselection_leave_intent_V16;
    pd_xtokens_transfer_V16_t xtokens_transfer_V16;
    pd_vesting_claim_V16_t vesting_claim_V16;
    pd_vesting_vested_transfer_V16_t vesting_vested_transfer_V16;
    pd_vesting_update_vesting_schedules_V16_t vesting_update_vesting_schedules_V16;
    pd_vesting_claim_for_V16_t vesting_claim_for_V16;
    pd_loans_add_market_V16_t loans_add_market_V16;
    pd_loans_activate_market_V16_t loans_activate_market_V16;
    pd_loans_update_rate_model_V16_t loans_update_rate_model_V16;
    pd_loans_update_market_V16_t loans_update_market_V16;
    pd_loans_force_update_market_V16_t loans_force_update_market_V16;
    pd_loans_add_reward_V16_t loans_add_reward_V16;
    pd_loans_withdraw_missing_reward_V16_t loans_withdraw_missing_reward_V16;
    pd_loans_update_market_reward_speed_V16_t loans_update_market_reward_speed_V16;
    pd_loans_claim_reward_V16_t loans_claim_reward_V16;
    pd_loans_claim_reward_for_market_V16_t loans_claim_reward_for_market_V16;
    pd_loans_mint_V16_t loans_mint_V16;
    pd_loans_redeem_V16_t loans_redeem_V16;
    pd_loans_redeem_all_V16_t loans_redeem_all_V16;
    pd_loans_borrow_V16_t loans_borrow_V16;
    pd_loans_repay_borrow_V16_t loans_repay_borrow_V16;
    pd_loans_repay_borrow_all_V16_t loans_repay_borrow_all_V16;
    pd_loans_collateral_asset_V16_t loans_collateral_asset_V16;
    pd_loans_liquidate_borrow_V16_t loans_liquidate_borrow_V16;
    pd_loans_add_reserves_V16_t loans_add_reserves_V16;
    pd_loans_reduce_reserves_V16_t loans_reduce_reserves_V16;
    pd_loans_reduce_incentive_reserves_V16_t loans_reduce_incentive_reserves_V16;
    pd_loans_update_liquidation_free_collateral_V16_t loans_update_liquidation_free_collateral_V16;
    pd_prices_set_price_V16_t prices_set_price_V16;
    pd_prices_reset_price_V16_t prices_reset_price_V16;
    pd_crowdloans_create_vault_V16_t crowdloans_create_vault_V16;
    pd_crowdloans_update_vault_V16_t crowdloans_update_vault_V16;
    pd_crowdloans_open_V16_t crowdloans_open_V16;
    pd_crowdloans_contribute_V16_t crowdloans_contribute_V16;
    pd_crowdloans_set_vrf_V16_t crowdloans_set_vrf_V16;
    pd_crowdloans_close_V16_t crowdloans_close_V16;
    pd_crowdloans_reopen_V16_t crowdloans_reopen_V16;
    pd_crowdloans_auction_succeeded_V16_t crowdloans_auction_succeeded_V16;
    pd_crowdloans_auction_failed_V16_t crowdloans_auction_failed_V16;
    pd_crowdloans_claim_V16_t crowdloans_claim_V16;
    pd_crowdloans_claim_for_V16_t crowdloans_claim_for_V16;
    pd_crowdloans_withdraw_V16_t crowdloans_withdraw_V16;
    pd_crowdloans_withdraw_for_V16_t crowdloans_withdraw_for_V16;
    pd_crowdloans_redeem_V16_t crowdloans_redeem_V16;
    pd_crowdloans_slot_expired_V16_t crowdloans_slot_expired_V16;
    pd_crowdloans_migrate_pending_V16_t crowdloans_migrate_pending_V16;
    pd_crowdloans_refund_V16_t crowdloans_refund_V16;
    pd_crowdloans_dissolve_vault_V16_t crowdloans_dissolve_vault_V16;
    pd_crowdloans_refund_for_V16_t crowdloans_refund_for_V16;
    pd_liquidstaking_stake_V16_t liquidstaking_stake_V16;
    pd_liquidstaking_unstake_V16_t liquidstaking_unstake_V16;
    pd_liquidstaking_update_reserve_factor_V16_t liquidstaking_update_reserve_factor_V16;
    pd_liquidstaking_update_staking_ledger_cap_V16_t liquidstaking_update_staking_ledger_cap_V16;
    pd_liquidstaking_bond_V16_t liquidstaking_bond_V16;
    pd_liquidstaking_bond_extra_V16_t liquidstaking_bond_extra_V16;
    pd_liquidstaking_unbond_V16_t liquidstaking_unbond_V16;
    pd_liquidstaking_rebond_V16_t liquidstaking_rebond_V16;
    pd_liquidstaking_withdraw_unbonded_V16_t liquidstaking_withdraw_unbonded_V16;
    pd_liquidstaking_nominate_V16_t liquidstaking_nominate_V16;
    pd_liquidstaking_claim_for_V16_t liquidstaking_claim_for_V16;
    pd_liquidstaking_force_set_era_start_block_V16_t liquidstaking_force_set_era_start_block_V16;
    pd_liquidstaking_force_set_current_era_V16_t liquidstaking_force_set_current_era_V16;
    pd_liquidstaking_force_advance_era_V16_t liquidstaking_force_advance_era_V16;
    pd_liquidstaking_force_matching_V16_t liquidstaking_force_matching_V16;
    pd_liquidstaking_force_set_staking_ledger_V16_t liquidstaking_force_set_staking_ledger_V16;
    pd_liquidstaking_set_current_era_V16_t liquidstaking_set_current_era_V16;
    pd_liquidstaking_set_staking_ledger_V16_t liquidstaking_set_staking_ledger_V16;
    pd_liquidstaking_reduce_reserves_V16_t liquidstaking_reduce_reserves_V16;
    pd_liquidstaking_cancel_unstake_V16_t liquidstaking_cancel_unstake_V16;
    pd_generalcouncilmembership_add_member_V16_t generalcouncilmembership_add_member_V16;
    pd_generalcouncilmembership_remove_member_V16_t generalcouncilmembership_remove_member_V16;
    pd_generalcouncilmembership_swap_member_V16_t generalcouncilmembership_swap_member_V16;
    pd_generalcouncilmembership_reset_members_V16_t generalcouncilmembership_reset_members_V16;
    pd_generalcouncilmembership_change_key_V16_t generalcouncilmembership_change_key_V16;
    pd_generalcouncilmembership_set_prime_V16_t generalcouncilmembership_set_prime_V16;
    pd_generalcouncilmembership_clear_prime_V16_t generalcouncilmembership_clear_prime_V16;
    pd_technicalcommitteemembership_add_member_V16_t technicalcommitteemembership_add_member_V16;
    pd_technicalcommitteemembership_remove_member_V16_t technicalcommitteemembership_remove_member_V16;
    pd_technicalcommitteemembership_swap_member_V16_t technicalcommitteemembership_swap_member_V16;
    pd_technicalcommitteemembership_reset_members_V16_t technicalcommitteemembership_reset_members_V16;
    pd_technicalcommitteemembership_change_key_V16_t technicalcommitteemembership_change_key_V16;
    pd_technicalcommitteemembership_set_prime_V16_t technicalcommitteemembership_set_prime_V16;
    pd_technicalcommitteemembership_clear_prime_V16_t technicalcommitteemembership_clear_prime_V16;
    pd_oraclemembership_add_member_V16_t oraclemembership_add_member_V16;
    pd_oraclemembership_remove_member_V16_t oraclemembership_remove_member_V16;
    pd_oraclemembership_swap_member_V16_t oraclemembership_swap_member_V16;
    pd_oraclemembership_reset_members_V16_t oraclemembership_reset_members_V16;
    pd_oraclemembership_change_key_V16_t oraclemembership_change_key_V16;
    pd_oraclemembership_set_prime_V16_t oraclemembership_set_prime_V16;
    pd_oraclemembership_clear_prime_V16_t oraclemembership_clear_prime_V16;
    pd_liquidstakingagentsmembership_add_member_V16_t liquidstakingagentsmembership_add_member_V16;
    pd_liquidstakingagentsmembership_remove_member_V16_t liquidstakingagentsmembership_remove_member_V16;
    pd_liquidstakingagentsmembership_swap_member_V16_t liquidstakingagentsmembership_swap_member_V16;
    pd_liquidstakingagentsmembership_reset_members_V16_t liquidstakingagentsmembership_reset_members_V16;
    pd_liquidstakingagentsmembership_change_key_V16_t liquidstakingagentsmembership_change_key_V16;
    pd_liquidstakingagentsmembership_set_prime_V16_t liquidstakingagentsmembership_set_prime_V16;
    pd_liquidstakingagentsmembership_clear_prime_V16_t liquidstakingagentsmembership_clear_prime_V16;
    pd_bridgemembership_add_member_V16_t bridgemembership_add_member_V16;
    pd_bridgemembership_remove_member_V16_t bridgemembership_remove_member_V16;
    pd_bridgemembership_swap_member_V16_t bridgemembership_swap_member_V16;
    pd_bridgemembership_reset_members_V16_t bridgemembership_reset_members_V16;
    pd_bridgemembership_change_key_V16_t bridgemembership_change_key_V16;
    pd_bridgemembership_set_prime_V16_t bridgemembership_set_prime_V16;
    pd_bridgemembership_clear_prime_V16_t bridgemembership_clear_prime_V16;
    pd_crowdloansautomatorsmembership_add_member_V16_t crowdloansautomatorsmembership_add_member_V16;
    pd_crowdloansautomatorsmembership_remove_member_V16_t crowdloansautomatorsmembership_remove_member_V16;
    pd_crowdloansautomatorsmembership_swap_member_V16_t crowdloansautomatorsmembership_swap_member_V16;
    pd_crowdloansautomatorsmembership_reset_members_V16_t crowdloansautomatorsmembership_reset_members_V16;
    pd_crowdloansautomatorsmembership_change_key_V16_t crowdloansautomatorsmembership_change_key_V16;
    pd_crowdloansautomatorsmembership_set_prime_V16_t crowdloansautomatorsmembership_set_prime_V16;
    pd_crowdloansautomatorsmembership_clear_prime_V16_t crowdloansautomatorsmembership_clear_prime_V16;
    pd_amm_add_liquidity_V16_t amm_add_liquidity_V16;
    pd_amm_remove_liquidity_V16_t amm_remove_liquidity_V16;
    pd_amm_create_pool_V16_t amm_create_pool_V16;
    pd_ammroute_swap_exact_tokens_for_tokens_V16_t ammroute_swap_exact_tokens_for_tokens_V16;
    pd_ammroute_swap_tokens_for_exact_tokens_V16_t ammroute_swap_tokens_for_exact_tokens_V16;
    pd_currencyadapter_force_set_lock_V16_t currencyadapter_force_set_lock_V16;
    pd_currencyadapter_force_remove_lock_V16_t currencyadapter_force_remove_lock_V16;
    pd_bridge_register_chain_V16_t bridge_register_chain_V16;
    pd_bridge_unregister_chain_V16_t bridge_unregister_chain_V16;
    pd_bridge_register_bridge_token_V16_t bridge_register_bridge_token_V16;
    pd_bridge_unregister_bridge_token_V16_t bridge_unregister_bridge_token_V16;
    pd_bridge_set_bridge_token_fee_V16_t bridge_set_bridge_token_fee_V16;
    pd_bridge_set_bridge_token_status_V16_t bridge_set_bridge_token_status_V16;
    pd_bridge_set_bridge_token_cap_V16_t bridge_set_bridge_token_cap_V16;
    pd_bridge_clean_cap_accumulated_value_V16_t bridge_clean_cap_accumulated_value_V16;
    pd_bridge_teleport_V16_t bridge_teleport_V16;
    pd_bridge_materialize_V16_t bridge_materialize_V16;
    pd_emergencyshutdown_toggle_pallet_V16_t emergencyshutdown_toggle_pallet_V16;
    pd_emergencyshutdown_toggle_call_V16_t emergencyshutdown_toggle_call_V16;
    pd_farming_create_V16_t farming_create_V16;
    pd_farming_set_pool_status_V16_t farming_set_pool_status_V16;
    pd_farming_set_pool_cool_down_duration_V16_t farming_set_pool_cool_down_duration_V16;
    pd_farming_reset_pool_unlock_height_V16_t farming_reset_pool_unlock_height_V16;
    pd_farming_deposit_V16_t farming_deposit_V16;
    pd_farming_withdraw_V16_t farming_withdraw_V16;
    pd_farming_redeem_V16_t farming_redeem_V16;
    pd_farming_claim_V16_t farming_claim_V16;
    pd_farming_dispatch_reward_V16_t farming_dispatch_reward_V16;
    pd_streaming_set_minimum_deposit_V16_t streaming_set_minimum_deposit_V16;
    pd_parachainsystem_authorize_upgrade_V16_t parachainsystem_authorize_upgrade_V16;
    pd_parachainsystem_enact_authorized_upgrade_V16_t parachainsystem_enact_authorized_upgrade_V16;
#endif
} pd_MethodBasic_V16_t;

#define PD_CALL_BALANCES_TRANSFER_V16 0
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V16_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V16 2
typedef struct {
    pd_LookupasStaticLookupSource_V16_t source;
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V16_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V16 3
typedef struct {
    pd_LookupasStaticLookupSource_V16_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V16_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V16 0
typedef struct {
    pd_Perbill_V16_t ratio;
} pd_system_fill_block_V16_t;

#define PD_CALL_SYSTEM_REMARK_V16 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V16_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V16 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V16_t;

#define PD_CALL_SYSTEM_SET_CODE_V16 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V16_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V16 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V16_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V16 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V16_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V16 0
typedef struct {
    pd_VecAccountId_V16_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V16_t;

#define PD_CALL_MULTISIG_AS_MULTI_V16 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V16_t other_signatories;
    pd_OptionTimepoint_V16_t maybe_timepoint;
    pd_OpaqueCall_V16_t call;
    pd_bool_t store_call;
    pd_Weight_V16_t max_weight;
} pd_multisig_as_multi_V16_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V16 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V16_t other_signatories;
    pd_OptionTimepoint_V16_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V16_t max_weight;
} pd_multisig_approve_as_multi_V16_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V16 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V16_t other_signatories;
    pd_Timepoint_V16_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V16_t;

#define PD_CALL_BALANCES_SET_BALANCE_V16 1
typedef struct {
    pd_LookupasStaticLookupSource_V16_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V16_t;

#define PD_CALL_PROXY_PROXY_V16 0
typedef struct {
    pd_AccountId_V16_t real;
    pd_OptionProxyType_V16_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V16_t;

#endif

typedef union {
    pd_balances_transfer_V16_t balances_transfer_V16;
    pd_balances_force_transfer_V16_t balances_force_transfer_V16;
    pd_balances_transfer_keep_alive_V16_t balances_transfer_keep_alive_V16;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V16_t system_fill_block_V16;
    pd_system_remark_V16_t system_remark_V16;
    pd_system_set_heap_pages_V16_t system_set_heap_pages_V16;
    pd_system_set_code_V16_t system_set_code_V16;
    pd_system_set_code_without_checks_V16_t system_set_code_without_checks_V16;
    pd_system_remark_with_event_V16_t system_remark_with_event_V16;
    pd_multisig_as_multi_threshold_1_V16_t multisig_as_multi_threshold_1_V16;
    pd_multisig_as_multi_V16_t multisig_as_multi_V16;
    pd_multisig_approve_as_multi_V16_t multisig_approve_as_multi_V16;
    pd_multisig_cancel_as_multi_V16_t multisig_cancel_as_multi_V16;
    pd_balances_set_balance_V16_t balances_set_balance_V16;
    pd_proxy_proxy_V16_t proxy_proxy_V16;
#endif
} pd_MethodNested_V16_t;

typedef union {
    pd_MethodBasic_V16_t basic;
    pd_MethodNested_V16_t nested;
} pd_Method_V16_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
