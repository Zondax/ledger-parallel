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
#include "substrate_types_V13.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V13 0
#define PD_CALL_TIMESTAMP_V13 1
#define PD_CALL_UTILITY_V13 2
#define PD_CALL_MULTISIG_V13 3
#define PD_CALL_BALANCES_V13 4
#define PD_CALL_ASSETS_V13 6
#define PD_CALL_PROXY_V13 7
#define PD_CALL_IDENTITY_V13 8
#define PD_CALL_SUDO_V13 10
#define PD_CALL_DEMOCRACY_V13 11
#define PD_CALL_GENERALCOUNCIL_V13 12
#define PD_CALL_TECHNICALCOMMITTEE_V13 13
#define PD_CALL_TREASURY_V13 14
#define PD_CALL_PREIMAGE_V13 16
#define PD_CALL_XCMPQUEUE_V13 22
#define PD_CALL_COLLATORSELECTION_V13 31
#define PD_CALL_SESSION_V13 32
#define PD_CALL_VESTING_V13 46
#define PD_CALL_LOANS_V13 50
#define PD_CALL_CROWDLOANS_V13 52
#define PD_CALL_LIQUIDSTAKING_V13 60
#define PD_CALL_GENERALCOUNCILMEMBERSHIP_V13 70
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V13 71
#define PD_CALL_ORACLEMEMBERSHIP_V13 72
#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_V13 73
#define PD_CALL_BRIDGEMEMBERSHIP_V13 74
#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_V13 75
#define PD_CALL_BRIDGE_V13 90
#define PD_CALL_EMERGENCYSHUTDOWN_V13 91
#define PD_CALL_FARMING_V13 92
#define PD_CALL_STREAMING_V13 94
#define PD_CALL_PARACHAINSYSTEM_V13 20

#define PD_CALL_UTILITY_BATCH_V13 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V13_t;

#define PD_CALL_UTILITY_BATCH_ALL_V13 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V13_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V13 4
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V13_t;

#define PD_CALL_SESSION_SET_KEYS_V13 0
typedef struct {
    pd_Keys_V13_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V13_t;

#define PD_CALL_SESSION_PURGE_KEYS_V13 1
typedef struct {
} pd_session_purge_keys_V13_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V13 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V13_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V13 5
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V13_t;

#define PD_CALL_ASSETS_CREATE_V13 0
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t admin;
    pd_Balance_t min_balance;
} pd_assets_create_V13_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V13 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t owner;
    pd_bool_t is_sufficient;
    pd_Compactu128_t min_balance;
} pd_assets_force_create_V13_t;

#define PD_CALL_ASSETS_DESTROY_V13 2
typedef struct {
    pd_Compactu32_t id;
    pd_DestroyWitness_V13_t witness;
} pd_assets_destroy_V13_t;

#define PD_CALL_ASSETS_MINT_V13 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t beneficiary;
    pd_Compactu128_t amount;
} pd_assets_mint_V13_t;

#define PD_CALL_ASSETS_BURN_V13 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t who;
    pd_Compactu128_t amount;
} pd_assets_burn_V13_t;

#define PD_CALL_ASSETS_TRANSFER_V13 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t target;
    pd_Compactu128_t amount;
} pd_assets_transfer_V13_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V13 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t target;
    pd_Compactu128_t amount;
} pd_assets_transfer_keep_alive_V13_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V13 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t source;
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_Compactu128_t amount;
} pd_assets_force_transfer_V13_t;

#define PD_CALL_ASSETS_FREEZE_V13 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t who;
} pd_assets_freeze_V13_t;

#define PD_CALL_ASSETS_THAW_V13 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t who;
} pd_assets_thaw_V13_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V13 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V13_t;

#define PD_CALL_ASSETS_THAW_ASSET_V13 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V13_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V13 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t owner;
} pd_assets_transfer_ownership_V13_t;

#define PD_CALL_ASSETS_SET_TEAM_V13 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t issuer;
    pd_LookupasStaticLookupSource_V13_t admin;
    pd_LookupasStaticLookupSource_V13_t freezer;
} pd_assets_set_team_V13_t;

#define PD_CALL_ASSETS_SET_METADATA_V13 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V13_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V13 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V13_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V13 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V13_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V13 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V13_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V13 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t owner;
    pd_LookupasStaticLookupSource_V13_t issuer;
    pd_LookupasStaticLookupSource_V13_t admin;
    pd_LookupasStaticLookupSource_V13_t freezer;
    pd_Compactu128_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V13_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V13 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t delegate;
    pd_Compactu128_t amount;
} pd_assets_approve_transfer_V13_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V13 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t delegate;
} pd_assets_cancel_approval_V13_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V13 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t owner;
    pd_LookupasStaticLookupSource_V13_t delegate;
} pd_assets_force_cancel_approval_V13_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V13 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V13_t owner;
    pd_LookupasStaticLookupSource_V13_t destination;
    pd_Compactu128_t amount;
} pd_assets_transfer_approved_V13_t;

