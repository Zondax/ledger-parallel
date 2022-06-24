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
#include "substrate_types_V17.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V17 0
#define PD_CALL_TIMESTAMP_V17 1
#define PD_CALL_UTILITY_V17 2
#define PD_CALL_MULTISIG_V17 3
#define PD_CALL_BALANCES_V17 4
#define PD_CALL_ASSETS_V17 6
#define PD_CALL_PROXY_V17 7
#define PD_CALL_IDENTITY_V17 8
#define PD_CALL_DEMOCRACY_V17 11
#define PD_CALL_GENERALCOUNCIL_V17 12
#define PD_CALL_TECHNICALCOMMITTEE_V17 13
#define PD_CALL_TREASURY_V17 14
#define PD_CALL_PREIMAGE_V17 16
#define PD_CALL_XCMPQUEUE_V17 22
#define PD_CALL_DMPQUEUE_V17 23
#define PD_CALL_COLLATORSELECTION_V17 31
#define PD_CALL_SESSION_V17 32
#define PD_CALL_XTOKENS_V17 43
#define PD_CALL_VESTING_V17 46
#define PD_CALL_LOANS_V17 50
#define PD_CALL_PRICES_V17 51
#define PD_CALL_CROWDLOANS_V17 52
#define PD_CALL_LIQUIDSTAKING_V17 60
#define PD_CALL_GENERALCOUNCILMEMBERSHIP_V17 70
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V17 71
#define PD_CALL_ORACLEMEMBERSHIP_V17 72
#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_V17 73
#define PD_CALL_BRIDGEMEMBERSHIP_V17 74
#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_V17 75
#define PD_CALL_AMM_V17 80
#define PD_CALL_AMMROUTE_V17 81
#define PD_CALL_CURRENCYADAPTER_V17 82
#define PD_CALL_BRIDGE_V17 90
#define PD_CALL_EMERGENCYSHUTDOWN_V17 91
#define PD_CALL_FARMING_V17 92
#define PD_CALL_STREAMING_V17 94
#define PD_CALL_PARACHAINSYSTEM_V17 20

#define PD_CALL_UTILITY_BATCH_V17 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V17_t;

#define PD_CALL_UTILITY_BATCH_ALL_V17 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V17_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V17 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V17_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V17 4
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V17_t;

#define PD_CALL_SESSION_SET_KEYS_V17 0
typedef struct {
    pd_Keys_V17_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V17_t;

#define PD_CALL_SESSION_PURGE_KEYS_V17 1
typedef struct {
} pd_session_purge_keys_V17_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V17 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V17_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V17 5
typedef struct {
    pd_LookupasStaticLookupSource_V17_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V17_t;

#define PD_CALL_ASSETS_CREATE_V17 0
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t admin;
    pd_Balance_t min_balance;
} pd_assets_create_V17_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V17 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t owner;
    pd_bool_t is_sufficient;
    pd_Compactu128_t min_balance;
} pd_assets_force_create_V17_t;

#define PD_CALL_ASSETS_DESTROY_V17 2
typedef struct {
    pd_Compactu32_t id;
    pd_DestroyWitness_V17_t witness;
} pd_assets_destroy_V17_t;

#define PD_CALL_ASSETS_MINT_V17 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t beneficiary;
    pd_Compactu128_t amount;
} pd_assets_mint_V17_t;

#define PD_CALL_ASSETS_BURN_V17 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t who;
    pd_Compactu128_t amount;
} pd_assets_burn_V17_t;

#define PD_CALL_ASSETS_TRANSFER_V17 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t target;
    pd_Compactu128_t amount;
} pd_assets_transfer_V17_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V17 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t target;
    pd_Compactu128_t amount;
} pd_assets_transfer_keep_alive_V17_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V17 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t source;
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_Compactu128_t amount;
} pd_assets_force_transfer_V17_t;

#define PD_CALL_ASSETS_FREEZE_V17 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t who;
} pd_assets_freeze_V17_t;

#define PD_CALL_ASSETS_THAW_V17 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t who;
} pd_assets_thaw_V17_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V17 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V17_t;

#define PD_CALL_ASSETS_THAW_ASSET_V17 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V17_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V17 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t owner;
} pd_assets_transfer_ownership_V17_t;

#define PD_CALL_ASSETS_SET_TEAM_V17 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t issuer;
    pd_LookupasStaticLookupSource_V17_t admin;
    pd_LookupasStaticLookupSource_V17_t freezer;
} pd_assets_set_team_V17_t;

#define PD_CALL_ASSETS_SET_METADATA_V17 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V17_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V17 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V17_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V17 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V17_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V17 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V17_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V17 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t owner;
    pd_LookupasStaticLookupSource_V17_t issuer;
    pd_LookupasStaticLookupSource_V17_t admin;
    pd_LookupasStaticLookupSource_V17_t freezer;
    pd_Compactu128_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V17_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V17 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t delegate;
    pd_Compactu128_t amount;
} pd_assets_approve_transfer_V17_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V17 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t delegate;
} pd_assets_cancel_approval_V17_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V17 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t owner;
    pd_LookupasStaticLookupSource_V17_t delegate;
} pd_assets_force_cancel_approval_V17_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V17 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V17_t owner;
    pd_LookupasStaticLookupSource_V17_t destination;
    pd_Compactu128_t amount;
} pd_assets_transfer_approved_V17_t;

#define PD_CALL_ASSETS_TOUCH_V17 23
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V17_t;

#define PD_CALL_ASSETS_REFUND_V17 24
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V17_t;