#define PD_CALL_ASSETS_TOUCH_V13 23
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V13_t;

#define PD_CALL_ASSETS_REFUND_V13 24
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V13_t;

#define PD_CALL_PROXY_ADD_PROXY_V13 1
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_ProxyType_V13_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V13_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V13 2
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_ProxyType_V13_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V13_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V13 3
typedef struct {
} pd_proxy_remove_proxies_V13_t;

#define PD_CALL_PROXY_ANONYMOUS_V13 4
typedef struct {
    pd_ProxyType_V13_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V13_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V13 5
typedef struct {
    pd_AccountId_V13_t spawner;
    pd_ProxyType_V13_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V13_t;

#define PD_CALL_PROXY_ANNOUNCE_V13 6
typedef struct {
    pd_AccountId_V13_t real;
    pd_CallHashOf_V13_t call_hash;
} pd_proxy_announce_V13_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V13 7
typedef struct {
    pd_AccountId_V13_t real;
    pd_CallHashOf_V13_t call_hash;
} pd_proxy_remove_announcement_V13_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V13 8
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_CallHashOf_V13_t call_hash;
} pd_proxy_reject_announcement_V13_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V13 9
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_AccountId_V13_t real;
    pd_OptionProxyType_V13_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V13_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V13 0
typedef struct {
    pd_AccountId_V13_t account;
} pd_identity_add_registrar_V13_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V13 3
typedef struct {
} pd_identity_clear_identity_V13_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V13 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V13_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V13 5
typedef struct {
    pd_RegistrarIndex_V13_t reg_index;
} pd_identity_cancel_request_V13_t;

#define PD_CALL_IDENTITY_SET_FEE_V13 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V13_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V13 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V13_t new_;
} pd_identity_set_account_id_V13_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V13 10
typedef struct {
    pd_LookupasStaticLookupSource_V13_t target;
} pd_identity_kill_identity_V13_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V13 13
typedef struct {
    pd_LookupasStaticLookupSource_V13_t sub;
} pd_identity_remove_sub_V13_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V13 14
typedef struct {
} pd_identity_quit_sub_V13_t;

#define PD_CALL_SUDO_SUDO_V13 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V13_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V13 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V13_t weight;
} pd_sudo_sudo_unchecked_weight_V13_t;

#define PD_CALL_SUDO_SET_KEY_V13 2
typedef struct {
    pd_LookupasStaticLookupSource_V13_t new_;
} pd_sudo_set_key_V13_t;

#define PD_CALL_SUDO_SUDO_AS_V13 3
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V13_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V13 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V13_t;

#define PD_CALL_DEMOCRACY_SECOND_V13 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V13_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V13 3
typedef struct {
    pd_ReferendumIndex_V13_t ref_index;
} pd_democracy_emergency_cancel_V13_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V13 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V13_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V13 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V13_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V13 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V13_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V13 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V13_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V13 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V13_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V13 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V13_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V13 10
typedef struct {
    pd_ReferendumIndex_V13_t which;
} pd_democracy_cancel_queued_V13_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V13 11
typedef struct {
    pd_AccountId_V13_t to;
    pd_Conviction_V13_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V13_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V13 12
typedef struct {
} pd_democracy_undelegate_V13_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V13 13
typedef struct {
} pd_democracy_clear_public_proposals_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V13 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V13 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V13 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V13 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V13_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V13 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V13_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V13 19
typedef struct {
    pd_AccountId_V13_t target;
} pd_democracy_unlock_V13_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V13 20
typedef struct {
    pd_ReferendumIndex_V13_t index;
} pd_democracy_remove_vote_V13_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V13 21
typedef struct {
    pd_AccountId_V13_t target;
    pd_ReferendumIndex_V13_t index;
} pd_democracy_remove_other_vote_V13_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V13 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V13_t index;
} pd_democracy_enact_proposal_V13_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V13 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V13_t;

#define PD_CALL_GENERALCOUNCIL_SET_MEMBERS_V13 0
typedef struct {
    pd_VecAccountId_V13_t new_members;
    pd_OptionAccountId_V13_t prime;
    pd_MemberCount_V13_t old_count;
} pd_generalcouncil_set_members_V13_t;

#define PD_CALL_GENERALCOUNCIL_EXECUTE_V13 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_execute_V13_t;

#define PD_CALL_GENERALCOUNCIL_PROPOSE_V13 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_propose_V13_t;

#define PD_CALL_GENERALCOUNCIL_VOTE_V13 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_generalcouncil_vote_V13_t;

#define PD_CALL_GENERALCOUNCIL_CLOSE_V13 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_generalcouncil_close_V13_t;

#define PD_CALL_GENERALCOUNCIL_DISAPPROVE_PROPOSAL_V13 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_generalcouncil_disapprove_proposal_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V13 0
typedef struct {
    pd_VecAccountId_V13_t new_members;
    pd_OptionAccountId_V13_t prime;
    pd_MemberCount_V13_t old_count;
} pd_technicalcommittee_set_members_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V13 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V13 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V13 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V13 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V13 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V13_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V13 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V13_t beneficiary;
} pd_treasury_propose_spend_V13_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V13 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V13_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V13 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V13_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V13 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V13_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V13 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V13_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V13 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V13_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V13 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V13_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V13 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V13_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V13 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V13 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V13 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V13 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V13 6
typedef struct {
    pd_Weight_V13_t new_;
} pd_xcmpqueue_update_threshold_weight_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V13 7
typedef struct {
    pd_Weight_V13_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V13 8
typedef struct {
    pd_Weight_V13_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V13_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V13 0
typedef struct {
    pd_VecAccountId_V13_t new_;
} pd_collatorselection_set_invulnerables_V13_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V13 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V13_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V13 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V13_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V13 3
typedef struct {
} pd_collatorselection_register_as_candidate_V13_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V13 4
typedef struct {
} pd_collatorselection_leave_intent_V13_t;

#define PD_CALL_VESTING_CLAIM_V13 0
typedef struct {
} pd_vesting_claim_V13_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V13 1
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_VestingScheduleOf_V13_t schedule;
} pd_vesting_vested_transfer_V13_t;

#define PD_CALL_VESTING_UPDATE_VESTING_SCHEDULES_V13 2
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_VecVestingScheduleOf_V13_t vesting_schedules;
} pd_vesting_update_vesting_schedules_V13_t;

#define PD_CALL_VESTING_CLAIM_FOR_V13 3
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
} pd_vesting_claim_for_V13_t;

#define PD_CALL_LOANS_ADD_REWARD_V13 5
typedef struct {
    pd_Balance_t amount;
} pd_loans_add_reward_V13_t;

#define PD_CALL_LOANS_WITHDRAW_MISSING_REWARD_V13 6
typedef struct {
    pd_LookupasStaticLookupSource_V13_t target_account;
    pd_Balance_t amount;
} pd_loans_withdraw_missing_reward_V13_t;

#define PD_CALL_LOANS_UPDATE_MARKET_REWARD_SPEED_V13 7
typedef struct {
    pd_AssetIdOfT_V13_t asset_id;
    pd_Balance_t supply_reward_per_block;
    pd_Balance_t borrow_reward_per_block;
} pd_loans_update_market_reward_speed_V13_t;

#define PD_CALL_LOANS_CLAIM_REWARD_V13 8
typedef struct {
} pd_loans_claim_reward_V13_t;

#define PD_CALL_LOANS_CLAIM_REWARD_FOR_MARKET_V13 9
typedef struct {
    pd_AssetIdOfT_V13_t asset_id;
} pd_loans_claim_reward_for_market_V13_t;

#define PD_CALL_LOANS_REDUCE_INCENTIVE_RESERVES_V13 20
typedef struct {
    pd_LookupasStaticLookupSource_V13_t receiver;
    pd_AssetIdOfT_V13_t asset_id;
    pd_Compactu128_t redeem_amount;
} pd_loans_reduce_incentive_reserves_V13_t;

#define PD_CALL_CROWDLOANS_SET_VRF_V13 4
typedef struct {
    pd_bool_t flag;
} pd_crowdloans_set_vrf_V13_t;

#define PD_CALL_LIQUIDSTAKING_STAKE_V13 0
typedef struct {
    pd_Compactu128_t amount;
} pd_liquidstaking_stake_V13_t;

#define PD_CALL_LIQUIDSTAKING_UNSTAKE_V13 1
typedef struct {
    pd_Compactu128_t liquid_amount;
} pd_liquidstaking_unstake_V13_t;

#define PD_CALL_LIQUIDSTAKING_UPDATE_RESERVE_FACTOR_V13 2
typedef struct {
    pd_Ratio_V13_t reserve_factor;
} pd_liquidstaking_update_reserve_factor_V13_t;

#define PD_CALL_LIQUIDSTAKING_UPDATE_STAKING_LEDGER_CAP_V13 3
typedef struct {
    pd_Compactu128_t cap;
} pd_liquidstaking_update_staking_ledger_cap_V13_t;

#define PD_CALL_LIQUIDSTAKING_NOMINATE_V13 9
typedef struct {
    pd_DerivativeIndex_V13_t derivative_index;
    pd_VecAccountId_V13_t targets;
} pd_liquidstaking_nominate_V13_t;