#define PD_CALL_PROXY_ADD_PROXY_V17 1
typedef struct {
    pd_AccountId_V17_t delegate;
    pd_ProxyType_V17_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V17_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V17 2
typedef struct {
    pd_AccountId_V17_t delegate;
    pd_ProxyType_V17_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V17_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V17 3
typedef struct {
} pd_proxy_remove_proxies_V17_t;

#define PD_CALL_PROXY_ANONYMOUS_V17 4
typedef struct {
    pd_ProxyType_V17_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V17_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V17 5
typedef struct {
    pd_AccountId_V17_t spawner;
    pd_ProxyType_V17_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V17_t;

#define PD_CALL_PROXY_ANNOUNCE_V17 6
typedef struct {
    pd_AccountId_V17_t real;
    pd_CallHashOf_V17_t call_hash;
} pd_proxy_announce_V17_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V17 7
typedef struct {
    pd_AccountId_V17_t real;
    pd_CallHashOf_V17_t call_hash;
} pd_proxy_remove_announcement_V17_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V17 8
typedef struct {
    pd_AccountId_V17_t delegate;
    pd_CallHashOf_V17_t call_hash;
} pd_proxy_reject_announcement_V17_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V17 9
typedef struct {
    pd_AccountId_V17_t delegate;
    pd_AccountId_V17_t real;
    pd_OptionProxyType_V17_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V17_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V17 0
typedef struct {
    pd_AccountId_V17_t account;
} pd_identity_add_registrar_V17_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V17 3
typedef struct {
} pd_identity_clear_identity_V17_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V17 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V17_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V17 5
typedef struct {
    pd_RegistrarIndex_V17_t reg_index;
} pd_identity_cancel_request_V17_t;

#define PD_CALL_IDENTITY_SET_FEE_V17 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V17_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V17 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V17_t new_;
} pd_identity_set_account_id_V17_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V17 10
typedef struct {
    pd_LookupasStaticLookupSource_V17_t target;
} pd_identity_kill_identity_V17_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V17 13
typedef struct {
    pd_LookupasStaticLookupSource_V17_t sub;
} pd_identity_remove_sub_V17_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V17 14
typedef struct {
} pd_identity_quit_sub_V17_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V17 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V17_t;

#define PD_CALL_DEMOCRACY_SECOND_V17 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V17_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V17 3
typedef struct {
    pd_ReferendumIndex_V17_t ref_index;
} pd_democracy_emergency_cancel_V17_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V17 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V17_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V17 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V17_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V17 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V17_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V17 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V17_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V17 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V17_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V17 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V17_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V17 10
typedef struct {
    pd_ReferendumIndex_V17_t which;
} pd_democracy_cancel_queued_V17_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V17 11
typedef struct {
    pd_AccountId_V17_t to;
    pd_Conviction_V17_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V17_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V17 12
typedef struct {
} pd_democracy_undelegate_V17_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V17 13
typedef struct {
} pd_democracy_clear_public_proposals_V17_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V17 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V17_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V17 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V17_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V17 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V17_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V17 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V17_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V17 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V17_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V17 19
typedef struct {
    pd_AccountId_V17_t target;
} pd_democracy_unlock_V17_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V17 20
typedef struct {
    pd_ReferendumIndex_V17_t index;
} pd_democracy_remove_vote_V17_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V17 21
typedef struct {
    pd_AccountId_V17_t target;
    pd_ReferendumIndex_V17_t index;
} pd_democracy_remove_other_vote_V17_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V17 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V17_t index;
} pd_democracy_enact_proposal_V17_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V17 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V17_t;

#define PD_CALL_GENERALCOUNCIL_SET_MEMBERS_V17 0
typedef struct {
    pd_VecAccountId_V17_t new_members;
    pd_OptionAccountId_V17_t prime;
    pd_MemberCount_V17_t old_count;
} pd_generalcouncil_set_members_V17_t;

#define PD_CALL_GENERALCOUNCIL_EXECUTE_V17 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_execute_V17_t;

#define PD_CALL_GENERALCOUNCIL_PROPOSE_V17 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_propose_V17_t;

#define PD_CALL_GENERALCOUNCIL_VOTE_V17 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_generalcouncil_vote_V17_t;

#define PD_CALL_GENERALCOUNCIL_CLOSE_V17 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_close_V17_t;

#define PD_CALL_GENERALCOUNCIL_DISAPPROVE_PROPOSAL_V17 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_generalcouncil_disapprove_proposal_V17_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V17 0
typedef struct {
    pd_VecAccountId_V17_t new_members;
    pd_OptionAccountId_V17_t prime;
    pd_MemberCount_V17_t old_count;
} pd_technicalcommittee_set_members_V17_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V17 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V17_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V17 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V17_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V17 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V17_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V17 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V17_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V17 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V17_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V17 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V17_t beneficiary;
} pd_treasury_propose_spend_V17_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V17 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V17_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V17 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V17_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V17 3
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V17_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V17 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V17_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V17 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V17_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V17 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V17_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V17 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V17_t;

#define PD_CALL_XCMPQUEUE_SERVICE_OVERWEIGHT_V17 0
typedef struct {
    pd_OverweightIndex_V17_t index;
    pd_Weight_V17_t weight_limit;
} pd_xcmpqueue_service_overweight_V17_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V17 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V17_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V17 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V17_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V17 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V17_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V17 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V17_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V17 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V17_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V17 6
typedef struct {
    pd_Weight_V17_t new_;
} pd_xcmpqueue_update_threshold_weight_V17_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V17 7
typedef struct {
    pd_Weight_V17_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V17_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V17 8
typedef struct {
    pd_Weight_V17_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V17_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V17 0
typedef struct {
    pd_OverweightIndex_V17_t index;
    pd_Weight_V17_t weight_limit;
} pd_dmpqueue_service_overweight_V17_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V17 0
typedef struct {
    pd_VecAccountId_V17_t new_;
} pd_collatorselection_set_invulnerables_V17_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V17 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V17_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V17 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V17_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V17 3
typedef struct {
} pd_collatorselection_register_as_candidate_V17_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V17 4
typedef struct {
} pd_collatorselection_leave_intent_V17_t;

#define PD_CALL_XTOKENS_TRANSFER_V17 0
typedef struct {
    pd_CurrencyId_V17_t currency_id;
    pd_Balance_t amount;
    pd_BoxVersionedMultiLocation_V17_t dest;
    pd_Weight_V17_t dest_weight;
} pd_xtokens_transfer_V17_t;

#define PD_CALL_VESTING_CLAIM_V17 0
typedef struct {
} pd_vesting_claim_V17_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V17 1
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_VestingScheduleOf_V17_t schedule;
} pd_vesting_vested_transfer_V17_t;

#define PD_CALL_VESTING_UPDATE_VESTING_SCHEDULES_V17 2
typedef struct {
    pd_LookupasStaticLookupSource_V17_t who;
    pd_VecVestingScheduleOf_V17_t vesting_schedules;
} pd_vesting_update_vesting_schedules_V17_t;

#define PD_CALL_VESTING_CLAIM_FOR_V17 3
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
} pd_vesting_claim_for_V17_t;

#define PD_CALL_LOANS_ADD_MARKET_V17 0
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_MarketBalanceOfT_V17_t market;
} pd_loans_add_market_V17_t;

#define PD_CALL_LOANS_ACTIVATE_MARKET_V17 1
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
} pd_loans_activate_market_V17_t;

#define PD_CALL_LOANS_UPDATE_RATE_MODEL_V17 2
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_InterestRateModel_V17_t rate_model;
} pd_loans_update_rate_model_V17_t;

#define PD_CALL_LOANS_UPDATE_MARKET_V17 3
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_OptionRatio_V17_t collateral_factor;
    pd_OptionRatio_V17_t liquidation_threshold;
    pd_OptionRatio_V17_t reserve_factor;
    pd_OptionRatio_V17_t close_factor;
    pd_OptionRatio_V17_t liquidate_incentive_reserved_factor;
    pd_OptionRate_V17_t liquidate_incentive;
    pd_OptionBalance_t supply_cap;
    pd_OptionBalance_t borrow_cap;
} pd_loans_update_market_V17_t;

#define PD_CALL_LOANS_FORCE_UPDATE_MARKET_V17 4
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_MarketBalanceOfT_V17_t market;
} pd_loans_force_update_market_V17_t;

#define PD_CALL_LOANS_ADD_REWARD_V17 5
typedef struct {
    pd_Balance_t amount;
} pd_loans_add_reward_V17_t;

#define PD_CALL_LOANS_WITHDRAW_MISSING_REWARD_V17 6
typedef struct {
    pd_LookupasStaticLookupSource_V17_t target_account;
    pd_Balance_t amount;
} pd_loans_withdraw_missing_reward_V17_t;

#define PD_CALL_LOANS_UPDATE_MARKET_REWARD_SPEED_V17 7
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_OptionBalance_t supply_reward_per_block;
    pd_OptionBalance_t borrow_reward_per_block;
} pd_loans_update_market_reward_speed_V17_t;

#define PD_CALL_LOANS_CLAIM_REWARD_V17 8
typedef struct {
} pd_loans_claim_reward_V17_t;

#define PD_CALL_LOANS_CLAIM_REWARD_FOR_MARKET_V17 9
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
} pd_loans_claim_reward_for_market_V17_t;

#define PD_CALL_LOANS_MINT_V17 10
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t mint_amount;
} pd_loans_mint_V17_t;

#define PD_CALL_LOANS_REDEEM_V17 11
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t redeem_amount;
} pd_loans_redeem_V17_t;

#define PD_CALL_LOANS_REDEEM_ALL_V17 12
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
} pd_loans_redeem_all_V17_t;

#define PD_CALL_LOANS_BORROW_V17 13
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t borrow_amount;
} pd_loans_borrow_V17_t;

#define PD_CALL_LOANS_REPAY_BORROW_V17 14
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t repay_amount;
} pd_loans_repay_borrow_V17_t;

#define PD_CALL_LOANS_REPAY_BORROW_ALL_V17 15
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
} pd_loans_repay_borrow_all_V17_t;

#define PD_CALL_LOANS_COLLATERAL_ASSET_V17 16
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_bool_t enable;
} pd_loans_collateral_asset_V17_t;

#define PD_CALL_LOANS_LIQUIDATE_BORROW_V17 17
typedef struct {
    pd_AccountId_V17_t borrower;
    pd_AssetIdOfT_V17_t liquidation_asset_id;
    pd_Compactu128_t repay_amount;
    pd_AssetIdOfT_V17_t collateral_asset_id;
} pd_loans_liquidate_borrow_V17_t;

#define PD_CALL_LOANS_ADD_RESERVES_V17 18
typedef struct {
    pd_LookupasStaticLookupSource_V17_t payer;
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t add_amount;
} pd_loans_add_reserves_V17_t;

#define PD_CALL_LOANS_REDUCE_RESERVES_V17 19
typedef struct {
    pd_LookupasStaticLookupSource_V17_t receiver;
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t reduce_amount;
} pd_loans_reduce_reserves_V17_t;

#define PD_CALL_LOANS_REDUCE_INCENTIVE_RESERVES_V17 20
typedef struct {
    pd_LookupasStaticLookupSource_V17_t receiver;
    pd_AssetIdOfT_V17_t asset_id;
    pd_Compactu128_t redeem_amount;
} pd_loans_reduce_incentive_reserves_V17_t;

#define PD_CALL_LOANS_UPDATE_LIQUIDATION_FREE_COLLATERAL_V17 21
typedef struct {
    pd_VecAssetIdOf_V17_t collaterals;
} pd_loans_update_liquidation_free_collateral_V17_t;

#define PD_CALL_PRICES_SET_PRICE_V17 0
typedef struct {
    pd_CurrencyId_V17_t asset_id;
    pd_Price_V17_t price;
} pd_prices_set_price_V17_t;

#define PD_CALL_PRICES_RESET_PRICE_V17 1
typedef struct {
    pd_CurrencyId_V17_t asset_id;
} pd_prices_reset_price_V17_t;

#define PD_CALL_CROWDLOANS_CREATE_VAULT_V17 0
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_AssetIdOfT_V17_t ctoken;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
    pd_ContributionStrategy_V17_t contribution_strategy;
    pd_CompactBalance_t cap;
    pd_BlockNumber_t end_block;
} pd_crowdloans_create_vault_V17_t;

#define PD_CALL_CROWDLOANS_UPDATE_VAULT_V17 1
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_OptionBalance_t cap;
    pd_OptionBlockNumber_t end_block;
    pd_OptionContributionStrategy_V17_t contribution_strategy;
} pd_crowdloans_update_vault_V17_t;

#define PD_CALL_CROWDLOANS_OPEN_V17 2
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_open_V17_t;

#define PD_CALL_CROWDLOANS_CONTRIBUTE_V17 3
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_CompactBalance_t amount;
    pd_Vecu8_t referral_code;
} pd_crowdloans_contribute_V17_t;

#define PD_CALL_CROWDLOANS_SET_VRF_V17 4
typedef struct {
    pd_bool_t flag;
} pd_crowdloans_set_vrf_V17_t;

#define PD_CALL_CROWDLOANS_CLOSE_V17 5
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_close_V17_t;

#define PD_CALL_CROWDLOANS_REOPEN_V17 6
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_reopen_V17_t;

#define PD_CALL_CROWDLOANS_AUCTION_SUCCEEDED_V17 7
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_auction_succeeded_V17_t;

#define PD_CALL_CROWDLOANS_AUCTION_FAILED_V17 8
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_auction_failed_V17_t;

#define PD_CALL_CROWDLOANS_CLAIM_V17 9
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_claim_V17_t;

#define PD_CALL_CROWDLOANS_CLAIM_FOR_V17 10
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_claim_for_V17_t;

#define PD_CALL_CROWDLOANS_WITHDRAW_V17 11
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_withdraw_V17_t;

#define PD_CALL_CROWDLOANS_WITHDRAW_FOR_V17 12
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_withdraw_for_V17_t;

#define PD_CALL_CROWDLOANS_REDEEM_V17 13
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
    pd_CompactBalance_t amount;
} pd_crowdloans_redeem_V17_t;

#define PD_CALL_CROWDLOANS_SLOT_EXPIRED_V17 14
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_slot_expired_V17_t;

#define PD_CALL_CROWDLOANS_MIGRATE_PENDING_V17 15
typedef struct {
    pd_ParaId_V17_t crowdloan;
} pd_crowdloans_migrate_pending_V17_t;

#define PD_CALL_CROWDLOANS_REFUND_V17 17
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_refund_V17_t;

#define PD_CALL_CROWDLOANS_DISSOLVE_VAULT_V17 18
typedef struct {
    pd_ParaId_V17_t crowdloan;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_dissolve_vault_V17_t;

#define PD_CALL_CROWDLOANS_REFUND_FOR_V17 19
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_ParaId_V17_t crowdloan;
    pd_ChildStorageKind_V17_t kind;
    pd_CompactBalance_t amount;
    pd_LeasePeriod_V17_t lease_start;
    pd_LeasePeriod_V17_t lease_end;
} pd_crowdloans_refund_for_V17_t;

#define PD_CALL_LIQUIDSTAKING_STAKE_V17 0
typedef struct {
    pd_Compactu128_t amount;
} pd_liquidstaking_stake_V17_t;

#define PD_CALL_LIQUIDSTAKING_UNSTAKE_V17 1
typedef struct {
    pd_Compactu128_t liquid_amount;
    pd_UnstakeProvider_V17_t unstake_provider;
} pd_liquidstaking_unstake_V17_t;

#define PD_CALL_LIQUIDSTAKING_UPDATE_RESERVE_FACTOR_V17 2
typedef struct {
    pd_Ratio_V17_t reserve_factor;
} pd_liquidstaking_update_reserve_factor_V17_t;

#define PD_CALL_LIQUIDSTAKING_UPDATE_STAKING_LEDGER_CAP_V17 3
typedef struct {
    pd_Compactu128_t cap;
} pd_liquidstaking_update_staking_ledger_cap_V17_t;

#define PD_CALL_LIQUIDSTAKING_BOND_V17 4
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_Compactu128_t amount;
    pd_RewardDestination_V17_t payee;
} pd_liquidstaking_bond_V17_t;

#define PD_CALL_LIQUIDSTAKING_BOND_EXTRA_V17 5
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_Compactu128_t amount;
} pd_liquidstaking_bond_extra_V17_t;

#define PD_CALL_LIQUIDSTAKING_UNBOND_V17 6
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_Compactu128_t amount;
} pd_liquidstaking_unbond_V17_t;

#define PD_CALL_LIQUIDSTAKING_REBOND_V17 7
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_Compactu128_t amount;
} pd_liquidstaking_rebond_V17_t;

#define PD_CALL_LIQUIDSTAKING_WITHDRAW_UNBONDED_V17 8
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_u32_t num_slashing_spans;
} pd_liquidstaking_withdraw_unbonded_V17_t;

#define PD_CALL_LIQUIDSTAKING_NOMINATE_V17 9
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_VecAccountId_V17_t targets;
} pd_liquidstaking_nominate_V17_t;

#define PD_CALL_LIQUIDSTAKING_CLAIM_FOR_V17 11
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
} pd_liquidstaking_claim_for_V17_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_ERA_START_BLOCK_V17 12
typedef struct {
    pd_BlockNumber_t block_number;
} pd_liquidstaking_force_set_era_start_block_V17_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_CURRENT_ERA_V17 13
typedef struct {
    pd_EraIndex_V17_t era;
} pd_liquidstaking_force_set_current_era_V17_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_ADVANCE_ERA_V17 14
typedef struct {
    pd_EraIndex_V17_t offset;
} pd_liquidstaking_force_advance_era_V17_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_MATCHING_V17 15
typedef struct {
} pd_liquidstaking_force_matching_V17_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_STAKING_LEDGER_V17 16
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_StakingLedgerAccountIdBalanceOfT_V17_t staking_ledger;
} pd_liquidstaking_force_set_staking_ledger_V17_t;