#define PD_CALL_LIQUIDSTAKING_CLAIM_FOR_V13 11
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
} pd_liquidstaking_claim_for_V13_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_SET_CURRENT_ERA_V13 13
typedef struct {
    pd_EraIndex_V13_t era;
} pd_liquidstaking_force_set_current_era_V13_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_ADVANCE_ERA_V13 14
typedef struct {
    pd_EraIndex_V13_t offset;
} pd_liquidstaking_force_advance_era_V13_t;

#define PD_CALL_LIQUIDSTAKING_FORCE_MATCHING_V13 15
typedef struct {
} pd_liquidstaking_force_matching_V13_t;

#define PD_CALL_LIQUIDSTAKING_SET_CURRENT_ERA_V13 17
typedef struct {
    pd_EraIndex_V13_t era;
    pd_VecVecu8_t proof;
} pd_liquidstaking_set_current_era_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_generalcouncilmembership_add_member_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_generalcouncilmembership_remove_member_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_generalcouncilmembership_swap_member_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_generalcouncilmembership_reset_members_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_generalcouncilmembership_change_key_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_generalcouncilmembership_set_prime_V13_t;

#define PD_CALL_GENERALCOUNCILMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_generalcouncilmembership_clear_prime_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_technicalcommitteemembership_add_member_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_technicalcommitteemembership_remove_member_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_technicalcommitteemembership_swap_member_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_technicalcommitteemembership_reset_members_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_technicalcommitteemembership_change_key_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_technicalcommitteemembership_set_prime_V13_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_technicalcommitteemembership_clear_prime_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_oraclemembership_add_member_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_oraclemembership_remove_member_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_oraclemembership_swap_member_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_oraclemembership_reset_members_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_oraclemembership_change_key_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_oraclemembership_set_prime_V13_t;

#define PD_CALL_ORACLEMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_oraclemembership_clear_prime_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_liquidstakingagentsmembership_add_member_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_liquidstakingagentsmembership_remove_member_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_liquidstakingagentsmembership_swap_member_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_liquidstakingagentsmembership_reset_members_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_liquidstakingagentsmembership_change_key_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_liquidstakingagentsmembership_set_prime_V13_t;

#define PD_CALL_LIQUIDSTAKINGAGENTSMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_liquidstakingagentsmembership_clear_prime_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_bridgemembership_add_member_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_bridgemembership_remove_member_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_bridgemembership_swap_member_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_bridgemembership_reset_members_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_bridgemembership_change_key_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_bridgemembership_set_prime_V13_t;

#define PD_CALL_BRIDGEMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_bridgemembership_clear_prime_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_crowdloansautomatorsmembership_add_member_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_crowdloansautomatorsmembership_remove_member_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_crowdloansautomatorsmembership_swap_member_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_crowdloansautomatorsmembership_reset_members_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_crowdloansautomatorsmembership_change_key_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_crowdloansautomatorsmembership_set_prime_V13_t;

#define PD_CALL_CROWDLOANSAUTOMATORSMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_crowdloansautomatorsmembership_clear_prime_V13_t;

#define PD_CALL_BRIDGE_SET_BRIDGE_TOKEN_STATUS_V13 5
typedef struct {
    pd_CurrencyId_V13_t bridge_token_id;
    pd_bool_t enable;
} pd_bridge_set_bridge_token_status_V13_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_PALLET_V13 0
typedef struct {
    pd_u8_t pallet_idx;
} pd_emergencyshutdown_toggle_pallet_V13_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_CALL_V13 1
typedef struct {
    pd_u8_t pallet_idx;
    pd_u8_t call_idx;
} pd_emergencyshutdown_toggle_call_V13_t;

#define PD_CALL_FARMING_SET_POOL_COOL_DOWN_DURATION_V13 2
typedef struct {
    pd_AssetIdOfT_V13_t asset;
    pd_AssetIdOfT_V13_t reward_asset;
    pd_BlockNumber_t lock_duration;
    pd_BlockNumber_t cool_down_duration;
} pd_farming_set_pool_cool_down_duration_V13_t;

#define PD_CALL_FARMING_RESET_POOL_UNLOCK_HEIGHT_V13 3
typedef struct {
    pd_AssetIdOfT_V13_t asset;
    pd_AssetIdOfT_V13_t reward_asset;
    pd_BlockNumber_t lock_duration;
} pd_farming_reset_pool_unlock_height_V13_t;

#define PD_CALL_STREAMING_SET_MINIMUM_DEPOSIT_V13 3
typedef struct {
    pd_AssetIdOfT_V13_t asset_id;
    pd_Balance_t minimum_deposit;
} pd_streaming_set_minimum_deposit_V13_t;

#define PD_CALL_PARACHAINSYSTEM_AUTHORIZE_UPGRADE_V13 2
typedef struct {
    pd_Hash_t code_hash;
} pd_parachainsystem_authorize_upgrade_V13_t;

#define PD_CALL_PARACHAINSYSTEM_ENACT_AUTHORIZED_UPGRADE_V13 3
typedef struct {
    pd_Vecu8_t code;
} pd_parachainsystem_enact_authorized_upgrade_V13_t;