#define PD_CALL_LIQUIDSTAKING_SET_CURRENT_ERA_V17 17
typedef struct {
    pd_EraIndex_V17_t era;
    pd_VecVecu8_t proof;
} pd_liquidstaking_set_current_era_V17_t;

#define PD_CALL_LIQUIDSTAKING_SET_STAKING_LEDGER_V17 18
typedef struct {
    pd_DerivativeIndex_V17_t derivative_index;
    pd_StakingLedgerAccountIdBalanceOfT_V17_t staking_ledger;
    pd_VecVecu8_t proof;
} pd_liquidstaking_set_staking_ledger_V17_t;

#define PD_CALL_LIQUIDSTAKING_REDUCE_RESERVES_V17 19
typedef struct {
    pd_LookupasStaticLookupSource_V17_t receiver;
    pd_Compactu128_t reduce_amount;
} pd_liquidstaking_reduce_reserves_V17_t;

#define PD_CALL_LIQUIDSTAKING_CANCEL_UNSTAKE_V17 20
typedef struct {
    pd_Compactu128_t amount;
} pd_liquidstaking_cancel_unstake_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_ADD_MEMBER_V17 0
typedef struct {
    pd_AccountId_V17_t who;
} pd_generalcouncilmembership_add_member_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_REMOVE_MEMBER_V17 1
typedef struct {
    pd_AccountId_V17_t who;
} pd_generalcouncilmembership_remove_member_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_SWAP_MEMBER_V17 2
typedef struct {
    pd_AccountId_V17_t remove;
    pd_AccountId_V17_t add;
} pd_generalcouncilmembership_swap_member_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_RESET_MEMBERS_V17 3
typedef struct {
    pd_VecAccountId_V17_t members;
} pd_generalcouncilmembership_reset_members_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_CHANGE_KEY_V17 4
typedef struct {
    pd_AccountId_V17_t new_;
} pd_generalcouncilmembership_change_key_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_SET_PRIME_V17 5
typedef struct {
    pd_AccountId_V17_t who;
} pd_generalcouncilmembership_set_prime_V17_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_CLEAR_PRIME_V17 6
typedef struct {
} pd_generalcouncilmembership_clear_prime_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V17 0
typedef struct {
    pd_AccountId_V17_t who;
} pd_technicalcommitteemembership_add_member_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V17 1
typedef struct {
    pd_AccountId_V17_t who;
} pd_technicalcommitteemembership_remove_member_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V17 2
typedef struct {
    pd_AccountId_V17_t remove;
    pd_AccountId_V17_t add;
} pd_technicalcommitteemembership_swap_member_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V17 3
typedef struct {
    pd_VecAccountId_V17_t members;
} pd_technicalcommitteemembership_reset_members_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_CHANGE_KEY_V17 4
typedef struct {
    pd_AccountId_V17_t new_;
} pd_technicalcommitteemembership_change_key_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_PRIME_V17 5
typedef struct {
    pd_AccountId_V17_t who;
} pd_technicalcommitteemembership_set_prime_V17_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_CLEAR_PRIME_V17 6
typedef struct {
} pd_technicalcommitteemembership_clear_prime_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_ADD_MEMBER_V17 0
typedef struct {
    pd_AccountId_V17_t who;
} pd_oraclemembership_add_member_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_REMOVE_MEMBER_V17 1
typedef struct {
    pd_AccountId_V17_t who;
} pd_oraclemembership_remove_member_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_SWAP_MEMBER_V17 2
typedef struct {
    pd_AccountId_V17_t remove;
    pd_AccountId_V17_t add;
} pd_oraclemembership_swap_member_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_RESET_MEMBERS_V17 3
typedef struct {
    pd_VecAccountId_V17_t members;
} pd_oraclemembership_reset_members_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_CHANGE_KEY_V17 4
typedef struct {
    pd_AccountId_V17_t new_;
} pd_oraclemembership_change_key_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_SET_PRIME_V17 5
typedef struct {
    pd_AccountId_V17_t who;
} pd_oraclemembership_set_prime_V17_t;

#define PD_CALL_ORACLEMEMBERSHIP_CLEAR_PRIME_V17 6
typedef struct {
} pd_oraclemembership_clear_prime_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_ADD_MEMBER_V17 0
typedef struct {
    pd_AccountId_V17_t who;
} pd_liquidstakingagentsmembership_add_member_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_REMOVE_MEMBER_V17 1
typedef struct {
    pd_AccountId_V17_t who;
} pd_liquidstakingagentsmembership_remove_member_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_SWAP_MEMBER_V17 2
typedef struct {
    pd_AccountId_V17_t remove;
    pd_AccountId_V17_t add;
} pd_liquidstakingagentsmembership_swap_member_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_RESET_MEMBERS_V17 3
typedef struct {
    pd_VecAccountId_V17_t members;
} pd_liquidstakingagentsmembership_reset_members_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_CHANGE_KEY_V17 4
typedef struct {
    pd_AccountId_V17_t new_;
} pd_liquidstakingagentsmembership_change_key_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_SET_PRIME_V17 5
typedef struct {
    pd_AccountId_V17_t who;
} pd_liquidstakingagentsmembership_set_prime_V17_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_CLEAR_PRIME_V17 6
typedef struct {
} pd_liquidstakingagentsmembership_clear_prime_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_ADD_MEMBER_V17 0
typedef struct {
    pd_AccountId_V17_t who;
} pd_bridgemembership_add_member_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_REMOVE_MEMBER_V17 1
typedef struct {
    pd_AccountId_V17_t who;
} pd_bridgemembership_remove_member_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_SWAP_MEMBER_V17 2
typedef struct {
    pd_AccountId_V17_t remove;
    pd_AccountId_V17_t add;
} pd_bridgemembership_swap_member_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_RESET_MEMBERS_V17 3
typedef struct {
    pd_VecAccountId_V17_t members;
} pd_bridgemembership_reset_members_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_CHANGE_KEY_V17 4
typedef struct {
    pd_AccountId_V17_t new_;
} pd_bridgemembership_change_key_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_SET_PRIME_V17 5
typedef struct {
    pd_AccountId_V17_t who;
} pd_bridgemembership_set_prime_V17_t;

#define PD_CALL_BRIDGEMEMBERSHIP_CLEAR_PRIME_V17 6
typedef struct {
} pd_bridgemembership_clear_prime_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_ADD_MEMBER_V17 0
typedef struct {
    pd_AccountId_V17_t who;
} pd_crowdloansautomatorsmembership_add_member_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_REMOVE_MEMBER_V17 1
typedef struct {
    pd_AccountId_V17_t who;
} pd_crowdloansautomatorsmembership_remove_member_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_SWAP_MEMBER_V17 2
typedef struct {
    pd_AccountId_V17_t remove;
    pd_AccountId_V17_t add;
} pd_crowdloansautomatorsmembership_swap_member_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_RESET_MEMBERS_V17 3
typedef struct {
    pd_VecAccountId_V17_t members;
} pd_crowdloansautomatorsmembership_reset_members_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_CHANGE_KEY_V17 4
typedef struct {
    pd_AccountId_V17_t new_;
} pd_crowdloansautomatorsmembership_change_key_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_SET_PRIME_V17 5
typedef struct {
    pd_AccountId_V17_t who;
} pd_crowdloansautomatorsmembership_set_prime_V17_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_CLEAR_PRIME_V17 6
typedef struct {
} pd_crowdloansautomatorsmembership_clear_prime_V17_t;

#define PD_CALL_AMM_ADD_LIQUIDITY_V17 0
typedef struct {
    pd_AssetIdOfAssetIdOf_V17_t pair;
    pd_BalanceOfBalanceOf_V17_t desired_amounts;
    pd_BalanceOfBalanceOf_V17_t minimum_amounts;
} pd_amm_add_liquidity_V17_t;

#define PD_CALL_AMM_REMOVE_LIQUIDITY_V17 1
typedef struct {
    pd_AssetIdOfAssetIdOf_V17_t pair;
    pd_Compactu128_t liquidity;
} pd_amm_remove_liquidity_V17_t;