#endif

typedef union {
    pd_utility_batch_V13_t utility_batch_V13;
    pd_utility_batch_all_V13_t utility_batch_all_V13;
    pd_balances_transfer_all_V13_t balances_transfer_all_V13;
    pd_session_set_keys_V13_t session_set_keys_V13;
    pd_session_purge_keys_V13_t session_purge_keys_V13;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V13_t timestamp_set_V13;
    pd_balances_force_unreserve_V13_t balances_force_unreserve_V13;
    pd_assets_create_V13_t assets_create_V13;
    pd_assets_force_create_V13_t assets_force_create_V13;
    pd_assets_destroy_V13_t assets_destroy_V13;
    pd_assets_mint_V13_t assets_mint_V13;
    pd_assets_burn_V13_t assets_burn_V13;
    pd_assets_transfer_V13_t assets_transfer_V13;
    pd_assets_transfer_keep_alive_V13_t assets_transfer_keep_alive_V13;
    pd_assets_force_transfer_V13_t assets_force_transfer_V13;
    pd_assets_freeze_V13_t assets_freeze_V13;
    pd_assets_thaw_V13_t assets_thaw_V13;
    pd_assets_freeze_asset_V13_t assets_freeze_asset_V13;
    pd_assets_thaw_asset_V13_t assets_thaw_asset_V13;
    pd_assets_transfer_ownership_V13_t assets_transfer_ownership_V13;
    pd_assets_set_team_V13_t assets_set_team_V13;
    pd_assets_set_metadata_V13_t assets_set_metadata_V13;
    pd_assets_clear_metadata_V13_t assets_clear_metadata_V13;
    pd_assets_force_set_metadata_V13_t assets_force_set_metadata_V13;
    pd_assets_force_clear_metadata_V13_t assets_force_clear_metadata_V13;
    pd_assets_force_asset_status_V13_t assets_force_asset_status_V13;
    pd_assets_approve_transfer_V13_t assets_approve_transfer_V13;
    pd_assets_cancel_approval_V13_t assets_cancel_approval_V13;
    pd_assets_force_cancel_approval_V13_t assets_force_cancel_approval_V13;
    pd_assets_transfer_approved_V13_t assets_transfer_approved_V13;
    pd_assets_touch_V13_t assets_touch_V13;
    pd_assets_refund_V13_t assets_refund_V13;
    pd_proxy_add_proxy_V13_t proxy_add_proxy_V13;
    pd_proxy_remove_proxy_V13_t proxy_remove_proxy_V13;
    pd_proxy_remove_proxies_V13_t proxy_remove_proxies_V13;
    pd_proxy_anonymous_V13_t proxy_anonymous_V13;
    pd_proxy_kill_anonymous_V13_t proxy_kill_anonymous_V13;
    pd_proxy_announce_V13_t proxy_announce_V13;
    pd_proxy_remove_announcement_V13_t proxy_remove_announcement_V13;
    pd_proxy_reject_announcement_V13_t proxy_reject_announcement_V13;
    pd_proxy_proxy_announced_V13_t proxy_proxy_announced_V13;
    pd_identity_add_registrar_V13_t identity_add_registrar_V13;
    pd_identity_clear_identity_V13_t identity_clear_identity_V13;
    pd_identity_request_judgement_V13_t identity_request_judgement_V13;
    pd_identity_cancel_request_V13_t identity_cancel_request_V13;
    pd_identity_set_fee_V13_t identity_set_fee_V13;
    pd_identity_set_account_id_V13_t identity_set_account_id_V13;
    pd_identity_kill_identity_V13_t identity_kill_identity_V13;
    pd_identity_remove_sub_V13_t identity_remove_sub_V13;
    pd_identity_quit_sub_V13_t identity_quit_sub_V13;
    pd_sudo_sudo_V13_t sudo_sudo_V13;
    pd_sudo_sudo_unchecked_weight_V13_t sudo_sudo_unchecked_weight_V13;
    pd_sudo_set_key_V13_t sudo_set_key_V13;
    pd_sudo_sudo_as_V13_t sudo_sudo_as_V13;
    pd_democracy_propose_V13_t democracy_propose_V13;
    pd_democracy_second_V13_t democracy_second_V13;
    pd_democracy_emergency_cancel_V13_t democracy_emergency_cancel_V13;
    pd_democracy_external_propose_V13_t democracy_external_propose_V13;
    pd_democracy_external_propose_majority_V13_t democracy_external_propose_majority_V13;
    pd_democracy_external_propose_default_V13_t democracy_external_propose_default_V13;
    pd_democracy_fast_track_V13_t democracy_fast_track_V13;
    pd_democracy_veto_external_V13_t democracy_veto_external_V13;
    pd_democracy_cancel_referendum_V13_t democracy_cancel_referendum_V13;
    pd_democracy_cancel_queued_V13_t democracy_cancel_queued_V13;
    pd_democracy_delegate_V13_t democracy_delegate_V13;
    pd_democracy_undelegate_V13_t democracy_undelegate_V13;
    pd_democracy_clear_public_proposals_V13_t democracy_clear_public_proposals_V13;
    pd_democracy_note_preimage_V13_t democracy_note_preimage_V13;
    pd_democracy_note_preimage_operational_V13_t democracy_note_preimage_operational_V13;
    pd_democracy_note_imminent_preimage_V13_t democracy_note_imminent_preimage_V13;
    pd_democracy_note_imminent_preimage_operational_V13_t democracy_note_imminent_preimage_operational_V13;
    pd_democracy_reap_preimage_V13_t democracy_reap_preimage_V13;
    pd_democracy_unlock_V13_t democracy_unlock_V13;
    pd_democracy_remove_vote_V13_t democracy_remove_vote_V13;
    pd_democracy_remove_other_vote_V13_t democracy_remove_other_vote_V13;
    pd_democracy_enact_proposal_V13_t democracy_enact_proposal_V13;
    pd_democracy_cancel_proposal_V13_t democracy_cancel_proposal_V13;
    pd_generalcouncil_set_members_V13_t generalcouncil_set_members_V13;
    pd_generalcouncil_execute_V13_t generalcouncil_execute_V13;
    pd_generalcouncil_propose_V13_t generalcouncil_propose_V13;
    pd_generalcouncil_vote_V13_t generalcouncil_vote_V13;
    pd_generalcouncil_close_V13_t generalcouncil_close_V13;
    pd_generalcouncil_disapprove_proposal_V13_t generalcouncil_disapprove_proposal_V13;
    pd_technicalcommittee_set_members_V13_t technicalcommittee_set_members_V13;
    pd_technicalcommittee_execute_V13_t technicalcommittee_execute_V13;
    pd_technicalcommittee_propose_V13_t technicalcommittee_propose_V13;
    pd_technicalcommittee_vote_V13_t technicalcommittee_vote_V13;
    pd_technicalcommittee_close_V13_t technicalcommittee_close_V13;
    pd_technicalcommittee_disapprove_proposal_V13_t technicalcommittee_disapprove_proposal_V13;
    pd_treasury_propose_spend_V13_t treasury_propose_spend_V13;
    pd_treasury_reject_proposal_V13_t treasury_reject_proposal_V13;
    pd_treasury_approve_proposal_V13_t treasury_approve_proposal_V13;
    pd_preimage_note_preimage_V13_t preimage_note_preimage_V13;
    pd_preimage_unnote_preimage_V13_t preimage_unnote_preimage_V13;
    pd_preimage_request_preimage_V13_t preimage_request_preimage_V13;
    pd_preimage_unrequest_preimage_V13_t preimage_unrequest_preimage_V13;
    pd_xcmpqueue_suspend_xcm_execution_V13_t xcmpqueue_suspend_xcm_execution_V13;
    pd_xcmpqueue_resume_xcm_execution_V13_t xcmpqueue_resume_xcm_execution_V13;
    pd_xcmpqueue_update_suspend_threshold_V13_t xcmpqueue_update_suspend_threshold_V13;
    pd_xcmpqueue_update_drop_threshold_V13_t xcmpqueue_update_drop_threshold_V13;
    pd_xcmpqueue_update_resume_threshold_V13_t xcmpqueue_update_resume_threshold_V13;
    pd_xcmpqueue_update_threshold_weight_V13_t xcmpqueue_update_threshold_weight_V13;
    pd_xcmpqueue_update_weight_restrict_decay_V13_t xcmpqueue_update_weight_restrict_decay_V13;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V13_t xcmpqueue_update_xcmp_max_individual_weight_V13;
    pd_collatorselection_set_invulnerables_V13_t collatorselection_set_invulnerables_V13;
    pd_collatorselection_set_desired_candidates_V13_t collatorselection_set_desired_candidates_V13;
    pd_collatorselection_set_candidacy_bond_V13_t collatorselection_set_candidacy_bond_V13;
    pd_collatorselection_register_as_candidate_V13_t collatorselection_register_as_candidate_V13;
    pd_collatorselection_leave_intent_V13_t collatorselection_leave_intent_V13;
    pd_vesting_claim_V13_t vesting_claim_V13;
    pd_vesting_vested_transfer_V13_t vesting_vested_transfer_V13;
    pd_vesting_update_vesting_schedules_V13_t vesting_update_vesting_schedules_V13;
    pd_vesting_claim_for_V13_t vesting_claim_for_V13;
    pd_loans_add_reward_V13_t loans_add_reward_V13;
    pd_loans_withdraw_missing_reward_V13_t loans_withdraw_missing_reward_V13;
    pd_loans_update_market_reward_speed_V13_t loans_update_market_reward_speed_V13;
    pd_loans_claim_reward_V13_t loans_claim_reward_V13;
    pd_loans_claim_reward_for_market_V13_t loans_claim_reward_for_market_V13;
    pd_loans_reduce_incentive_reserves_V13_t loans_reduce_incentive_reserves_V13;
    pd_crowdloans_set_vrf_V13_t crowdloans_set_vrf_V13;
    pd_liquidstaking_stake_V13_t liquidstaking_stake_V13;
    pd_liquidstaking_unstake_V13_t liquidstaking_unstake_V13;
    pd_liquidstaking_update_reserve_factor_V13_t liquidstaking_update_reserve_factor_V13;
    pd_liquidstaking_update_staking_ledger_cap_V13_t liquidstaking_update_staking_ledger_cap_V13;
    pd_liquidstaking_nominate_V13_t liquidstaking_nominate_V13;
    pd_liquidstaking_claim_for_V13_t liquidstaking_claim_for_V13;
    pd_liquidstaking_force_set_current_era_V13_t liquidstaking_force_set_current_era_V13;
    pd_liquidstaking_force_advance_era_V13_t liquidstaking_force_advance_era_V13;
    pd_liquidstaking_force_matching_V13_t liquidstaking_force_matching_V13;
    pd_liquidstaking_set_current_era_V13_t liquidstaking_set_current_era_V13;
    pd_generalcouncilmembership_add_member_V13_t generalcouncilmembership_add_member_V13;
    pd_generalcouncilmembership_remove_member_V13_t generalcouncilmembership_remove_member_V13;
    pd_generalcouncilmembership_swap_member_V13_t generalcouncilmembership_swap_member_V13;
    pd_generalcouncilmembership_reset_members_V13_t generalcouncilmembership_reset_members_V13;
    pd_generalcouncilmembership_change_key_V13_t generalcouncilmembership_change_key_V13;
    pd_generalcouncilmembership_set_prime_V13_t generalcouncilmembership_set_prime_V13;
    pd_generalcouncilmembership_clear_prime_V13_t generalcouncilmembership_clear_prime_V13;
    pd_technicalcommitteemembership_add_member_V13_t technicalcommitteemembership_add_member_V13;
    pd_technicalcommitteemembership_remove_member_V13_t technicalcommitteemembership_remove_member_V13;
    pd_technicalcommitteemembership_swap_member_V13_t technicalcommitteemembership_swap_member_V13;
    pd_technicalcommitteemembership_reset_members_V13_t technicalcommitteemembership_reset_members_V13;
    pd_technicalcommitteemembership_change_key_V13_t technicalcommitteemembership_change_key_V13;
    pd_technicalcommitteemembership_set_prime_V13_t technicalcommitteemembership_set_prime_V13;
    pd_technicalcommitteemembership_clear_prime_V13_t technicalcommitteemembership_clear_prime_V13;
    pd_oraclemembership_add_member_V13_t oraclemembership_add_member_V13;
    pd_oraclemembership_remove_member_V13_t oraclemembership_remove_member_V13;
    pd_oraclemembership_swap_member_V13_t oraclemembership_swap_member_V13;
    pd_oraclemembership_reset_members_V13_t oraclemembership_reset_members_V13;
    pd_oraclemembership_change_key_V13_t oraclemembership_change_key_V13;
    pd_oraclemembership_set_prime_V13_t oraclemembership_set_prime_V13;
    pd_oraclemembership_clear_prime_V13_t oraclemembership_clear_prime_V13;
    pd_liquidstakingagentsmembership_add_member_V13_t liquidstakingagentsmembership_add_member_V13;
    pd_liquidstakingagentsmembership_remove_member_V13_t liquidstakingagentsmembership_remove_member_V13;
    pd_liquidstakingagentsmembership_swap_member_V13_t liquidstakingagentsmembership_swap_member_V13;
    pd_liquidstakingagentsmembership_reset_members_V13_t liquidstakingagentsmembership_reset_members_V13;
    pd_liquidstakingagentsmembership_change_key_V13_t liquidstakingagentsmembership_change_key_V13;
    pd_liquidstakingagentsmembership_set_prime_V13_t liquidstakingagentsmembership_set_prime_V13;
    pd_liquidstakingagentsmembership_clear_prime_V13_t liquidstakingagentsmembership_clear_prime_V13;
    pd_bridgemembership_add_member_V13_t bridgemembership_add_member_V13;
    pd_bridgemembership_remove_member_V13_t bridgemembership_remove_member_V13;
    pd_bridgemembership_swap_member_V13_t bridgemembership_swap_member_V13;
    pd_bridgemembership_reset_members_V13_t bridgemembership_reset_members_V13;
    pd_bridgemembership_change_key_V13_t bridgemembership_change_key_V13;
    pd_bridgemembership_set_prime_V13_t bridgemembership_set_prime_V13;
    pd_bridgemembership_clear_prime_V13_t bridgemembership_clear_prime_V13;
    pd_crowdloansautomatorsmembership_add_member_V13_t crowdloansautomatorsmembership_add_member_V13;
    pd_crowdloansautomatorsmembership_remove_member_V13_t crowdloansautomatorsmembership_remove_member_V13;
    pd_crowdloansautomatorsmembership_swap_member_V13_t crowdloansautomatorsmembership_swap_member_V13;
    pd_crowdloansautomatorsmembership_reset_members_V13_t crowdloansautomatorsmembership_reset_members_V13;
    pd_crowdloansautomatorsmembership_change_key_V13_t crowdloansautomatorsmembership_change_key_V13;
    pd_crowdloansautomatorsmembership_set_prime_V13_t crowdloansautomatorsmembership_set_prime_V13;
    pd_crowdloansautomatorsmembership_clear_prime_V13_t crowdloansautomatorsmembership_clear_prime_V13;
    pd_bridge_set_bridge_token_status_V13_t bridge_set_bridge_token_status_V13;
    pd_emergencyshutdown_toggle_pallet_V13_t emergencyshutdown_toggle_pallet_V13;
    pd_emergencyshutdown_toggle_call_V13_t emergencyshutdown_toggle_call_V13;
    pd_farming_set_pool_cool_down_duration_V13_t farming_set_pool_cool_down_duration_V13;
    pd_farming_reset_pool_unlock_height_V13_t farming_reset_pool_unlock_height_V13;
    pd_streaming_set_minimum_deposit_V13_t streaming_set_minimum_deposit_V13;
    pd_parachainsystem_authorize_upgrade_V13_t parachainsystem_authorize_upgrade_V13;
    pd_parachainsystem_enact_authorized_upgrade_V13_t parachainsystem_enact_authorized_upgrade_V13;
#endif
} pd_MethodBasic_V13_t;

#define PD_CALL_BALANCES_TRANSFER_V13 0
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V13_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V13 2
typedef struct {
    pd_LookupasStaticLookupSource_V13_t source;
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V13_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V13 3
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V13_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V13 0
typedef struct {
    pd_Perbill_V13_t ratio;
} pd_system_fill_block_V13_t;

#define PD_CALL_SYSTEM_REMARK_V13 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V13_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V13 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V13_t;

#define PD_CALL_SYSTEM_SET_CODE_V13 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V13_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V13 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V13_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V13 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V13_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V13 0
typedef struct {
    pd_VecAccountId_V13_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V13_t;

#define PD_CALL_MULTISIG_AS_MULTI_V13 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V13_t other_signatories;
    pd_OptionTimepoint_V13_t maybe_timepoint;
    pd_OpaqueCall_V13_t call;
    pd_bool_t store_call;
    pd_Weight_V13_t max_weight;
} pd_multisig_as_multi_V13_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V13 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V13_t other_signatories;
    pd_OptionTimepoint_V13_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V13_t max_weight;
} pd_multisig_approve_as_multi_V13_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V13 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V13_t other_signatories;
    pd_Timepoint_V13_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V13_t;

#define PD_CALL_BALANCES_SET_BALANCE_V13 1
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V13_t;