#define PD_CALL_AMM_CREATE_POOL_V17 2
typedef struct {
    pd_AssetIdOfAssetIdOf_V17_t pair;
    pd_BalanceOfBalanceOf_V17_t liquidity_amounts;
    pd_AccountId_V17_t lptoken_receiver;
    pd_AssetIdOf_V17_t lp_token_id;
} pd_amm_create_pool_V17_t;

#define PD_CALL_AMMROUTE_SWAP_EXACT_TOKENS_FOR_TOKENS_V17 0
typedef struct {
    pd_VecAssetIdOf_V17_t route;
    pd_Compactu128_t amount_in;
    pd_Compactu128_t min_amount_out;
} pd_ammroute_swap_exact_tokens_for_tokens_V17_t;

#define PD_CALL_AMMROUTE_SWAP_TOKENS_FOR_EXACT_TOKENS_V17 1
typedef struct {
    pd_VecAssetIdOf_V17_t route;
    pd_Compactu128_t amount_out;
    pd_Compactu128_t max_amount_in;
} pd_ammroute_swap_tokens_for_exact_tokens_V17_t;

#define PD_CALL_CURRENCYADAPTER_FORCE_SET_LOCK_V17 0
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AccountId_V17_t who;
    pd_Compactu128_t amount;
} pd_currencyadapter_force_set_lock_V17_t;

#define PD_CALL_CURRENCYADAPTER_FORCE_REMOVE_LOCK_V17 1
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AccountId_V17_t who;
} pd_currencyadapter_force_remove_lock_V17_t;

#define PD_CALL_BRIDGE_REGISTER_CHAIN_V17 0
typedef struct {
    pd_ChainId_V17_t chain_id;
} pd_bridge_register_chain_V17_t;

#define PD_CALL_BRIDGE_UNREGISTER_CHAIN_V17 1
typedef struct {
    pd_ChainId_V17_t chain_id;
} pd_bridge_unregister_chain_V17_t;

#define PD_CALL_BRIDGE_REGISTER_BRIDGE_TOKEN_V17 2
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_BridgeToken_V17_t bridge_token;
} pd_bridge_register_bridge_token_V17_t;

#define PD_CALL_BRIDGE_UNREGISTER_BRIDGE_TOKEN_V17 3
typedef struct {
    pd_CurrencyId_V17_t bridge_token_id;
} pd_bridge_unregister_bridge_token_V17_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_FEE_V17 4
typedef struct {
    pd_CurrencyId_V17_t bridge_token_id;
    pd_Balance_t new_fee;
} pd_bridge_set_bridge_token_fee_V17_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_STATUS_V17 5
typedef struct {
    pd_CurrencyId_V17_t bridge_token_id;
    pd_bool_t enable;
} pd_bridge_set_bridge_token_status_V17_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_CAP_V17 6
typedef struct {
    pd_CurrencyId_V17_t bridge_token_id;
    pd_BridgeType_V17_t bridge_type;
    pd_Balance_t new_cap;
} pd_bridge_set_bridge_token_cap_V17_t;

#define PD_CALL_BRIDGE_CLEAN_CAP_ACCUMULATED_VALUE_V17 7
typedef struct {
    pd_CurrencyId_V17_t bridge_token_id;
    pd_BridgeType_V17_t bridge_type;
} pd_bridge_clean_cap_accumulated_value_V17_t;

#define PD_CALL_BRIDGE_TELEPORT_V17 8
typedef struct {
    pd_ChainId_V17_t dest_id;
    pd_CurrencyId_V17_t bridge_token_id;
    pd_TeleAccount_V17_t to;
    pd_Balance_t amount;
} pd_bridge_teleport_V17_t;

#define PD_CALL_BRIDGE_MATERIALIZE_V17 9
typedef struct {
    pd_ChainId_V17_t src_id;
    pd_ChainNonce_V17_t src_nonce;
    pd_CurrencyId_V17_t bridge_token_id;
    pd_AccountId_V17_t to;
    pd_Balance_t amount;
    pd_bool_t favour;
} pd_bridge_materialize_V17_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_PALLET_V17 0
typedef struct {
    pd_u8_t pallet_idx;
} pd_emergencyshutdown_toggle_pallet_V17_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_CALL_V17 1
typedef struct {
    pd_u8_t pallet_idx;
    pd_u8_t call_idx;
} pd_emergencyshutdown_toggle_call_V17_t;

#define PD_CALL_FARMING_CREATE_V17 0
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_BlockNumber_t cool_down_duration;
} pd_farming_create_V17_t;

#define PD_CALL_FARMING_SET_POOL_STATUS_V17 1
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_bool_t is_active;
} pd_farming_set_pool_status_V17_t;

#define PD_CALL_FARMING_SET_POOL_COOL_DOWN_DURATION_V17 2
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_BlockNumber_t cool_down_duration;
} pd_farming_set_pool_cool_down_duration_V17_t;

#define PD_CALL_FARMING_RESET_POOL_UNLOCK_HEIGHT_V17 3
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_reset_pool_unlock_height_V17_t;

#define PD_CALL_FARMING_DEPOSIT_V17 4
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_Balance_t amount;
} pd_farming_deposit_V17_t;

#define PD_CALL_FARMING_WITHDRAW_V17 5
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_Balance_t amount;
} pd_farming_withdraw_V17_t;

#define PD_CALL_FARMING_REDEEM_V17 6
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_redeem_V17_t;

#define PD_CALL_FARMING_CLAIM_V17 7
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_claim_V17_t;

#define PD_CALL_FARMING_DISPATCH_REWARD_V17 8
typedef struct {
    pd_AssetIdOfT_V17_t asset;
    pd_AssetIdOfT_V17_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_LookupasStaticLookupSource_V17_t payer;
    pd_Balance_t amount;
    pd_BlockNumber_t reward_duration;
} pd_farming_dispatch_reward_V17_t;

#define PD_CALL_STREAMING_SET_MINIMUM_DEPOSIT_V17 3
typedef struct {
    pd_AssetIdOfT_V17_t asset_id;
    pd_Balance_t minimum_deposit;
} pd_streaming_set_minimum_deposit_V17_t;

#define PD_CALL_PARACHAINSYSTEM_AUTHORIZE_UPGRADE_V17 2
typedef struct {
    pd_Hash_t code_hash;
} pd_parachainsystem_authorize_upgrade_V17_t;

#define PD_CALL_PARACHAINSYSTEM_ENACT_AUTHORIZED_UPGRADE_V17 3
typedef struct {
    pd_Vecu8_t code;
} pd_parachainsystem_enact_authorized_upgrade_V17_t;

#endif

typedef union {
    pd_utility_batch_V17_t utility_batch_V17;
    pd_utility_batch_all_V17_t utility_batch_all_V17;
    pd_utility_force_batch_V17_t utility_force_batch_V17;
    pd_balances_transfer_all_V17_t balances_transfer_all_V17;
    pd_session_set_keys_V17_t session_set_keys_V17;
    pd_session_purge_keys_V17_t session_purge_keys_V17;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V17_t timestamp_set_V17;
    pd_balances_force_unreserve_V17_t balances_force_unreserve_V17;
    pd_assets_create_V17_t assets_create_V17;
    pd_assets_force_create_V17_t assets_force_create_V17;
    pd_assets_destroy_V17_t assets_destroy_V17;
    pd_assets_mint_V17_t assets_mint_V17;
    pd_assets_burn_V17_t assets_burn_V17;
    pd_assets_transfer_V17_t assets_transfer_V17;
    pd_assets_transfer_keep_alive_V17_t assets_transfer_keep_alive_V17;
    pd_assets_force_transfer_V17_t assets_force_transfer_V17;
    pd_assets_freeze_V17_t assets_freeze_V17;
    pd_assets_thaw_V17_t assets_thaw_V17;
    pd_assets_freeze_asset_V17_t assets_freeze_asset_V17;
    pd_assets_thaw_asset_V17_t assets_thaw_asset_V17;
    pd_assets_transfer_ownership_V17_t assets_transfer_ownership_V17;
    pd_assets_set_team_V17_t assets_set_team_V17;
    pd_assets_set_metadata_V17_t assets_set_metadata_V17;
    pd_assets_clear_metadata_V17_t assets_clear_metadata_V17;
    pd_assets_force_set_metadata_V17_t assets_force_set_metadata_V17;
    pd_assets_force_clear_metadata_V17_t assets_force_clear_metadata_V17;
    pd_assets_force_asset_status_V17_t assets_force_asset_status_V17;
    pd_assets_approve_transfer_V17_t assets_approve_transfer_V17;
    pd_assets_cancel_approval_V17_t assets_cancel_approval_V17;
    pd_assets_force_cancel_approval_V17_t assets_force_cancel_approval_V17;
    pd_assets_transfer_approved_V17_t assets_transfer_approved_V17;
    pd_assets_touch_V17_t assets_touch_V17;
    pd_assets_refund_V17_t assets_refund_V17;
    pd_proxy_add_proxy_V17_t proxy_add_proxy_V17;
    pd_proxy_remove_proxy_V17_t proxy_remove_proxy_V17;
    pd_proxy_remove_proxies_V17_t proxy_remove_proxies_V17;
    pd_proxy_anonymous_V17_t proxy_anonymous_V17;
    pd_proxy_kill_anonymous_V17_t proxy_kill_anonymous_V17;
    pd_proxy_announce_V17_t proxy_announce_V17;
    pd_proxy_remove_announcement_V17_t proxy_remove_announcement_V17;
    pd_proxy_reject_announcement_V17_t proxy_reject_announcement_V17;
    pd_proxy_proxy_announced_V17_t proxy_proxy_announced_V17;
    pd_identity_add_registrar_V17_t identity_add_registrar_V17;
    pd_identity_clear_identity_V17_t identity_clear_identity_V17;
    pd_identity_request_judgement_V17_t identity_request_judgement_V17;
    pd_identity_cancel_request_V17_t identity_cancel_request_V17;
    pd_identity_set_fee_V17_t identity_set_fee_V17;
    pd_identity_set_account_id_V17_t identity_set_account_id_V17;
    pd_identity_kill_identity_V17_t identity_kill_identity_V17;
    pd_identity_remove_sub_V17_t identity_remove_sub_V17;
    pd_identity_quit_sub_V17_t identity_quit_sub_V17;
    pd_democracy_propose_V17_t democracy_propose_V17;
    pd_democracy_second_V17_t democracy_second_V17;
    pd_democracy_emergency_cancel_V17_t democracy_emergency_cancel_V17;
    pd_democracy_external_propose_V17_t democracy_external_propose_V17;
    pd_democracy_external_propose_majority_V17_t democracy_external_propose_majority_V17;
    pd_democracy_external_propose_default_V17_t democracy_external_propose_default_V17;
    pd_democracy_fast_track_V17_t democracy_fast_track_V17;
    pd_democracy_veto_external_V17_t democracy_veto_external_V17;
    pd_democracy_cancel_referendum_V17_t democracy_cancel_referendum_V17;
    pd_democracy_cancel_queued_V17_t democracy_cancel_queued_V17;
    pd_democracy_delegate_V17_t democracy_delegate_V17;
    pd_democracy_undelegate_V17_t democracy_undelegate_V17;
    pd_democracy_clear_public_proposals_V17_t democracy_clear_public_proposals_V17;
    pd_democracy_note_preimage_V17_t democracy_note_preimage_V17;
    pd_democracy_note_preimage_operational_V17_t democracy_note_preimage_operational_V17;
    pd_democracy_note_imminent_preimage_V17_t democracy_note_imminent_preimage_V17;
    pd_democracy_note_imminent_preimage_operational_V17_t democracy_note_imminent_preimage_operational_V17;
    pd_democracy_reap_preimage_V17_t democracy_reap_preimage_V17;
    pd_democracy_unlock_V17_t democracy_unlock_V17;
    pd_democracy_remove_vote_V17_t democracy_remove_vote_V17;
    pd_democracy_remove_other_vote_V17_t democracy_remove_other_vote_V17;
    pd_democracy_enact_proposal_V17_t democracy_enact_proposal_V17;
    pd_democracy_cancel_proposal_V17_t democracy_cancel_proposal_V17;
    pd_generalcouncil_set_members_V17_t generalcouncil_set_members_V17;
    pd_generalcouncil_execute_V17_t generalcouncil_execute_V17;
    pd_generalcouncil_propose_V17_t generalcouncil_propose_V17;
    pd_generalcouncil_vote_V17_t generalcouncil_vote_V17;
    pd_generalcouncil_close_V17_t generalcouncil_close_V17;
    pd_generalcouncil_disapprove_proposal_V17_t generalcouncil_disapprove_proposal_V17;
    pd_technicalcommittee_set_members_V17_t technicalcommittee_set_members_V17;
    pd_technicalcommittee_execute_V17_t technicalcommittee_execute_V17;
    pd_technicalcommittee_propose_V17_t technicalcommittee_propose_V17;
    pd_technicalcommittee_vote_V17_t technicalcommittee_vote_V17;
    pd_technicalcommittee_close_V17_t technicalcommittee_close_V17;
    pd_technicalcommittee_disapprove_proposal_V17_t technicalcommittee_disapprove_proposal_V17;
    pd_treasury_propose_spend_V17_t treasury_propose_spend_V17;
    pd_treasury_reject_proposal_V17_t treasury_reject_proposal_V17;
    pd_treasury_approve_proposal_V17_t treasury_approve_proposal_V17;
    pd_treasury_remove_approval_V17_t treasury_remove_approval_V17;
    pd_preimage_note_preimage_V17_t preimage_note_preimage_V17;
    pd_preimage_unnote_preimage_V17_t preimage_unnote_preimage_V17;
    pd_preimage_request_preimage_V17_t preimage_request_preimage_V17;
    pd_preimage_unrequest_preimage_V17_t preimage_unrequest_preimage_V17;
    pd_xcmpqueue_service_overweight_V17_t xcmpqueue_service_overweight_V17;
    pd_xcmpqueue_suspend_xcm_execution_V17_t xcmpqueue_suspend_xcm_execution_V17;
    pd_xcmpqueue_resume_xcm_execution_V17_t xcmpqueue_resume_xcm_execution_V17;
    pd_xcmpqueue_update_suspend_threshold_V17_t xcmpqueue_update_suspend_threshold_V17;
    pd_xcmpqueue_update_drop_threshold_V17_t xcmpqueue_update_drop_threshold_V17;
    pd_xcmpqueue_update_resume_threshold_V17_t xcmpqueue_update_resume_threshold_V17;
    pd_xcmpqueue_update_threshold_weight_V17_t xcmpqueue_update_threshold_weight_V17;
    pd_xcmpqueue_update_weight_restrict_decay_V17_t xcmpqueue_update_weight_restrict_decay_V17;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V17_t xcmpqueue_update_xcmp_max_individual_weight_V17;
    pd_dmpqueue_service_overweight_V17_t dmpqueue_service_overweight_V17;
    pd_collatorselection_set_invulnerables_V17_t collatorselection_set_invulnerables_V17;
    pd_collatorselection_set_desired_candidates_V17_t collatorselection_set_desired_candidates_V17;
    pd_collatorselection_set_candidacy_bond_V17_t collatorselection_set_candidacy_bond_V17;
    pd_collatorselection_register_as_candidate_V17_t collatorselection_register_as_candidate_V17;
    pd_collatorselection_leave_intent_V17_t collatorselection_leave_intent_V17;
    pd_xtokens_transfer_V17_t xtokens_transfer_V17;
    pd_vesting_claim_V17_t vesting_claim_V17;
    pd_vesting_vested_transfer_V17_t vesting_vested_transfer_V17;
    pd_vesting_update_vesting_schedules_V17_t vesting_update_vesting_schedules_V17;
    pd_vesting_claim_for_V17_t vesting_claim_for_V17;
    pd_loans_add_market_V17_t loans_add_market_V17;
    pd_loans_activate_market_V17_t loans_activate_market_V17;
    pd_loans_update_rate_model_V17_t loans_update_rate_model_V17;
    pd_loans_update_market_V17_t loans_update_market_V17;
    pd_loans_force_update_market_V17_t loans_force_update_market_V17;
    pd_loans_add_reward_V17_t loans_add_reward_V17;
    pd_loans_withdraw_missing_reward_V17_t loans_withdraw_missing_reward_V17;
    pd_loans_update_market_reward_speed_V17_t loans_update_market_reward_speed_V17;
    pd_loans_claim_reward_V17_t loans_claim_reward_V17;
    pd_loans_claim_reward_for_market_V17_t loans_claim_reward_for_market_V17;
    pd_loans_mint_V17_t loans_mint_V17;
    pd_loans_redeem_V17_t loans_redeem_V17;
    pd_loans_redeem_all_V17_t loans_redeem_all_V17;
    pd_loans_borrow_V17_t loans_borrow_V17;
    pd_loans_repay_borrow_V17_t loans_repay_borrow_V17;
    pd_loans_repay_borrow_all_V17_t loans_repay_borrow_all_V17;
    pd_loans_collateral_asset_V17_t loans_collateral_asset_V17;
    pd_loans_liquidate_borrow_V17_t loans_liquidate_borrow_V17;
    pd_loans_add_reserves_V17_t loans_add_reserves_V17;
    pd_loans_reduce_reserves_V17_t loans_reduce_reserves_V17;
    pd_loans_reduce_incentive_reserves_V17_t loans_reduce_incentive_reserves_V17;
    pd_loans_update_liquidation_free_collateral_V17_t loans_update_liquidation_free_collateral_V17;
    pd_prices_set_price_V17_t prices_set_price_V17;
    pd_prices_reset_price_V17_t prices_reset_price_V17;
    pd_crowdloans_create_vault_V17_t crowdloans_create_vault_V17;
    pd_crowdloans_update_vault_V17_t crowdloans_update_vault_V17;
    pd_crowdloans_open_V17_t crowdloans_open_V17;
    pd_crowdloans_contribute_V17_t crowdloans_contribute_V17;
    pd_crowdloans_set_vrf_V17_t crowdloans_set_vrf_V17;
    pd_crowdloans_close_V17_t crowdloans_close_V17;
    pd_crowdloans_reopen_V17_t crowdloans_reopen_V17;
    pd_crowdloans_auction_succeeded_V17_t crowdloans_auction_succeeded_V17;
    pd_crowdloans_auction_failed_V17_t crowdloans_auction_failed_V17;
    pd_crowdloans_claim_V17_t crowdloans_claim_V17;
    pd_crowdloans_claim_for_V17_t crowdloans_claim_for_V17;
    pd_crowdloans_withdraw_V17_t crowdloans_withdraw_V17;
    pd_crowdloans_withdraw_for_V17_t crowdloans_withdraw_for_V17;
    pd_crowdloans_redeem_V17_t crowdloans_redeem_V17;
    pd_crowdloans_slot_expired_V17_t crowdloans_slot_expired_V17;
    pd_crowdloans_migrate_pending_V17_t crowdloans_migrate_pending_V17;
    pd_crowdloans_refund_V17_t crowdloans_refund_V17;
    pd_crowdloans_dissolve_vault_V17_t crowdloans_dissolve_vault_V17;
    pd_crowdloans_refund_for_V17_t crowdloans_refund_for_V17;
    pd_liquidstaking_stake_V17_t liquidstaking_stake_V17;
    pd_liquidstaking_unstake_V17_t liquidstaking_unstake_V17;
    pd_liquidstaking_update_reserve_factor_V17_t liquidstaking_update_reserve_factor_V17;
    pd_liquidstaking_update_staking_ledger_cap_V17_t liquidstaking_update_staking_ledger_cap_V17;
    pd_liquidstaking_bond_V17_t liquidstaking_bond_V17;
    pd_liquidstaking_bond_extra_V17_t liquidstaking_bond_extra_V17;
    pd_liquidstaking_unbond_V17_t liquidstaking_unbond_V17;
    pd_liquidstaking_rebond_V17_t liquidstaking_rebond_V17;
    pd_liquidstaking_withdraw_unbonded_V17_t liquidstaking_withdraw_unbonded_V17;
    pd_liquidstaking_nominate_V17_t liquidstaking_nominate_V17;
    pd_liquidstaking_claim_for_V17_t liquidstaking_claim_for_V17;
    pd_liquidstaking_force_set_era_start_block_V17_t liquidstaking_force_set_era_start_block_V17;
    pd_liquidstaking_force_set_current_era_V17_t liquidstaking_force_set_current_era_V17;
    pd_liquidstaking_force_advance_era_V17_t liquidstaking_force_advance_era_V17;
    pd_liquidstaking_force_matching_V17_t liquidstaking_force_matching_V17;
    pd_liquidstaking_force_set_staking_ledger_V17_t liquidstaking_force_set_staking_ledger_V17;
    pd_liquidstaking_set_current_era_V17_t liquidstaking_set_current_era_V17;
    pd_liquidstaking_set_staking_ledger_V17_t liquidstaking_set_staking_ledger_V17;
    pd_liquidstaking_reduce_reserves_V17_t liquidstaking_reduce_reserves_V17;
    pd_liquidstaking_cancel_unstake_V17_t liquidstaking_cancel_unstake_V17;
    pd_generalcouncilmembership_add_member_V17_t generalcouncilmembership_add_member_V17;
    pd_generalcouncilmembership_remove_member_V17_t generalcouncilmembership_remove_member_V17;
    pd_generalcouncilmembership_swap_member_V17_t generalcouncilmembership_swap_member_V17;
    pd_generalcouncilmembership_reset_members_V17_t generalcouncilmembership_reset_members_V17;
    pd_generalcouncilmembership_change_key_V17_t generalcouncilmembership_change_key_V17;
    pd_generalcouncilmembership_set_prime_V17_t generalcouncilmembership_set_prime_V17;
    pd_generalcouncilmembership_clear_prime_V17_t generalcouncilmembership_clear_prime_V17;
    pd_technicalcommitteemembership_add_member_V17_t technicalcommitteemembership_add_member_V17;
    pd_technicalcommitteemembership_remove_member_V17_t technicalcommitteemembership_remove_member_V17;
    pd_technicalcommitteemembership_swap_member_V17_t technicalcommitteemembership_swap_member_V17;
    pd_technicalcommitteemembership_reset_members_V17_t technicalcommitteemembership_reset_members_V17;
    pd_technicalcommitteemembership_change_key_V17_t technicalcommitteemembership_change_key_V17;
    pd_technicalcommitteemembership_set_prime_V17_t technicalcommitteemembership_set_prime_V17;
    pd_technicalcommitteemembership_clear_prime_V17_t technicalcommitteemembership_clear_prime_V17;
    pd_oraclemembership_add_member_V17_t oraclemembership_add_member_V17;
    pd_oraclemembership_remove_member_V17_t oraclemembership_remove_member_V17;
    pd_oraclemembership_swap_member_V17_t oraclemembership_swap_member_V17;
    pd_oraclemembership_reset_members_V17_t oraclemembership_reset_members_V17;
    pd_oraclemembership_change_key_V17_t oraclemembership_change_key_V17;
    pd_oraclemembership_set_prime_V17_t oraclemembership_set_prime_V17;
    pd_oraclemembership_clear_prime_V17_t oraclemembership_clear_prime_V17;
    pd_liquidstakingagentsmembership_add_member_V17_t liquidstakingagentsmembership_add_member_V17;
    pd_liquidstakingagentsmembership_remove_member_V17_t liquidstakingagentsmembership_remove_member_V17;
    pd_liquidstakingagentsmembership_swap_member_V17_t liquidstakingagentsmembership_swap_member_V17;
    pd_liquidstakingagentsmembership_reset_members_V17_t liquidstakingagentsmembership_reset_members_V17;
    pd_liquidstakingagentsmembership_change_key_V17_t liquidstakingagentsmembership_change_key_V17;
    pd_liquidstakingagentsmembership_set_prime_V17_t liquidstakingagentsmembership_set_prime_V17;
    pd_liquidstakingagentsmembership_clear_prime_V17_t liquidstakingagentsmembership_clear_prime_V17;
    pd_bridgemembership_add_member_V17_t bridgemembership_add_member_V17;
    pd_bridgemembership_remove_member_V17_t bridgemembership_remove_member_V17;
    pd_bridgemembership_swap_member_V17_t bridgemembership_swap_member_V17;
    pd_bridgemembership_reset_members_V17_t bridgemembership_reset_members_V17;
    pd_bridgemembership_change_key_V17_t bridgemembership_change_key_V17;
    pd_bridgemembership_set_prime_V17_t bridgemembership_set_prime_V17;
    pd_bridgemembership_clear_prime_V17_t bridgemembership_clear_prime_V17;
    pd_crowdloansautomatorsmembership_add_member_V17_t crowdloansautomatorsmembership_add_member_V17;
    pd_crowdloansautomatorsmembership_remove_member_V17_t crowdloansautomatorsmembership_remove_member_V17;
    pd_crowdloansautomatorsmembership_swap_member_V17_t crowdloansautomatorsmembership_swap_member_V17;
    pd_crowdloansautomatorsmembership_reset_members_V17_t crowdloansautomatorsmembership_reset_members_V17;
    pd_crowdloansautomatorsmembership_change_key_V17_t crowdloansautomatorsmembership_change_key_V17;
    pd_crowdloansautomatorsmembership_set_prime_V17_t crowdloansautomatorsmembership_set_prime_V17;
    pd_crowdloansautomatorsmembership_clear_prime_V17_t crowdloansautomatorsmembership_clear_prime_V17;
    pd_amm_add_liquidity_V17_t amm_add_liquidity_V17;
    pd_amm_remove_liquidity_V17_t amm_remove_liquidity_V17;
    pd_amm_create_pool_V17_t amm_create_pool_V17;
    pd_ammroute_swap_exact_tokens_for_tokens_V17_t ammroute_swap_exact_tokens_for_tokens_V17;
    pd_ammroute_swap_tokens_for_exact_tokens_V17_t ammroute_swap_tokens_for_exact_tokens_V17;
    pd_currencyadapter_force_set_lock_V17_t currencyadapter_force_set_lock_V17;
    pd_currencyadapter_force_remove_lock_V17_t currencyadapter_force_remove_lock_V17;
    pd_bridge_register_chain_V17_t bridge_register_chain_V17;
    pd_bridge_unregister_chain_V17_t bridge_unregister_chain_V17;
    pd_bridge_register_bridge_token_V17_t bridge_register_bridge_token_V17;
    pd_bridge_unregister_bridge_token_V17_t bridge_unregister_bridge_token_V17;
    pd_bridge_set_bridge_token_fee_V17_t bridge_set_bridge_token_fee_V17;
    pd_bridge_set_bridge_token_status_V17_t bridge_set_bridge_token_status_V17;
    pd_bridge_set_bridge_token_cap_V17_t bridge_set_bridge_token_cap_V17;
    pd_bridge_clean_cap_accumulated_value_V17_t bridge_clean_cap_accumulated_value_V17;
    pd_bridge_teleport_V17_t bridge_teleport_V17;
    pd_bridge_materialize_V17_t bridge_materialize_V17;
    pd_emergencyshutdown_toggle_pallet_V17_t emergencyshutdown_toggle_pallet_V17;
    pd_emergencyshutdown_toggle_call_V17_t emergencyshutdown_toggle_call_V17;
    pd_farming_create_V17_t farming_create_V17;
    pd_farming_set_pool_status_V17_t farming_set_pool_status_V17;
    pd_farming_set_pool_cool_down_duration_V17_t farming_set_pool_cool_down_duration_V17;
    pd_farming_reset_pool_unlock_height_V17_t farming_reset_pool_unlock_height_V17;
    pd_farming_deposit_V17_t farming_deposit_V17;
    pd_farming_withdraw_V17_t farming_withdraw_V17;
    pd_farming_redeem_V17_t farming_redeem_V17;
    pd_farming_claim_V17_t farming_claim_V17;
    pd_farming_dispatch_reward_V17_t farming_dispatch_reward_V17;
    pd_streaming_set_minimum_deposit_V17_t streaming_set_minimum_deposit_V17;
    pd_parachainsystem_authorize_upgrade_V17_t parachainsystem_authorize_upgrade_V17;
    pd_parachainsystem_enact_authorized_upgrade_V17_t parachainsystem_enact_authorized_upgrade_V17;
#endif
} pd_MethodBasic_V17_t;