#define PD_CALL_PROXY_PROXY_V13 0
typedef struct {
    pd_AccountId_V13_t real;
    pd_OptionProxyType_V13_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V13_t;

#endif

typedef union {
    pd_balances_transfer_V13_t balances_transfer_V13;
    pd_balances_force_transfer_V13_t balances_force_transfer_V13;
    pd_balances_transfer_keep_alive_V13_t balances_transfer_keep_alive_V13;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V13_t system_fill_block_V13;
    pd_system_remark_V13_t system_remark_V13;
    pd_system_set_heap_pages_V13_t system_set_heap_pages_V13;
    pd_system_set_code_V13_t system_set_code_V13;
    pd_system_set_code_without_checks_V13_t system_set_code_without_checks_V13;
    pd_system_remark_with_event_V13_t system_remark_with_event_V13;
    pd_multisig_as_multi_threshold_1_V13_t multisig_as_multi_threshold_1_V13;
    pd_multisig_as_multi_V13_t multisig_as_multi_V13;
    pd_multisig_approve_as_multi_V13_t multisig_approve_as_multi_V13;
    pd_multisig_cancel_as_multi_V13_t multisig_cancel_as_multi_V13;
    pd_balances_set_balance_V13_t balances_set_balance_V13;
    pd_proxy_proxy_V13_t proxy_proxy_V13;
#endif
} pd_MethodNested_V13_t;

typedef union {
    pd_MethodBasic_V13_t basic;
    pd_MethodNested_V13_t nested;
} pd_Method_V13_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