#define PD_CALL_BALANCES_TRANSFER_V17 0
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V17_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V17 2
typedef struct {
    pd_LookupasStaticLookupSource_V17_t source;
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V17_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V17 3
typedef struct {
    pd_LookupasStaticLookupSource_V17_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V17_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V17 0
typedef struct {
    pd_Perbill_V17_t ratio;
} pd_system_fill_block_V17_t;

#define PD_CALL_SYSTEM_REMARK_V17 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V17_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V17 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V17_t;

#define PD_CALL_SYSTEM_SET_CODE_V17 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V17_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V17 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V17_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V17 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V17_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V17 0
typedef struct {
    pd_VecAccountId_V17_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V17_t;

#define PD_CALL_MULTISIG_AS_MULTI_V17 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V17_t other_signatories;
    pd_OptionTimepoint_V17_t maybe_timepoint;
    pd_OpaqueCall_V17_t call;
    pd_bool_t store_call;
    pd_Weight_V17_t max_weight;
} pd_multisig_as_multi_V17_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V17 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V17_t other_signatories;
    pd_OptionTimepoint_V17_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V17_t max_weight;
} pd_multisig_approve_as_multi_V17_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V17 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V17_t other_signatories;
    pd_Timepoint_V17_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V17_t;

#define PD_CALL_BALANCES_SET_BALANCE_V17 1
typedef struct {
    pd_LookupasStaticLookupSource_V17_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V17_t;

#define PD_CALL_PROXY_PROXY_V17 0
typedef struct {
    pd_AccountId_V17_t real;
    pd_OptionProxyType_V17_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V17_t;

#endif

typedef union {
    pd_balances_transfer_V17_t balances_transfer_V17;
    pd_balances_force_transfer_V17_t balances_force_transfer_V17;
    pd_balances_transfer_keep_alive_V17_t balances_transfer_keep_alive_V17;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V17_t system_fill_block_V17;
    pd_system_remark_V17_t system_remark_V17;
    pd_system_set_heap_pages_V17_t system_set_heap_pages_V17;
    pd_system_set_code_V17_t system_set_code_V17;
    pd_system_set_code_without_checks_V17_t system_set_code_without_checks_V17;
    pd_system_remark_with_event_V17_t system_remark_with_event_V17;
    pd_multisig_as_multi_threshold_1_V17_t multisig_as_multi_threshold_1_V17;
    pd_multisig_as_multi_V17_t multisig_as_multi_V17;
    pd_multisig_approve_as_multi_V17_t multisig_approve_as_multi_V17;
    pd_multisig_cancel_as_multi_V17_t multisig_cancel_as_multi_V17;
    pd_balances_set_balance_V17_t balances_set_balance_V17;
    pd_proxy_proxy_V17_t proxy_proxy_V17;
#endif
} pd_MethodNested_V17_t;

typedef union {
    pd_MethodBasic_V17_t basic;
    pd_MethodNested_V17_t nested;
} pd_Method_V17_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
