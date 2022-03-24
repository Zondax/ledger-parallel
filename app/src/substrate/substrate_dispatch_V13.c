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

#include "substrate_dispatch_V13.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_utility_batch_V13(
    parser_context_t* c, pd_utility_batch_V13_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V13(
    parser_context_t* c, pd_utility_batch_all_V13_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V13(
    parser_context_t* c, pd_balances_transfer_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V13(
    parser_context_t* c, pd_balances_force_transfer_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V13(
    parser_context_t* c, pd_balances_transfer_keep_alive_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V13(
    parser_context_t* c, pd_balances_transfer_all_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V13(
    parser_context_t* c, pd_session_set_keys_V13_t* m)
{
    CHECK_ERROR(_readKeys_V13(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V13(
    parser_context_t* c, pd_session_purge_keys_V13_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V13(
    parser_context_t* c, pd_system_fill_block_V13_t* m)
{
    CHECK_ERROR(_readPerbill_V13(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V13(
    parser_context_t* c, pd_system_remark_V13_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V13(
    parser_context_t* c, pd_system_set_heap_pages_V13_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V13(
    parser_context_t* c, pd_system_set_code_V13_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V13(
    parser_context_t* c, pd_system_set_code_without_checks_V13_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V13(
    parser_context_t* c, pd_system_remark_with_event_V13_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V13(
    parser_context_t* c, pd_timestamp_set_V13_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V13(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V13(
    parser_context_t* c, pd_multisig_as_multi_V13_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V13(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V13(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V13(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V13(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V13(
    parser_context_t* c, pd_multisig_approve_as_multi_V13_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V13(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V13(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V13(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V13(
    parser_context_t* c, pd_multisig_cancel_as_multi_V13_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V13(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V13(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V13(
    parser_context_t* c, pd_balances_set_balance_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V13(
    parser_context_t* c, pd_balances_force_unreserve_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_create_V13(
    parser_context_t* c, pd_assets_create_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V13(
    parser_context_t* c, pd_assets_force_create_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactu128(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_V13(
    parser_context_t* c, pd_assets_destroy_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readDestroyWitness_V13(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V13(
    parser_context_t* c, pd_assets_mint_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->beneficiary))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V13(
    parser_context_t* c, pd_assets_burn_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V13(
    parser_context_t* c, pd_assets_transfer_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->target))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_keep_alive_V13(
    parser_context_t* c, pd_assets_transfer_keep_alive_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->target))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V13(
    parser_context_t* c, pd_assets_force_transfer_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V13(
    parser_context_t* c, pd_assets_freeze_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V13(
    parser_context_t* c, pd_assets_thaw_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_asset_V13(
    parser_context_t* c, pd_assets_freeze_asset_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_asset_V13(
    parser_context_t* c, pd_assets_thaw_asset_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V13(
    parser_context_t* c, pd_assets_transfer_ownership_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V13(
    parser_context_t* c, pd_assets_set_team_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_metadata_V13(
    parser_context_t* c, pd_assets_set_metadata_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_clear_metadata_V13(
    parser_context_t* c, pd_assets_clear_metadata_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_set_metadata_V13(
    parser_context_t* c, pd_assets_force_set_metadata_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_clear_metadata_V13(
    parser_context_t* c, pd_assets_force_clear_metadata_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_asset_status_V13(
    parser_context_t* c, pd_assets_force_asset_status_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->freezer))
    CHECK_ERROR(_readCompactu128(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_approve_transfer_V13(
    parser_context_t* c, pd_assets_approve_transfer_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->delegate))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V13(
    parser_context_t* c, pd_assets_cancel_approval_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_cancel_approval_V13(
    parser_context_t* c, pd_assets_force_cancel_approval_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_approved_V13(
    parser_context_t* c, pd_assets_transfer_approved_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->destination))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_V13(
    parser_context_t* c, pd_assets_touch_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_V13(
    parser_context_t* c, pd_assets_refund_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V13(
    parser_context_t* c, pd_proxy_announce_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V13(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V13(
    parser_context_t* c, pd_proxy_remove_announcement_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V13(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V13(
    parser_context_t* c, pd_proxy_reject_announcement_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V13(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V13(
    parser_context_t* c, pd_identity_add_registrar_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V13(
    parser_context_t* c, pd_identity_clear_identity_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V13(
    parser_context_t* c, pd_identity_request_judgement_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V13(
    parser_context_t* c, pd_identity_cancel_request_V13_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V13(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V13(
    parser_context_t* c, pd_identity_set_fee_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V13(
    parser_context_t* c, pd_identity_set_account_id_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V13(
    parser_context_t* c, pd_identity_kill_identity_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V13(
    parser_context_t* c, pd_identity_remove_sub_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V13(
    parser_context_t* c, pd_identity_quit_sub_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V13(
    parser_context_t* c, pd_sudo_sudo_V13_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V13(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V13_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V13(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V13(
    parser_context_t* c, pd_sudo_set_key_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V13(
    parser_context_t* c, pd_sudo_sudo_as_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V13(
    parser_context_t* c, pd_democracy_propose_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V13(
    parser_context_t* c, pd_democracy_second_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V13(
    parser_context_t* c, pd_democracy_emergency_cancel_V13_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V13(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V13(
    parser_context_t* c, pd_democracy_external_propose_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V13(
    parser_context_t* c, pd_democracy_external_propose_majority_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V13(
    parser_context_t* c, pd_democracy_external_propose_default_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V13(
    parser_context_t* c, pd_democracy_fast_track_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V13(
    parser_context_t* c, pd_democracy_veto_external_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V13(
    parser_context_t* c, pd_democracy_cancel_referendum_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V13(
    parser_context_t* c, pd_democracy_cancel_queued_V13_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V13(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V13(
    parser_context_t* c, pd_democracy_delegate_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->to))
    CHECK_ERROR(_readConviction_V13(c, &m->conviction))
    CHECK_ERROR(_readBalance(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V13(
    parser_context_t* c, pd_democracy_undelegate_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V13(
    parser_context_t* c, pd_democracy_clear_public_proposals_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V13(
    parser_context_t* c, pd_democracy_note_preimage_V13_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V13(
    parser_context_t* c, pd_democracy_note_preimage_operational_V13_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V13(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V13_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V13(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V13_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V13(
    parser_context_t* c, pd_democracy_reap_preimage_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V13(
    parser_context_t* c, pd_democracy_unlock_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V13(
    parser_context_t* c, pd_democracy_remove_vote_V13_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V13(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V13(
    parser_context_t* c, pd_democracy_remove_other_vote_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V13(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V13(
    parser_context_t* c, pd_democracy_enact_proposal_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V13(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V13(
    parser_context_t* c, pd_democracy_cancel_proposal_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_set_members_V13(
    parser_context_t* c, pd_generalcouncil_set_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V13(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V13(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_execute_V13(
    parser_context_t* c, pd_generalcouncil_execute_V13_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_propose_V13(
    parser_context_t* c, pd_generalcouncil_propose_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_vote_V13(
    parser_context_t* c, pd_generalcouncil_vote_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_close_V13(
    parser_context_t* c, pd_generalcouncil_close_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_disapprove_proposal_V13(
    parser_context_t* c, pd_generalcouncil_disapprove_proposal_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V13(
    parser_context_t* c, pd_technicalcommittee_set_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V13(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V13(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V13(
    parser_context_t* c, pd_technicalcommittee_execute_V13_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V13(
    parser_context_t* c, pd_technicalcommittee_propose_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V13(
    parser_context_t* c, pd_technicalcommittee_vote_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V13(
    parser_context_t* c, pd_technicalcommittee_close_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V13(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V13(
    parser_context_t* c, pd_treasury_propose_spend_V13_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V13(
    parser_context_t* c, pd_treasury_reject_proposal_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V13(
    parser_context_t* c, pd_treasury_approve_proposal_V13_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V13(
    parser_context_t* c, pd_preimage_note_preimage_V13_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V13(
    parser_context_t* c, pd_preimage_unnote_preimage_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V13(
    parser_context_t* c, pd_preimage_request_preimage_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V13(
    parser_context_t* c, pd_preimage_unrequest_preimage_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_suspend_xcm_execution_V13(
    parser_context_t* c, pd_xcmpqueue_suspend_xcm_execution_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_resume_xcm_execution_V13(
    parser_context_t* c, pd_xcmpqueue_resume_xcm_execution_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_suspend_threshold_V13(
    parser_context_t* c, pd_xcmpqueue_update_suspend_threshold_V13_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_drop_threshold_V13(
    parser_context_t* c, pd_xcmpqueue_update_drop_threshold_V13_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_resume_threshold_V13(
    parser_context_t* c, pd_xcmpqueue_update_resume_threshold_V13_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_threshold_weight_V13(
    parser_context_t* c, pd_xcmpqueue_update_threshold_weight_V13_t* m)
{
    CHECK_ERROR(_readWeight_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_weight_restrict_decay_V13(
    parser_context_t* c, pd_xcmpqueue_update_weight_restrict_decay_V13_t* m)
{
    CHECK_ERROR(_readWeight_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_xcmp_max_individual_weight_V13(
    parser_context_t* c, pd_xcmpqueue_update_xcmp_max_individual_weight_V13_t* m)
{
    CHECK_ERROR(_readWeight_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_invulnerables_V13(
    parser_context_t* c, pd_collatorselection_set_invulnerables_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_desired_candidates_V13(
    parser_context_t* c, pd_collatorselection_set_desired_candidates_V13_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_candidacy_bond_V13(
    parser_context_t* c, pd_collatorselection_set_candidacy_bond_V13_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->bond))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_as_candidate_V13(
    parser_context_t* c, pd_collatorselection_register_as_candidate_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_leave_intent_V13(
    parser_context_t* c, pd_collatorselection_leave_intent_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_V13(
    parser_context_t* c, pd_vesting_claim_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_for_V13(
    parser_context_t* c, pd_vesting_claim_for_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_add_reward_V13(
    parser_context_t* c, pd_loans_add_reward_V13_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_withdraw_missing_reward_V13(
    parser_context_t* c, pd_loans_withdraw_missing_reward_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->target_account))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_update_market_reward_speed_V13(
    parser_context_t* c, pd_loans_update_market_reward_speed_V13_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->asset_id))
    CHECK_ERROR(_readBalance(c, &m->supply_reward_per_block))
    CHECK_ERROR(_readBalance(c, &m->borrow_reward_per_block))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_claim_reward_V13(
    parser_context_t* c, pd_loans_claim_reward_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_claim_reward_for_market_V13(
    parser_context_t* c, pd_loans_claim_reward_for_market_V13_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_reduce_incentive_reserves_V13(
    parser_context_t* c, pd_loans_reduce_incentive_reserves_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->receiver))
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->redeem_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_set_vrf_V13(
    parser_context_t* c, pd_crowdloans_set_vrf_V13_t* m)
{
    CHECK_ERROR(_readbool(c, &m->flag))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_stake_V13(
    parser_context_t* c, pd_liquidstaking_stake_V13_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_unstake_V13(
    parser_context_t* c, pd_liquidstaking_unstake_V13_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->liquid_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_update_reserve_factor_V13(
    parser_context_t* c, pd_liquidstaking_update_reserve_factor_V13_t* m)
{
    CHECK_ERROR(_readRatio_V13(c, &m->reserve_factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_update_staking_ledger_cap_V13(
    parser_context_t* c, pd_liquidstaking_update_staking_ledger_cap_V13_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_nominate_V13(
    parser_context_t* c, pd_liquidstaking_nominate_V13_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V13(c, &m->derivative_index))
    CHECK_ERROR(_readVecAccountId_V13(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_claim_for_V13(
    parser_context_t* c, pd_liquidstaking_claim_for_V13_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V13(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_set_current_era_V13(
    parser_context_t* c, pd_liquidstaking_force_set_current_era_V13_t* m)
{
    CHECK_ERROR(_readEraIndex_V13(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_advance_era_V13(
    parser_context_t* c, pd_liquidstaking_force_advance_era_V13_t* m)
{
    CHECK_ERROR(_readEraIndex_V13(c, &m->offset))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_matching_V13(
    parser_context_t* c, pd_liquidstaking_force_matching_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_set_current_era_V13(
    parser_context_t* c, pd_liquidstaking_set_current_era_V13_t* m)
{
    CHECK_ERROR(_readEraIndex_V13(c, &m->era))
    CHECK_ERROR(_readVecVecu8(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_add_member_V13(
    parser_context_t* c, pd_generalcouncilmembership_add_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_remove_member_V13(
    parser_context_t* c, pd_generalcouncilmembership_remove_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_swap_member_V13(
    parser_context_t* c, pd_generalcouncilmembership_swap_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->remove))
    CHECK_ERROR(_readAccountId_V13(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_reset_members_V13(
    parser_context_t* c, pd_generalcouncilmembership_reset_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_change_key_V13(
    parser_context_t* c, pd_generalcouncilmembership_change_key_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_set_prime_V13(
    parser_context_t* c, pd_generalcouncilmembership_set_prime_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_clear_prime_V13(
    parser_context_t* c, pd_generalcouncilmembership_clear_prime_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member_V13(
    parser_context_t* c, pd_technicalcommitteemembership_add_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_remove_member_V13(
    parser_context_t* c, pd_technicalcommitteemembership_remove_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member_V13(
    parser_context_t* c, pd_technicalcommitteemembership_swap_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->remove))
    CHECK_ERROR(_readAccountId_V13(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_reset_members_V13(
    parser_context_t* c, pd_technicalcommitteemembership_reset_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_change_key_V13(
    parser_context_t* c, pd_technicalcommitteemembership_change_key_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_set_prime_V13(
    parser_context_t* c, pd_technicalcommitteemembership_set_prime_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_clear_prime_V13(
    parser_context_t* c, pd_technicalcommitteemembership_clear_prime_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_add_member_V13(
    parser_context_t* c, pd_oraclemembership_add_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_remove_member_V13(
    parser_context_t* c, pd_oraclemembership_remove_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_swap_member_V13(
    parser_context_t* c, pd_oraclemembership_swap_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->remove))
    CHECK_ERROR(_readAccountId_V13(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_reset_members_V13(
    parser_context_t* c, pd_oraclemembership_reset_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_change_key_V13(
    parser_context_t* c, pd_oraclemembership_change_key_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_set_prime_V13(
    parser_context_t* c, pd_oraclemembership_set_prime_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_clear_prime_V13(
    parser_context_t* c, pd_oraclemembership_clear_prime_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_add_member_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_add_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_remove_member_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_remove_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_swap_member_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_swap_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->remove))
    CHECK_ERROR(_readAccountId_V13(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_reset_members_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_reset_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_change_key_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_change_key_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_set_prime_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_set_prime_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_clear_prime_V13(
    parser_context_t* c, pd_liquidstakingagentsmembership_clear_prime_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_add_member_V13(
    parser_context_t* c, pd_bridgemembership_add_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_remove_member_V13(
    parser_context_t* c, pd_bridgemembership_remove_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_swap_member_V13(
    parser_context_t* c, pd_bridgemembership_swap_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->remove))
    CHECK_ERROR(_readAccountId_V13(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_reset_members_V13(
    parser_context_t* c, pd_bridgemembership_reset_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_change_key_V13(
    parser_context_t* c, pd_bridgemembership_change_key_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_set_prime_V13(
    parser_context_t* c, pd_bridgemembership_set_prime_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_clear_prime_V13(
    parser_context_t* c, pd_bridgemembership_clear_prime_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_add_member_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_add_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_remove_member_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_remove_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_swap_member_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_swap_member_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->remove))
    CHECK_ERROR(_readAccountId_V13(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_reset_members_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_reset_members_V13_t* m)
{
    CHECK_ERROR(_readVecAccountId_V13(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_change_key_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_change_key_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_set_prime_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_set_prime_V13_t* m)
{
    CHECK_ERROR(_readAccountId_V13(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_clear_prime_V13(
    parser_context_t* c, pd_crowdloansautomatorsmembership_clear_prime_V13_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_set_bridge_token_status_V13(
    parser_context_t* c, pd_bridge_set_bridge_token_status_V13_t* m)
{
    CHECK_ERROR(_readCurrencyId_V13(c, &m->bridge_token_id))
    CHECK_ERROR(_readbool(c, &m->enable))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_emergencyshutdown_toggle_pallet_V13(
    parser_context_t* c, pd_emergencyshutdown_toggle_pallet_V13_t* m)
{
    CHECK_ERROR(_readu8(c, &m->pallet_idx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_emergencyshutdown_toggle_call_V13(
    parser_context_t* c, pd_emergencyshutdown_toggle_call_V13_t* m)
{
    CHECK_ERROR(_readu8(c, &m->pallet_idx))
    CHECK_ERROR(_readu8(c, &m->call_idx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_set_pool_cool_down_duration_V13(
    parser_context_t* c, pd_farming_set_pool_cool_down_duration_V13_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readBlockNumber(c, &m->cool_down_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_reset_pool_unlock_height_V13(
    parser_context_t* c, pd_farming_reset_pool_unlock_height_V13_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_streaming_set_minimum_deposit_V13(
    parser_context_t* c, pd_streaming_set_minimum_deposit_V13_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V13(c, &m->asset_id))
    CHECK_ERROR(_readBalance(c, &m->minimum_deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainsystem_authorize_upgrade_V13(
    parser_context_t* c, pd_parachainsystem_authorize_upgrade_V13_t* m)
{
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainsystem_enact_authorized_upgrade_V13(
    parser_context_t* c, pd_parachainsystem_enact_authorized_upgrade_V13_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V13(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V13_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V13(c, &method->basic.utility_batch_V13))
        break;
    case 514: /* module 2 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V13(c, &method->basic.utility_batch_all_V13))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V13(c, &method->nested.balances_transfer_V13))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V13(c, &method->nested.balances_force_transfer_V13))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V13(c, &method->nested.balances_transfer_keep_alive_V13))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V13(c, &method->basic.balances_transfer_all_V13))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V13(c, &method->basic.session_set_keys_V13))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V13(c, &method->basic.session_purge_keys_V13))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V13(c, &method->nested.system_fill_block_V13))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V13(c, &method->nested.system_remark_V13))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V13(c, &method->nested.system_set_heap_pages_V13))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V13(c, &method->nested.system_set_code_V13))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V13(c, &method->nested.system_set_code_without_checks_V13))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V13(c, &method->nested.system_remark_with_event_V13))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V13(c, &method->basic.timestamp_set_V13))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V13(c, &method->nested.multisig_as_multi_threshold_1_V13))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V13(c, &method->nested.multisig_as_multi_V13))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V13(c, &method->nested.multisig_approve_as_multi_V13))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V13(c, &method->nested.multisig_cancel_as_multi_V13))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V13(c, &method->nested.balances_set_balance_V13))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V13(c, &method->basic.balances_force_unreserve_V13))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_assets_create_V13(c, &method->basic.assets_create_V13))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V13(c, &method->basic.assets_force_create_V13))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_assets_destroy_V13(c, &method->basic.assets_destroy_V13))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_assets_mint_V13(c, &method->basic.assets_mint_V13))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_assets_burn_V13(c, &method->basic.assets_burn_V13))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_assets_transfer_V13(c, &method->basic.assets_transfer_V13))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_assets_transfer_keep_alive_V13(c, &method->basic.assets_transfer_keep_alive_V13))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V13(c, &method->basic.assets_force_transfer_V13))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_assets_freeze_V13(c, &method->basic.assets_freeze_V13))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_assets_thaw_V13(c, &method->basic.assets_thaw_V13))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_assets_freeze_asset_V13(c, &method->basic.assets_freeze_asset_V13))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_assets_thaw_asset_V13(c, &method->basic.assets_thaw_asset_V13))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V13(c, &method->basic.assets_transfer_ownership_V13))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_assets_set_team_V13(c, &method->basic.assets_set_team_V13))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_assets_set_metadata_V13(c, &method->basic.assets_set_metadata_V13))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_assets_clear_metadata_V13(c, &method->basic.assets_clear_metadata_V13))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_assets_force_set_metadata_V13(c, &method->basic.assets_force_set_metadata_V13))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_assets_force_clear_metadata_V13(c, &method->basic.assets_force_clear_metadata_V13))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_assets_force_asset_status_V13(c, &method->basic.assets_force_asset_status_V13))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_assets_approve_transfer_V13(c, &method->basic.assets_approve_transfer_V13))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V13(c, &method->basic.assets_cancel_approval_V13))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_assets_force_cancel_approval_V13(c, &method->basic.assets_force_cancel_approval_V13))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_assets_transfer_approved_V13(c, &method->basic.assets_transfer_approved_V13))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_assets_touch_V13(c, &method->basic.assets_touch_V13))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_assets_refund_V13(c, &method->basic.assets_refund_V13))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V13(c, &method->basic.proxy_announce_V13))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V13(c, &method->basic.proxy_remove_announcement_V13))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V13(c, &method->basic.proxy_reject_announcement_V13))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V13(c, &method->basic.identity_add_registrar_V13))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V13(c, &method->basic.identity_clear_identity_V13))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V13(c, &method->basic.identity_request_judgement_V13))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V13(c, &method->basic.identity_cancel_request_V13))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V13(c, &method->basic.identity_set_fee_V13))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V13(c, &method->basic.identity_set_account_id_V13))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V13(c, &method->basic.identity_kill_identity_V13))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V13(c, &method->basic.identity_remove_sub_V13))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V13(c, &method->basic.identity_quit_sub_V13))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V13(c, &method->basic.sudo_sudo_V13))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V13(c, &method->basic.sudo_sudo_unchecked_weight_V13))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V13(c, &method->basic.sudo_set_key_V13))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V13(c, &method->basic.sudo_sudo_as_V13))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V13(c, &method->basic.democracy_propose_V13))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V13(c, &method->basic.democracy_second_V13))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V13(c, &method->basic.democracy_emergency_cancel_V13))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V13(c, &method->basic.democracy_external_propose_V13))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V13(c, &method->basic.democracy_external_propose_majority_V13))
        break;
    case 2822: /* module 11 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V13(c, &method->basic.democracy_external_propose_default_V13))
        break;
    case 2823: /* module 11 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V13(c, &method->basic.democracy_fast_track_V13))
        break;
    case 2824: /* module 11 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V13(c, &method->basic.democracy_veto_external_V13))
        break;
    case 2825: /* module 11 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V13(c, &method->basic.democracy_cancel_referendum_V13))
        break;
    case 2826: /* module 11 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V13(c, &method->basic.democracy_cancel_queued_V13))
        break;
    case 2827: /* module 11 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V13(c, &method->basic.democracy_delegate_V13))
        break;
    case 2828: /* module 11 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V13(c, &method->basic.democracy_undelegate_V13))
        break;
    case 2829: /* module 11 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V13(c, &method->basic.democracy_clear_public_proposals_V13))
        break;
    case 2830: /* module 11 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V13(c, &method->basic.democracy_note_preimage_V13))
        break;
    case 2831: /* module 11 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V13(c, &method->basic.democracy_note_preimage_operational_V13))
        break;
    case 2832: /* module 11 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V13(c, &method->basic.democracy_note_imminent_preimage_V13))
        break;
    case 2833: /* module 11 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V13(c, &method->basic.democracy_note_imminent_preimage_operational_V13))
        break;
    case 2834: /* module 11 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V13(c, &method->basic.democracy_reap_preimage_V13))
        break;
    case 2835: /* module 11 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V13(c, &method->basic.democracy_unlock_V13))
        break;
    case 2836: /* module 11 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V13(c, &method->basic.democracy_remove_vote_V13))
        break;
    case 2837: /* module 11 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V13(c, &method->basic.democracy_remove_other_vote_V13))
        break;
    case 2838: /* module 11 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V13(c, &method->basic.democracy_enact_proposal_V13))
        break;
    case 2840: /* module 11 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V13(c, &method->basic.democracy_cancel_proposal_V13))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_generalcouncil_set_members_V13(c, &method->basic.generalcouncil_set_members_V13))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_generalcouncil_execute_V13(c, &method->basic.generalcouncil_execute_V13))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_generalcouncil_propose_V13(c, &method->basic.generalcouncil_propose_V13))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_generalcouncil_vote_V13(c, &method->basic.generalcouncil_vote_V13))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_generalcouncil_close_V13(c, &method->basic.generalcouncil_close_V13))
        break;
    case 3077: /* module 12 call 5 */
        CHECK_ERROR(_readMethod_generalcouncil_disapprove_proposal_V13(c, &method->basic.generalcouncil_disapprove_proposal_V13))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V13(c, &method->basic.technicalcommittee_set_members_V13))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V13(c, &method->basic.technicalcommittee_execute_V13))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V13(c, &method->basic.technicalcommittee_propose_V13))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V13(c, &method->basic.technicalcommittee_vote_V13))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V13(c, &method->basic.technicalcommittee_close_V13))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V13(c, &method->basic.technicalcommittee_disapprove_proposal_V13))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V13(c, &method->basic.treasury_propose_spend_V13))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V13(c, &method->basic.treasury_reject_proposal_V13))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V13(c, &method->basic.treasury_approve_proposal_V13))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V13(c, &method->basic.preimage_note_preimage_V13))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V13(c, &method->basic.preimage_unnote_preimage_V13))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V13(c, &method->basic.preimage_request_preimage_V13))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V13(c, &method->basic.preimage_unrequest_preimage_V13))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_xcmpqueue_suspend_xcm_execution_V13(c, &method->basic.xcmpqueue_suspend_xcm_execution_V13))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_xcmpqueue_resume_xcm_execution_V13(c, &method->basic.xcmpqueue_resume_xcm_execution_V13))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_suspend_threshold_V13(c, &method->basic.xcmpqueue_update_suspend_threshold_V13))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_drop_threshold_V13(c, &method->basic.xcmpqueue_update_drop_threshold_V13))
        break;
    case 5637: /* module 22 call 5 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_resume_threshold_V13(c, &method->basic.xcmpqueue_update_resume_threshold_V13))
        break;
    case 5638: /* module 22 call 6 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_threshold_weight_V13(c, &method->basic.xcmpqueue_update_threshold_weight_V13))
        break;
    case 5639: /* module 22 call 7 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_weight_restrict_decay_V13(c, &method->basic.xcmpqueue_update_weight_restrict_decay_V13))
        break;
    case 5640: /* module 22 call 8 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_xcmp_max_individual_weight_V13(c, &method->basic.xcmpqueue_update_xcmp_max_individual_weight_V13))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_collatorselection_set_invulnerables_V13(c, &method->basic.collatorselection_set_invulnerables_V13))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_collatorselection_set_desired_candidates_V13(c, &method->basic.collatorselection_set_desired_candidates_V13))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_collatorselection_set_candidacy_bond_V13(c, &method->basic.collatorselection_set_candidacy_bond_V13))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_collatorselection_register_as_candidate_V13(c, &method->basic.collatorselection_register_as_candidate_V13))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_collatorselection_leave_intent_V13(c, &method->basic.collatorselection_leave_intent_V13))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_vesting_claim_V13(c, &method->basic.vesting_claim_V13))
        break;
    case 11779: /* module 46 call 3 */
        CHECK_ERROR(_readMethod_vesting_claim_for_V13(c, &method->basic.vesting_claim_for_V13))
        break;
    case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_loans_add_reward_V13(c, &method->basic.loans_add_reward_V13))
        break;
    case 12806: /* module 50 call 6 */
        CHECK_ERROR(_readMethod_loans_withdraw_missing_reward_V13(c, &method->basic.loans_withdraw_missing_reward_V13))
        break;
    case 12807: /* module 50 call 7 */
        CHECK_ERROR(_readMethod_loans_update_market_reward_speed_V13(c, &method->basic.loans_update_market_reward_speed_V13))
        break;
    case 12808: /* module 50 call 8 */
        CHECK_ERROR(_readMethod_loans_claim_reward_V13(c, &method->basic.loans_claim_reward_V13))
        break;
    case 12809: /* module 50 call 9 */
        CHECK_ERROR(_readMethod_loans_claim_reward_for_market_V13(c, &method->basic.loans_claim_reward_for_market_V13))
        break;
    case 12820: /* module 50 call 20 */
        CHECK_ERROR(_readMethod_loans_reduce_incentive_reserves_V13(c, &method->basic.loans_reduce_incentive_reserves_V13))
        break;
    case 13316: /* module 52 call 4 */
        CHECK_ERROR(_readMethod_crowdloans_set_vrf_V13(c, &method->basic.crowdloans_set_vrf_V13))
        break;
    case 15360: /* module 60 call 0 */
        CHECK_ERROR(_readMethod_liquidstaking_stake_V13(c, &method->basic.liquidstaking_stake_V13))
        break;
    case 15361: /* module 60 call 1 */
        CHECK_ERROR(_readMethod_liquidstaking_unstake_V13(c, &method->basic.liquidstaking_unstake_V13))
        break;
    case 15362: /* module 60 call 2 */
        CHECK_ERROR(_readMethod_liquidstaking_update_reserve_factor_V13(c, &method->basic.liquidstaking_update_reserve_factor_V13))
        break;
    case 15363: /* module 60 call 3 */
        CHECK_ERROR(_readMethod_liquidstaking_update_staking_ledger_cap_V13(c, &method->basic.liquidstaking_update_staking_ledger_cap_V13))
        break;
    case 15369: /* module 60 call 9 */
        CHECK_ERROR(_readMethod_liquidstaking_nominate_V13(c, &method->basic.liquidstaking_nominate_V13))
        break;
    case 15371: /* module 60 call 11 */
        CHECK_ERROR(_readMethod_liquidstaking_claim_for_V13(c, &method->basic.liquidstaking_claim_for_V13))
        break;
    case 15373: /* module 60 call 13 */
        CHECK_ERROR(_readMethod_liquidstaking_force_set_current_era_V13(c, &method->basic.liquidstaking_force_set_current_era_V13))
        break;
    case 15374: /* module 60 call 14 */
        CHECK_ERROR(_readMethod_liquidstaking_force_advance_era_V13(c, &method->basic.liquidstaking_force_advance_era_V13))
        break;
    case 15375: /* module 60 call 15 */
        CHECK_ERROR(_readMethod_liquidstaking_force_matching_V13(c, &method->basic.liquidstaking_force_matching_V13))
        break;
    case 15377: /* module 60 call 17 */
        CHECK_ERROR(_readMethod_liquidstaking_set_current_era_V13(c, &method->basic.liquidstaking_set_current_era_V13))
        break;
    case 17920: /* module 70 call 0 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_add_member_V13(c, &method->basic.generalcouncilmembership_add_member_V13))
        break;
    case 17921: /* module 70 call 1 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_remove_member_V13(c, &method->basic.generalcouncilmembership_remove_member_V13))
        break;
    case 17922: /* module 70 call 2 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_swap_member_V13(c, &method->basic.generalcouncilmembership_swap_member_V13))
        break;
    case 17923: /* module 70 call 3 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_reset_members_V13(c, &method->basic.generalcouncilmembership_reset_members_V13))
        break;
    case 17924: /* module 70 call 4 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_change_key_V13(c, &method->basic.generalcouncilmembership_change_key_V13))
        break;
    case 17925: /* module 70 call 5 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_set_prime_V13(c, &method->basic.generalcouncilmembership_set_prime_V13))
        break;
    case 17926: /* module 70 call 6 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_clear_prime_V13(c, &method->basic.generalcouncilmembership_clear_prime_V13))
        break;
    case 18176: /* module 71 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V13(c, &method->basic.technicalcommitteemembership_add_member_V13))
        break;
    case 18177: /* module 71 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V13(c, &method->basic.technicalcommitteemembership_remove_member_V13))
        break;
    case 18178: /* module 71 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V13(c, &method->basic.technicalcommitteemembership_swap_member_V13))
        break;
    case 18179: /* module 71 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V13(c, &method->basic.technicalcommitteemembership_reset_members_V13))
        break;
    case 18180: /* module 71 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_change_key_V13(c, &method->basic.technicalcommitteemembership_change_key_V13))
        break;
    case 18181: /* module 71 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_prime_V13(c, &method->basic.technicalcommitteemembership_set_prime_V13))
        break;
    case 18182: /* module 71 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_clear_prime_V13(c, &method->basic.technicalcommitteemembership_clear_prime_V13))
        break;
    case 18432: /* module 72 call 0 */
        CHECK_ERROR(_readMethod_oraclemembership_add_member_V13(c, &method->basic.oraclemembership_add_member_V13))
        break;
    case 18433: /* module 72 call 1 */
        CHECK_ERROR(_readMethod_oraclemembership_remove_member_V13(c, &method->basic.oraclemembership_remove_member_V13))
        break;
    case 18434: /* module 72 call 2 */
        CHECK_ERROR(_readMethod_oraclemembership_swap_member_V13(c, &method->basic.oraclemembership_swap_member_V13))
        break;
    case 18435: /* module 72 call 3 */
        CHECK_ERROR(_readMethod_oraclemembership_reset_members_V13(c, &method->basic.oraclemembership_reset_members_V13))
        break;
    case 18436: /* module 72 call 4 */
        CHECK_ERROR(_readMethod_oraclemembership_change_key_V13(c, &method->basic.oraclemembership_change_key_V13))
        break;
    case 18437: /* module 72 call 5 */
        CHECK_ERROR(_readMethod_oraclemembership_set_prime_V13(c, &method->basic.oraclemembership_set_prime_V13))
        break;
    case 18438: /* module 72 call 6 */
        CHECK_ERROR(_readMethod_oraclemembership_clear_prime_V13(c, &method->basic.oraclemembership_clear_prime_V13))
        break;
    case 18688: /* module 73 call 0 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_add_member_V13(c, &method->basic.liquidstakingagentsmembership_add_member_V13))
        break;
    case 18689: /* module 73 call 1 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_remove_member_V13(c, &method->basic.liquidstakingagentsmembership_remove_member_V13))
        break;
    case 18690: /* module 73 call 2 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_swap_member_V13(c, &method->basic.liquidstakingagentsmembership_swap_member_V13))
        break;
    case 18691: /* module 73 call 3 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_reset_members_V13(c, &method->basic.liquidstakingagentsmembership_reset_members_V13))
        break;
    case 18692: /* module 73 call 4 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_change_key_V13(c, &method->basic.liquidstakingagentsmembership_change_key_V13))
        break;
    case 18693: /* module 73 call 5 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_set_prime_V13(c, &method->basic.liquidstakingagentsmembership_set_prime_V13))
        break;
    case 18694: /* module 73 call 6 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_clear_prime_V13(c, &method->basic.liquidstakingagentsmembership_clear_prime_V13))
        break;
    case 18944: /* module 74 call 0 */
        CHECK_ERROR(_readMethod_bridgemembership_add_member_V13(c, &method->basic.bridgemembership_add_member_V13))
        break;
    case 18945: /* module 74 call 1 */
        CHECK_ERROR(_readMethod_bridgemembership_remove_member_V13(c, &method->basic.bridgemembership_remove_member_V13))
        break;
    case 18946: /* module 74 call 2 */
        CHECK_ERROR(_readMethod_bridgemembership_swap_member_V13(c, &method->basic.bridgemembership_swap_member_V13))
        break;
    case 18947: /* module 74 call 3 */
        CHECK_ERROR(_readMethod_bridgemembership_reset_members_V13(c, &method->basic.bridgemembership_reset_members_V13))
        break;
    case 18948: /* module 74 call 4 */
        CHECK_ERROR(_readMethod_bridgemembership_change_key_V13(c, &method->basic.bridgemembership_change_key_V13))
        break;
    case 18949: /* module 74 call 5 */
        CHECK_ERROR(_readMethod_bridgemembership_set_prime_V13(c, &method->basic.bridgemembership_set_prime_V13))
        break;
    case 18950: /* module 74 call 6 */
        CHECK_ERROR(_readMethod_bridgemembership_clear_prime_V13(c, &method->basic.bridgemembership_clear_prime_V13))
        break;
    case 19200: /* module 75 call 0 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_add_member_V13(c, &method->basic.crowdloansautomatorsmembership_add_member_V13))
        break;
    case 19201: /* module 75 call 1 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_remove_member_V13(c, &method->basic.crowdloansautomatorsmembership_remove_member_V13))
        break;
    case 19202: /* module 75 call 2 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_swap_member_V13(c, &method->basic.crowdloansautomatorsmembership_swap_member_V13))
        break;
    case 19203: /* module 75 call 3 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_reset_members_V13(c, &method->basic.crowdloansautomatorsmembership_reset_members_V13))
        break;
    case 19204: /* module 75 call 4 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_change_key_V13(c, &method->basic.crowdloansautomatorsmembership_change_key_V13))
        break;
    case 19205: /* module 75 call 5 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_set_prime_V13(c, &method->basic.crowdloansautomatorsmembership_set_prime_V13))
        break;
    case 19206: /* module 75 call 6 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_clear_prime_V13(c, &method->basic.crowdloansautomatorsmembership_clear_prime_V13))
        break;
    case 23045: /* module 90 call 5 */
        CHECK_ERROR(_readMethod_bridge_set_bridge_token_status_V13(c, &method->basic.bridge_set_bridge_token_status_V13))
        break;
    case 23296: /* module 91 call 0 */
        CHECK_ERROR(_readMethod_emergencyshutdown_toggle_pallet_V13(c, &method->basic.emergencyshutdown_toggle_pallet_V13))
        break;
    case 23297: /* module 91 call 1 */
        CHECK_ERROR(_readMethod_emergencyshutdown_toggle_call_V13(c, &method->basic.emergencyshutdown_toggle_call_V13))
        break;
    case 23554: /* module 92 call 2 */
        CHECK_ERROR(_readMethod_farming_set_pool_cool_down_duration_V13(c, &method->basic.farming_set_pool_cool_down_duration_V13))
        break;
    case 23555: /* module 92 call 3 */
        CHECK_ERROR(_readMethod_farming_reset_pool_unlock_height_V13(c, &method->basic.farming_reset_pool_unlock_height_V13))
        break;
    case 24067: /* module 94 call 3 */
        CHECK_ERROR(_readMethod_streaming_set_minimum_deposit_V13(c, &method->basic.streaming_set_minimum_deposit_V13))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_parachainsystem_authorize_upgrade_V13(c, &method->basic.parachainsystem_authorize_upgrade_V13))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_parachainsystem_enact_authorized_upgrade_V13(c, &method->basic.parachainsystem_enact_authorized_upgrade_V13))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V13(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 2:
        return STR_MO_UTILITY;
    case 4:
        return STR_MO_BALANCES;
    case 32:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 1:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_MULTISIG;
    case 6:
        return STR_MO_ASSETS;
    case 7:
        return STR_MO_PROXY;
    case 8:
        return STR_MO_IDENTITY;
    case 10:
        return STR_MO_SUDO;
    case 11:
        return STR_MO_DEMOCRACY;
    case 12:
        return STR_MO_GENERALCOUNCIL;
    case 13:
        return STR_MO_TECHNICALCOMMITTEE;
    case 14:
        return STR_MO_TREASURY;
    case 16:
        return STR_MO_PREIMAGE;
    case 22:
        return STR_MO_XCMPQUEUE;
    case 31:
        return STR_MO_COLLATORSELECTION;
    case 46:
        return STR_MO_VESTING;
    case 50:
        return STR_MO_LOANS;
    case 52:
        return STR_MO_CROWDLOANS;
    case 60:
        return STR_MO_LIQUIDSTAKING;
    case 70:
        return STR_MO_GENERALCOUNCILMEMBERSHIP;
    case 71:
        return STR_MO_TECHNICALCOMMITTEEMEMBERSHIP;
    case 72:
        return STR_MO_ORACLEMEMBERSHIP;
    case 73:
        return STR_MO_LIQUIDSTAKINGAGENTSMEMBERSHIP;
    case 74:
        return STR_MO_BRIDGEMEMBERSHIP;
    case 75:
        return STR_MO_CROWDLOANSAUTOMATORSMEMBERSHIP;
    case 90:
        return STR_MO_BRIDGE;
    case 91:
        return STR_MO_EMERGENCYSHUTDOWN;
    case 92:
        return STR_MO_FARMING;
    case 94:
        return STR_MO_STREAMING;
    case 20:
        return STR_MO_PARACHAINSYSTEM;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V13(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return STR_ME_BATCH;
    case 514: /* module 2 call 2 */
        return STR_ME_BATCH_ALL;
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 8192: /* module 32 call 0 */
        return STR_ME_SET_KEYS;
    case 8193: /* module 32 call 1 */
        return STR_ME_PURGE_KEYS;
    default:
        return _getMethod_Name_V13_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V13_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 256: /* module 1 call 0 */
        return STR_ME_SET;
    case 768: /* module 3 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 769: /* module 3 call 1 */
        return STR_ME_AS_MULTI;
    case 770: /* module 3 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 771: /* module 3 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 1025: /* module 4 call 1 */
        return STR_ME_SET_BALANCE;
    case 1029: /* module 4 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1536: /* module 6 call 0 */
        return STR_ME_CREATE;
    case 1537: /* module 6 call 1 */
        return STR_ME_FORCE_CREATE;
    case 1538: /* module 6 call 2 */
        return STR_ME_DESTROY;
    case 1539: /* module 6 call 3 */
        return STR_ME_MINT;
    case 1540: /* module 6 call 4 */
        return STR_ME_BURN;
    case 1541: /* module 6 call 5 */
        return STR_ME_TRANSFER;
    case 1542: /* module 6 call 6 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1543: /* module 6 call 7 */
        return STR_ME_FORCE_TRANSFER;
    case 1544: /* module 6 call 8 */
        return STR_ME_FREEZE;
    case 1545: /* module 6 call 9 */
        return STR_ME_THAW;
    case 1546: /* module 6 call 10 */
        return STR_ME_FREEZE_ASSET;
    case 1547: /* module 6 call 11 */
        return STR_ME_THAW_ASSET;
    case 1548: /* module 6 call 12 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 1549: /* module 6 call 13 */
        return STR_ME_SET_TEAM;
    case 1550: /* module 6 call 14 */
        return STR_ME_SET_METADATA;
    case 1551: /* module 6 call 15 */
        return STR_ME_CLEAR_METADATA;
    case 1552: /* module 6 call 16 */
        return STR_ME_FORCE_SET_METADATA;
    case 1553: /* module 6 call 17 */
        return STR_ME_FORCE_CLEAR_METADATA;
    case 1554: /* module 6 call 18 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 1555: /* module 6 call 19 */
        return STR_ME_APPROVE_TRANSFER;
    case 1556: /* module 6 call 20 */
        return STR_ME_CANCEL_APPROVAL;
    case 1557: /* module 6 call 21 */
        return STR_ME_FORCE_CANCEL_APPROVAL;
    case 1558: /* module 6 call 22 */
        return STR_ME_TRANSFER_APPROVED;
    case 1559: /* module 6 call 23 */
        return STR_ME_TOUCH;
    case 1560: /* module 6 call 24 */
        return STR_ME_REFUND;
    case 1798: /* module 7 call 6 */
        return STR_ME_ANNOUNCE;
    case 1799: /* module 7 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 1800: /* module 7 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 2048: /* module 8 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 2051: /* module 8 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 2052: /* module 8 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 2053: /* module 8 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 2054: /* module 8 call 6 */
        return STR_ME_SET_FEE;
    case 2055: /* module 8 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 2058: /* module 8 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 2061: /* module 8 call 13 */
        return STR_ME_REMOVE_SUB;
    case 2062: /* module 8 call 14 */
        return STR_ME_QUIT_SUB;
    case 2560: /* module 10 call 0 */
        return STR_ME_SUDO;
    case 2561: /* module 10 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 2562: /* module 10 call 2 */
        return STR_ME_SET_KEY;
    case 2563: /* module 10 call 3 */
        return STR_ME_SUDO_AS;
    case 2816: /* module 11 call 0 */
        return STR_ME_PROPOSE;
    case 2817: /* module 11 call 1 */
        return STR_ME_SECOND;
    case 2819: /* module 11 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 2820: /* module 11 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 2821: /* module 11 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 2822: /* module 11 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 2823: /* module 11 call 7 */
        return STR_ME_FAST_TRACK;
    case 2824: /* module 11 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 2825: /* module 11 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 2826: /* module 11 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 2827: /* module 11 call 11 */
        return STR_ME_DELEGATE;
    case 2828: /* module 11 call 12 */
        return STR_ME_UNDELEGATE;
    case 2829: /* module 11 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 2830: /* module 11 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 2831: /* module 11 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 2832: /* module 11 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 2833: /* module 11 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 2834: /* module 11 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 2835: /* module 11 call 19 */
        return STR_ME_UNLOCK;
    case 2836: /* module 11 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 2837: /* module 11 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 2838: /* module 11 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 2840: /* module 11 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3072: /* module 12 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3073: /* module 12 call 1 */
        return STR_ME_EXECUTE;
    case 3074: /* module 12 call 2 */
        return STR_ME_PROPOSE;
    case 3075: /* module 12 call 3 */
        return STR_ME_VOTE;
    case 3076: /* module 12 call 4 */
        return STR_ME_CLOSE;
    case 3077: /* module 12 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3328: /* module 13 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3329: /* module 13 call 1 */
        return STR_ME_EXECUTE;
    case 3330: /* module 13 call 2 */
        return STR_ME_PROPOSE;
    case 3331: /* module 13 call 3 */
        return STR_ME_VOTE;
    case 3332: /* module 13 call 4 */
        return STR_ME_CLOSE;
    case 3333: /* module 13 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3584: /* module 14 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 3585: /* module 14 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 3586: /* module 14 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 4097: /* module 16 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 4098: /* module 16 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 4099: /* module 16 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 5633: /* module 22 call 1 */
        return STR_ME_SUSPEND_XCM_EXECUTION;
    case 5634: /* module 22 call 2 */
        return STR_ME_RESUME_XCM_EXECUTION;
    case 5635: /* module 22 call 3 */
        return STR_ME_UPDATE_SUSPEND_THRESHOLD;
    case 5636: /* module 22 call 4 */
        return STR_ME_UPDATE_DROP_THRESHOLD;
    case 5637: /* module 22 call 5 */
        return STR_ME_UPDATE_RESUME_THRESHOLD;
    case 5638: /* module 22 call 6 */
        return STR_ME_UPDATE_THRESHOLD_WEIGHT;
    case 5639: /* module 22 call 7 */
        return STR_ME_UPDATE_WEIGHT_RESTRICT_DECAY;
    case 5640: /* module 22 call 8 */
        return STR_ME_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT;
    case 7936: /* module 31 call 0 */
        return STR_ME_SET_INVULNERABLES;
    case 7937: /* module 31 call 1 */
        return STR_ME_SET_DESIRED_CANDIDATES;
    case 7938: /* module 31 call 2 */
        return STR_ME_SET_CANDIDACY_BOND;
    case 7939: /* module 31 call 3 */
        return STR_ME_REGISTER_AS_CANDIDATE;
    case 7940: /* module 31 call 4 */
        return STR_ME_LEAVE_INTENT;
    case 11776: /* module 46 call 0 */
        return STR_ME_CLAIM;
    case 11779: /* module 46 call 3 */
        return STR_ME_CLAIM_FOR;
    case 12805: /* module 50 call 5 */
        return STR_ME_ADD_REWARD;
    case 12806: /* module 50 call 6 */
        return STR_ME_WITHDRAW_MISSING_REWARD;
    case 12807: /* module 50 call 7 */
        return STR_ME_UPDATE_MARKET_REWARD_SPEED;
    case 12808: /* module 50 call 8 */
        return STR_ME_CLAIM_REWARD;
    case 12809: /* module 50 call 9 */
        return STR_ME_CLAIM_REWARD_FOR_MARKET;
    case 12820: /* module 50 call 20 */
        return STR_ME_REDUCE_INCENTIVE_RESERVES;
    case 13316: /* module 52 call 4 */
        return STR_ME_SET_VRF;
    case 15360: /* module 60 call 0 */
        return STR_ME_STAKE;
    case 15361: /* module 60 call 1 */
        return STR_ME_UNSTAKE;
    case 15362: /* module 60 call 2 */
        return STR_ME_UPDATE_RESERVE_FACTOR;
    case 15363: /* module 60 call 3 */
        return STR_ME_UPDATE_STAKING_LEDGER_CAP;
    case 15369: /* module 60 call 9 */
        return STR_ME_NOMINATE;
    case 15371: /* module 60 call 11 */
        return STR_ME_CLAIM_FOR;
    case 15373: /* module 60 call 13 */
        return STR_ME_FORCE_SET_CURRENT_ERA;
    case 15374: /* module 60 call 14 */
        return STR_ME_FORCE_ADVANCE_ERA;
    case 15375: /* module 60 call 15 */
        return STR_ME_FORCE_MATCHING;
    case 15377: /* module 60 call 17 */
        return STR_ME_SET_CURRENT_ERA;
    case 17920: /* module 70 call 0 */
        return STR_ME_ADD_MEMBER;
    case 17921: /* module 70 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 17922: /* module 70 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 17923: /* module 70 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 17924: /* module 70 call 4 */
        return STR_ME_CHANGE_KEY;
    case 17925: /* module 70 call 5 */
        return STR_ME_SET_PRIME;
    case 17926: /* module 70 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 18176: /* module 71 call 0 */
        return STR_ME_ADD_MEMBER;
    case 18177: /* module 71 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 18178: /* module 71 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 18179: /* module 71 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 18180: /* module 71 call 4 */
        return STR_ME_CHANGE_KEY;
    case 18181: /* module 71 call 5 */
        return STR_ME_SET_PRIME;
    case 18182: /* module 71 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 18432: /* module 72 call 0 */
        return STR_ME_ADD_MEMBER;
    case 18433: /* module 72 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 18434: /* module 72 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 18435: /* module 72 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 18436: /* module 72 call 4 */
        return STR_ME_CHANGE_KEY;
    case 18437: /* module 72 call 5 */
        return STR_ME_SET_PRIME;
    case 18438: /* module 72 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 18688: /* module 73 call 0 */
        return STR_ME_ADD_MEMBER;
    case 18689: /* module 73 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 18690: /* module 73 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 18691: /* module 73 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 18692: /* module 73 call 4 */
        return STR_ME_CHANGE_KEY;
    case 18693: /* module 73 call 5 */
        return STR_ME_SET_PRIME;
    case 18694: /* module 73 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 18944: /* module 74 call 0 */
        return STR_ME_ADD_MEMBER;
    case 18945: /* module 74 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 18946: /* module 74 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 18947: /* module 74 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 18948: /* module 74 call 4 */
        return STR_ME_CHANGE_KEY;
    case 18949: /* module 74 call 5 */
        return STR_ME_SET_PRIME;
    case 18950: /* module 74 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 19200: /* module 75 call 0 */
        return STR_ME_ADD_MEMBER;
    case 19201: /* module 75 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 19202: /* module 75 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 19203: /* module 75 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 19204: /* module 75 call 4 */
        return STR_ME_CHANGE_KEY;
    case 19205: /* module 75 call 5 */
        return STR_ME_SET_PRIME;
    case 19206: /* module 75 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 23045: /* module 90 call 5 */
        return STR_ME_SET_BRIDGE_TOKEN_STATUS;
    case 23296: /* module 91 call 0 */
        return STR_ME_TOGGLE_PALLET;
    case 23297: /* module 91 call 1 */
        return STR_ME_TOGGLE_CALL;
    case 23554: /* module 92 call 2 */
        return STR_ME_SET_POOL_COOL_DOWN_DURATION;
    case 23555: /* module 92 call 3 */
        return STR_ME_RESET_POOL_UNLOCK_HEIGHT;
    case 24067: /* module 94 call 3 */
        return STR_ME_SET_MINIMUM_DEPOSIT;
    case 5122: /* module 20 call 2 */
        return STR_ME_AUTHORIZE_UPGRADE;
    case 5123: /* module 20 call 3 */
        return STR_ME_ENACT_AUTHORIZED_UPGRADE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V13(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return 1;
    case 514: /* module 2 call 2 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1028: /* module 4 call 4 */
        return 2;
    case 8192: /* module 32 call 0 */
        return 2;
    case 8193: /* module 32 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 256: /* module 1 call 0 */
        return 1;
    case 768: /* module 3 call 0 */
        return 2;
    case 769: /* module 3 call 1 */
        return 6;
    case 770: /* module 3 call 2 */
        return 5;
    case 771: /* module 3 call 3 */
        return 4;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 3;
    case 1537: /* module 6 call 1 */
        return 4;
    case 1538: /* module 6 call 2 */
        return 2;
    case 1539: /* module 6 call 3 */
        return 3;
    case 1540: /* module 6 call 4 */
        return 3;
    case 1541: /* module 6 call 5 */
        return 3;
    case 1542: /* module 6 call 6 */
        return 3;
    case 1543: /* module 6 call 7 */
        return 4;
    case 1544: /* module 6 call 8 */
        return 2;
    case 1545: /* module 6 call 9 */
        return 2;
    case 1546: /* module 6 call 10 */
        return 1;
    case 1547: /* module 6 call 11 */
        return 1;
    case 1548: /* module 6 call 12 */
        return 2;
    case 1549: /* module 6 call 13 */
        return 4;
    case 1550: /* module 6 call 14 */
        return 4;
    case 1551: /* module 6 call 15 */
        return 1;
    case 1552: /* module 6 call 16 */
        return 5;
    case 1553: /* module 6 call 17 */
        return 1;
    case 1554: /* module 6 call 18 */
        return 8;
    case 1555: /* module 6 call 19 */
        return 3;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 3;
    case 1558: /* module 6 call 22 */
        return 4;
    case 1559: /* module 6 call 23 */
        return 1;
    case 1560: /* module 6 call 24 */
        return 2;
    case 1798: /* module 7 call 6 */
        return 2;
    case 1799: /* module 7 call 7 */
        return 2;
    case 1800: /* module 7 call 8 */
        return 2;
    case 2048: /* module 8 call 0 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 0;
    case 2052: /* module 8 call 4 */
        return 2;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 2;
    case 2055: /* module 8 call 7 */
        return 2;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2061: /* module 8 call 13 */
        return 1;
    case 2062: /* module 8 call 14 */
        return 0;
    case 2560: /* module 10 call 0 */
        return 1;
    case 2561: /* module 10 call 1 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 1;
    case 2563: /* module 10 call 3 */
        return 2;
    case 2816: /* module 11 call 0 */
        return 2;
    case 2817: /* module 11 call 1 */
        return 2;
    case 2819: /* module 11 call 3 */
        return 1;
    case 2820: /* module 11 call 4 */
        return 1;
    case 2821: /* module 11 call 5 */
        return 1;
    case 2822: /* module 11 call 6 */
        return 1;
    case 2823: /* module 11 call 7 */
        return 3;
    case 2824: /* module 11 call 8 */
        return 1;
    case 2825: /* module 11 call 9 */
        return 1;
    case 2826: /* module 11 call 10 */
        return 1;
    case 2827: /* module 11 call 11 */
        return 3;
    case 2828: /* module 11 call 12 */
        return 0;
    case 2829: /* module 11 call 13 */
        return 0;
    case 2830: /* module 11 call 14 */
        return 1;
    case 2831: /* module 11 call 15 */
        return 1;
    case 2832: /* module 11 call 16 */
        return 1;
    case 2833: /* module 11 call 17 */
        return 1;
    case 2834: /* module 11 call 18 */
        return 2;
    case 2835: /* module 11 call 19 */
        return 1;
    case 2836: /* module 11 call 20 */
        return 1;
    case 2837: /* module 11 call 21 */
        return 2;
    case 2838: /* module 11 call 22 */
        return 2;
    case 2840: /* module 11 call 24 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 3;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 3;
    case 3075: /* module 12 call 3 */
        return 3;
    case 3076: /* module 12 call 4 */
        return 4;
    case 3077: /* module 12 call 5 */
        return 1;
    case 3328: /* module 13 call 0 */
        return 3;
    case 3329: /* module 13 call 1 */
        return 2;
    case 3330: /* module 13 call 2 */
        return 3;
    case 3331: /* module 13 call 3 */
        return 3;
    case 3332: /* module 13 call 4 */
        return 4;
    case 3333: /* module 13 call 5 */
        return 1;
    case 3584: /* module 14 call 0 */
        return 2;
    case 3585: /* module 14 call 1 */
        return 1;
    case 3586: /* module 14 call 2 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 1;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4099: /* module 16 call 3 */
        return 1;
    case 5633: /* module 22 call 1 */
        return 0;
    case 5634: /* module 22 call 2 */
        return 0;
    case 5635: /* module 22 call 3 */
        return 1;
    case 5636: /* module 22 call 4 */
        return 1;
    case 5637: /* module 22 call 5 */
        return 1;
    case 5638: /* module 22 call 6 */
        return 1;
    case 5639: /* module 22 call 7 */
        return 1;
    case 5640: /* module 22 call 8 */
        return 1;
    case 7936: /* module 31 call 0 */
        return 1;
    case 7937: /* module 31 call 1 */
        return 1;
    case 7938: /* module 31 call 2 */
        return 1;
    case 7939: /* module 31 call 3 */
        return 0;
    case 7940: /* module 31 call 4 */
        return 0;
    case 11776: /* module 46 call 0 */
        return 0;
    case 11779: /* module 46 call 3 */
        return 1;
    case 12805: /* module 50 call 5 */
        return 1;
    case 12806: /* module 50 call 6 */
        return 2;
    case 12807: /* module 50 call 7 */
        return 3;
    case 12808: /* module 50 call 8 */
        return 0;
    case 12809: /* module 50 call 9 */
        return 1;
    case 12820: /* module 50 call 20 */
        return 3;
    case 13316: /* module 52 call 4 */
        return 1;
    case 15360: /* module 60 call 0 */
        return 1;
    case 15361: /* module 60 call 1 */
        return 1;
    case 15362: /* module 60 call 2 */
        return 1;
    case 15363: /* module 60 call 3 */
        return 1;
    case 15369: /* module 60 call 9 */
        return 2;
    case 15371: /* module 60 call 11 */
        return 1;
    case 15373: /* module 60 call 13 */
        return 1;
    case 15374: /* module 60 call 14 */
        return 1;
    case 15375: /* module 60 call 15 */
        return 0;
    case 15377: /* module 60 call 17 */
        return 2;
    case 17920: /* module 70 call 0 */
        return 1;
    case 17921: /* module 70 call 1 */
        return 1;
    case 17922: /* module 70 call 2 */
        return 2;
    case 17923: /* module 70 call 3 */
        return 1;
    case 17924: /* module 70 call 4 */
        return 1;
    case 17925: /* module 70 call 5 */
        return 1;
    case 17926: /* module 70 call 6 */
        return 0;
    case 18176: /* module 71 call 0 */
        return 1;
    case 18177: /* module 71 call 1 */
        return 1;
    case 18178: /* module 71 call 2 */
        return 2;
    case 18179: /* module 71 call 3 */
        return 1;
    case 18180: /* module 71 call 4 */
        return 1;
    case 18181: /* module 71 call 5 */
        return 1;
    case 18182: /* module 71 call 6 */
        return 0;
    case 18432: /* module 72 call 0 */
        return 1;
    case 18433: /* module 72 call 1 */
        return 1;
    case 18434: /* module 72 call 2 */
        return 2;
    case 18435: /* module 72 call 3 */
        return 1;
    case 18436: /* module 72 call 4 */
        return 1;
    case 18437: /* module 72 call 5 */
        return 1;
    case 18438: /* module 72 call 6 */
        return 0;
    case 18688: /* module 73 call 0 */
        return 1;
    case 18689: /* module 73 call 1 */
        return 1;
    case 18690: /* module 73 call 2 */
        return 2;
    case 18691: /* module 73 call 3 */
        return 1;
    case 18692: /* module 73 call 4 */
        return 1;
    case 18693: /* module 73 call 5 */
        return 1;
    case 18694: /* module 73 call 6 */
        return 0;
    case 18944: /* module 74 call 0 */
        return 1;
    case 18945: /* module 74 call 1 */
        return 1;
    case 18946: /* module 74 call 2 */
        return 2;
    case 18947: /* module 74 call 3 */
        return 1;
    case 18948: /* module 74 call 4 */
        return 1;
    case 18949: /* module 74 call 5 */
        return 1;
    case 18950: /* module 74 call 6 */
        return 0;
    case 19200: /* module 75 call 0 */
        return 1;
    case 19201: /* module 75 call 1 */
        return 1;
    case 19202: /* module 75 call 2 */
        return 2;
    case 19203: /* module 75 call 3 */
        return 1;
    case 19204: /* module 75 call 4 */
        return 1;
    case 19205: /* module 75 call 5 */
        return 1;
    case 19206: /* module 75 call 6 */
        return 0;
    case 23045: /* module 90 call 5 */
        return 2;
    case 23296: /* module 91 call 0 */
        return 1;
    case 23297: /* module 91 call 1 */
        return 2;
    case 23554: /* module 92 call 2 */
        return 4;
    case 23555: /* module 92 call 3 */
        return 3;
    case 24067: /* module 94 call 3 */
        return 2;
    case 5122: /* module 20 call 2 */
        return 1;
    case 5123: /* module 20 call 3 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V13(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 514: /* module 2 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_admin;
        case 2:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_is_sufficient;
        case 3:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_witness;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_source;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        case 4:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_min_balance;
        case 6:
            return STR_IT_is_sufficient;
        case 7:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_destination;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_allow_burn;
        default:
            return NULL;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2822: /* module 11 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2823: /* module 11 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 2824: /* module 11 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2825: /* module 11 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2826: /* module 11 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 2827: /* module 11 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 2828: /* module 11 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2829: /* module 11 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2830: /* module 11 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2831: /* module 11 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2832: /* module 11 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2833: /* module 11 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2834: /* module 11 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 2835: /* module 11 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 2836: /* module 11 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2837: /* module 11 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2838: /* module 11 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2840: /* module 11 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5640: /* module 22 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bond;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target_account;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_supply_reward_per_block;
        case 2:
            return STR_IT_borrow_reward_per_block;
        default:
            return NULL;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 12809: /* module 50 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        default:
            return NULL;
        }
    case 12820: /* module 50 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receiver;
        case 1:
            return STR_IT_asset_id;
        case 2:
            return STR_IT_redeem_amount;
        default:
            return NULL;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_flag;
        default:
            return NULL;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_liquid_amount;
        default:
            return NULL;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reserve_factor;
        default:
            return NULL;
        }
    case 15363: /* module 60 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_cap;
        default:
            return NULL;
        }
    case 15369: /* module 60 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 15371: /* module 60 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 15373: /* module 60 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 15374: /* module 60 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offset;
        default:
            return NULL;
        }
    case 15375: /* module 60 call 15 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 15377: /* module 60 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 17920: /* module 70 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 17921: /* module 70 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 17922: /* module 70 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 17923: /* module 70 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 17924: /* module 70 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 17926: /* module 70 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18176: /* module 71 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18177: /* module 71 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18178: /* module 71 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 18179: /* module 71 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 18180: /* module 71 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 18181: /* module 71 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18182: /* module 71 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 18435: /* module 72 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 18436: /* module 72 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 18437: /* module 72 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18438: /* module 72 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18944: /* module 74 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18945: /* module 74 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18946: /* module 74 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 18947: /* module 74 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 18948: /* module 74 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 18949: /* module 74 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 18950: /* module 74 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 19200: /* module 75 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 19201: /* module 75 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 19202: /* module 75 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 19203: /* module 75 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 19204: /* module 75 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 19205: /* module 75 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 19206: /* module 75 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 23045: /* module 90 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_token_id;
        case 1:
            return STR_IT_enable;
        default:
            return NULL;
        }
    case 23296: /* module 91 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pallet_idx;
        default:
            return NULL;
        }
    case 23297: /* module 91 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pallet_idx;
        case 1:
            return STR_IT_call_idx;
        default:
            return NULL;
        }
    case 23554: /* module 92 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_reward_asset;
        case 2:
            return STR_IT_lock_duration;
        case 3:
            return STR_IT_cool_down_duration;
        default:
            return NULL;
        }
    case 23555: /* module 92 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_reward_asset;
        case 2:
            return STR_IT_lock_duration;
        default:
            return NULL;
        }
    case 24067: /* module 94 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_minimum_deposit;
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V13(
    pd_Method_V13_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V13 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V13.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 514: /* module 2 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V13 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V13.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->nested.balances_transfer_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V13 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V13 - source */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->nested.balances_force_transfer_V13.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->nested.balances_force_transfer_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V13 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->nested.balances_transfer_keep_alive_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V13 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.balances_transfer_all_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V13 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V13.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V13 - keys */;
            return _toStringKeys_V13(
                &m->basic.session_set_keys_V13.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V13 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V13.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V13 - ratio */;
            return _toStringPerbill_V13(
                &m->nested.system_fill_block_V13.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V13 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V13.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V13 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V13.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V13 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V13.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V13 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V13.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V13 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V13.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V13 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V13.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V13 - other_signatories */;
            return _toStringVecAccountId_V13(
                &m->nested.multisig_as_multi_threshold_1_V13.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V13 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V13.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V13 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V13.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V13 - other_signatories */;
            return _toStringVecAccountId_V13(
                &m->nested.multisig_as_multi_V13.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V13 - maybe_timepoint */;
            return _toStringOptionTimepoint_V13(
                &m->nested.multisig_as_multi_V13.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V13 - call */;
            return _toStringOpaqueCall_V13(
                &m->nested.multisig_as_multi_V13.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V13 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V13.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V13 - max_weight */;
            return _toStringWeight_V13(
                &m->nested.multisig_as_multi_V13.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V13 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V13.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V13 - other_signatories */;
            return _toStringVecAccountId_V13(
                &m->nested.multisig_approve_as_multi_V13.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V13 - maybe_timepoint */;
            return _toStringOptionTimepoint_V13(
                &m->nested.multisig_approve_as_multi_V13.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V13 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V13.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V13 - max_weight */;
            return _toStringWeight_V13(
                &m->nested.multisig_approve_as_multi_V13.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V13 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V13.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V13 - other_signatories */;
            return _toStringVecAccountId_V13(
                &m->nested.multisig_cancel_as_multi_V13.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V13 - timepoint */;
            return _toStringTimepoint_V13(
                &m->nested.multisig_cancel_as_multi_V13.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V13 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V13.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V13 - who */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->nested.balances_set_balance_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V13 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V13.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V13 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V13.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V13 - who */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.balances_force_unreserve_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V13 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* assets_create_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_create_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_create_V13 - admin */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_create_V13.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_create_V13 - min_balance */;
            return _toStringBalance(
                &m->basic.assets_create_V13.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_create_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V13 - owner */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_create_V13.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V13 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_create_V13.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V13 - min_balance */;
            return _toStringCompactu128(
                &m->basic.assets_force_create_V13.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* assets_destroy_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_destroy_V13 - witness */;
            return _toStringDestroyWitness_V13(
                &m->basic.assets_destroy_V13.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* assets_mint_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_mint_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V13 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_mint_V13.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_mint_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* assets_burn_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_burn_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V13 - who */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_burn_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_burn_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V13 - target */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_transfer_V13.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_transfer_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0: /* assets_transfer_keep_alive_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_keep_alive_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_keep_alive_V13 - target */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_transfer_keep_alive_V13.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_keep_alive_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_transfer_keep_alive_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_transfer_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V13 - source */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_transfer_V13.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_transfer_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_force_transfer_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_freeze_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V13 - who */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_freeze_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_thaw_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V13 - who */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_thaw_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* assets_freeze_asset_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_freeze_asset_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* assets_thaw_asset_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_thaw_asset_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_ownership_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V13 - owner */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_transfer_ownership_V13.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_team_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V13 - issuer */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_set_team_V13.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V13 - admin */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_set_team_V13.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V13 - freezer */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_set_team_V13.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* assets_set_metadata_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_metadata_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_metadata_V13 - name */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V13.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_metadata_V13 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V13.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_metadata_V13 - decimals */;
            return _toStringu8(
                &m->basic.assets_set_metadata_V13.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* assets_clear_metadata_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_clear_metadata_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0: /* assets_force_set_metadata_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_set_metadata_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_set_metadata_V13 - name */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V13.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_set_metadata_V13 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V13.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_set_metadata_V13 - decimals */;
            return _toStringu8(
                &m->basic.assets_force_set_metadata_V13.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_set_metadata_V13 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_set_metadata_V13.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* assets_force_clear_metadata_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_clear_metadata_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* assets_force_asset_status_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_asset_status_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_asset_status_V13 - owner */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_asset_status_V13.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_asset_status_V13 - issuer */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_asset_status_V13.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_asset_status_V13 - admin */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_asset_status_V13.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_asset_status_V13 - freezer */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_asset_status_V13.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assets_force_asset_status_V13 - min_balance */;
            return _toStringCompactu128(
                &m->basic.assets_force_asset_status_V13.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assets_force_asset_status_V13 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V13.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* assets_force_asset_status_V13 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V13.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* assets_approve_transfer_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_approve_transfer_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_approve_transfer_V13 - delegate */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_approve_transfer_V13.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_approve_transfer_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_approve_transfer_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_cancel_approval_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V13 - delegate */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_cancel_approval_V13.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* assets_force_cancel_approval_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_cancel_approval_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_cancel_approval_V13 - owner */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_cancel_approval_V13.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_cancel_approval_V13 - delegate */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_force_cancel_approval_V13.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* assets_transfer_approved_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_approved_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_approved_V13 - owner */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_transfer_approved_V13.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_approved_V13 - destination */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.assets_transfer_approved_V13.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_transfer_approved_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_transfer_approved_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* assets_touch_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_touch_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* assets_refund_V13 - id */;
            return _toStringCompactu32(
                &m->basic.assets_refund_V13.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_V13 - allow_burn */;
            return _toStringbool(
                &m->basic.assets_refund_V13.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V13 - real */;
            return _toStringAccountId_V13(
                &m->basic.proxy_announce_V13.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V13 - call_hash */;
            return _toStringCallHashOf_V13(
                &m->basic.proxy_announce_V13.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V13 - real */;
            return _toStringAccountId_V13(
                &m->basic.proxy_remove_announcement_V13.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V13 - call_hash */;
            return _toStringCallHashOf_V13(
                &m->basic.proxy_remove_announcement_V13.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V13 - delegate */;
            return _toStringAccountId_V13(
                &m->basic.proxy_reject_announcement_V13.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V13 - call_hash */;
            return _toStringCallHashOf_V13(
                &m->basic.proxy_reject_announcement_V13.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V13 - account */;
            return _toStringAccountId_V13(
                &m->basic.identity_add_registrar_V13.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V13 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V13.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V13 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V13.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V13 - reg_index */;
            return _toStringRegistrarIndex_V13(
                &m->basic.identity_cancel_request_V13.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V13 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V13 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V13.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V13 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.identity_set_account_id_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V13 - target */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.identity_kill_identity_V13.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V13 - sub */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.identity_remove_sub_V13.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V13 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V13.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V13 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V13.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V13 - weight */;
            return _toStringWeight_V13(
                &m->basic.sudo_sudo_unchecked_weight_V13.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V13 - new_ */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.sudo_set_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V13 - who */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.sudo_sudo_as_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V13 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V13.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V13 - amount */;
            return _toStringCompactBalance(
                &m->basic.democracy_propose_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V13 - proposal */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V13 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V13.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V13 - ref_index */;
            return _toStringReferendumIndex_V13(
                &m->basic.democracy_emergency_cancel_V13.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2822: /* module 11 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2823: /* module 11 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V13 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V13.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V13 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V13.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2824: /* module 11 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2825: /* module 11 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V13 - ref_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_referendum_V13.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2826: /* module 11 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V13 - which */;
            return _toStringReferendumIndex_V13(
                &m->basic.democracy_cancel_queued_V13.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2827: /* module 11 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V13 - to */;
            return _toStringAccountId_V13(
                &m->basic.democracy_delegate_V13.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V13 - conviction */;
            return _toStringConviction_V13(
                &m->basic.democracy_delegate_V13.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V13 - balance */;
            return _toStringBalance(
                &m->basic.democracy_delegate_V13.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2828: /* module 11 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2829: /* module 11 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2830: /* module 11 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V13 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V13.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2831: /* module 11 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V13 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V13.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2832: /* module 11 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V13 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V13.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2833: /* module 11 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V13 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V13.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2834: /* module 11 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V13 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V13.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2835: /* module 11 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V13 - target */;
            return _toStringAccountId_V13(
                &m->basic.democracy_unlock_V13.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2836: /* module 11 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V13 - index */;
            return _toStringReferendumIndex_V13(
                &m->basic.democracy_remove_vote_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2837: /* module 11 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V13 - target */;
            return _toStringAccountId_V13(
                &m->basic.democracy_remove_other_vote_V13.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V13 - index */;
            return _toStringReferendumIndex_V13(
                &m->basic.democracy_remove_other_vote_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2838: /* module 11 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V13 - index */;
            return _toStringReferendumIndex_V13(
                &m->basic.democracy_enact_proposal_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2840: /* module 11 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V13 - prop_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_proposal_V13.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* generalcouncil_set_members_V13 - new_members */;
            return _toStringVecAccountId_V13(
                &m->basic.generalcouncil_set_members_V13.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_set_members_V13 - prime */;
            return _toStringOptionAccountId_V13(
                &m->basic.generalcouncil_set_members_V13.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_set_members_V13 - old_count */;
            return _toStringMemberCount_V13(
                &m->basic.generalcouncil_set_members_V13.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* generalcouncil_execute_V13 - proposal */;
            return _toStringProposal(
                &m->basic.generalcouncil_execute_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_execute_V13 - length_bound */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_execute_V13.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* generalcouncil_propose_V13 - threshold */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_propose_V13.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_propose_V13 - proposal */;
            return _toStringProposal(
                &m->basic.generalcouncil_propose_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_propose_V13 - length_bound */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_propose_V13.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* generalcouncil_vote_V13 - proposal */;
            return _toStringHash(
                &m->basic.generalcouncil_vote_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_vote_V13 - index */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_vote_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_vote_V13 - approve */;
            return _toStringbool(
                &m->basic.generalcouncil_vote_V13.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* generalcouncil_close_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.generalcouncil_close_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_close_V13 - index */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_close_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_close_V13 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.generalcouncil_close_V13.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* generalcouncil_close_V13 - length_bound */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_close_V13.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0: /* generalcouncil_disapprove_proposal_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.generalcouncil_disapprove_proposal_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V13 - new_members */;
            return _toStringVecAccountId_V13(
                &m->basic.technicalcommittee_set_members_V13.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V13 - prime */;
            return _toStringOptionAccountId_V13(
                &m->basic.technicalcommittee_set_members_V13.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V13 - old_count */;
            return _toStringMemberCount_V13(
                &m->basic.technicalcommittee_set_members_V13.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V13 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V13 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V13.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V13 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V13.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V13 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V13 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V13.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V13 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V13.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V13 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V13 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V13.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V13 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V13.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V13 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.technicalcommittee_close_V13.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V13 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V13.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V13 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V13.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V13 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V13 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.treasury_propose_spend_V13.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V13 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V13.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V13 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V13.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V13 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V13.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V13 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V13.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V13 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V13.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V13 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V13.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_suspend_threshold_V13 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_suspend_threshold_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_drop_threshold_V13 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_drop_threshold_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_resume_threshold_V13 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_resume_threshold_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_threshold_weight_V13 - new_ */;
            return _toStringWeight_V13(
                &m->basic.xcmpqueue_update_threshold_weight_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_weight_restrict_decay_V13 - new_ */;
            return _toStringWeight_V13(
                &m->basic.xcmpqueue_update_weight_restrict_decay_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5640: /* module 22 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_xcmp_max_individual_weight_V13 - new_ */;
            return _toStringWeight_V13(
                &m->basic.xcmpqueue_update_xcmp_max_individual_weight_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_invulnerables_V13 - new_ */;
            return _toStringVecAccountId_V13(
                &m->basic.collatorselection_set_invulnerables_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_desired_candidates_V13 - max */;
            return _toStringu32(
                &m->basic.collatorselection_set_desired_candidates_V13.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_candidacy_bond_V13 - bond */;
            return _toStringBalance(
                &m->basic.collatorselection_set_candidacy_bond_V13.bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_claim_for_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.vesting_claim_for_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0: /* loans_add_reward_V13 - amount */;
            return _toStringBalance(
                &m->basic.loans_add_reward_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0: /* loans_withdraw_missing_reward_V13 - target_account */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.loans_withdraw_missing_reward_V13.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_withdraw_missing_reward_V13 - amount */;
            return _toStringBalance(
                &m->basic.loans_withdraw_missing_reward_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0: /* loans_update_market_reward_speed_V13 - asset_id */;
            return _toStringAssetIdOfT_V13(
                &m->basic.loans_update_market_reward_speed_V13.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_update_market_reward_speed_V13 - supply_reward_per_block */;
            return _toStringBalance(
                &m->basic.loans_update_market_reward_speed_V13.supply_reward_per_block,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_update_market_reward_speed_V13 - borrow_reward_per_block */;
            return _toStringBalance(
                &m->basic.loans_update_market_reward_speed_V13.borrow_reward_per_block,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 12809: /* module 50 call 9 */
        switch (itemIdx) {
        case 0: /* loans_claim_reward_for_market_V13 - asset_id */;
            return _toStringAssetIdOfT_V13(
                &m->basic.loans_claim_reward_for_market_V13.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12820: /* module 50 call 20 */
        switch (itemIdx) {
        case 0: /* loans_reduce_incentive_reserves_V13 - receiver */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.loans_reduce_incentive_reserves_V13.receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_reduce_incentive_reserves_V13 - asset_id */;
            return _toStringAssetIdOfT_V13(
                &m->basic.loans_reduce_incentive_reserves_V13.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_reduce_incentive_reserves_V13 - redeem_amount */;
            return _toStringCompactu128(
                &m->basic.loans_reduce_incentive_reserves_V13.redeem_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloans_set_vrf_V13 - flag */;
            return _toStringbool(
                &m->basic.crowdloans_set_vrf_V13.flag,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0: /* liquidstaking_stake_V13 - amount */;
            return _toStringCompactu128(
                &m->basic.liquidstaking_stake_V13.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0: /* liquidstaking_unstake_V13 - liquid_amount */;
            return _toStringCompactu128(
                &m->basic.liquidstaking_unstake_V13.liquid_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0: /* liquidstaking_update_reserve_factor_V13 - reserve_factor */;
            return _toStringRatio_V13(
                &m->basic.liquidstaking_update_reserve_factor_V13.reserve_factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15363: /* module 60 call 3 */
        switch (itemIdx) {
        case 0: /* liquidstaking_update_staking_ledger_cap_V13 - cap */;
            return _toStringCompactu128(
                &m->basic.liquidstaking_update_staking_ledger_cap_V13.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15369: /* module 60 call 9 */
        switch (itemIdx) {
        case 0: /* liquidstaking_nominate_V13 - derivative_index */;
            return _toStringDerivativeIndex_V13(
                &m->basic.liquidstaking_nominate_V13.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_nominate_V13 - targets */;
            return _toStringVecAccountId_V13(
                &m->basic.liquidstaking_nominate_V13.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15371: /* module 60 call 11 */
        switch (itemIdx) {
        case 0: /* liquidstaking_claim_for_V13 - dest */;
            return _toStringLookupasStaticLookupSource_V13(
                &m->basic.liquidstaking_claim_for_V13.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15373: /* module 60 call 13 */
        switch (itemIdx) {
        case 0: /* liquidstaking_force_set_current_era_V13 - era */;
            return _toStringEraIndex_V13(
                &m->basic.liquidstaking_force_set_current_era_V13.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15374: /* module 60 call 14 */
        switch (itemIdx) {
        case 0: /* liquidstaking_force_advance_era_V13 - offset */;
            return _toStringEraIndex_V13(
                &m->basic.liquidstaking_force_advance_era_V13.offset,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15375: /* module 60 call 15 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 15377: /* module 60 call 17 */
        switch (itemIdx) {
        case 0: /* liquidstaking_set_current_era_V13 - era */;
            return _toStringEraIndex_V13(
                &m->basic.liquidstaking_set_current_era_V13.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_set_current_era_V13 - proof */;
            return _toStringVecVecu8(
                &m->basic.liquidstaking_set_current_era_V13.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17920: /* module 70 call 0 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_add_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.generalcouncilmembership_add_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17921: /* module 70 call 1 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_remove_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.generalcouncilmembership_remove_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17922: /* module 70 call 2 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_swap_member_V13 - remove */;
            return _toStringAccountId_V13(
                &m->basic.generalcouncilmembership_swap_member_V13.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncilmembership_swap_member_V13 - add */;
            return _toStringAccountId_V13(
                &m->basic.generalcouncilmembership_swap_member_V13.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17923: /* module 70 call 3 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_reset_members_V13 - members */;
            return _toStringVecAccountId_V13(
                &m->basic.generalcouncilmembership_reset_members_V13.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17924: /* module 70 call 4 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_change_key_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.generalcouncilmembership_change_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_set_prime_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.generalcouncilmembership_set_prime_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17926: /* module 70 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18176: /* module 71 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_add_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.technicalcommitteemembership_add_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18177: /* module 71 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_remove_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.technicalcommitteemembership_remove_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18178: /* module 71 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_swap_member_V13 - remove */;
            return _toStringAccountId_V13(
                &m->basic.technicalcommitteemembership_swap_member_V13.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_swap_member_V13 - add */;
            return _toStringAccountId_V13(
                &m->basic.technicalcommitteemembership_swap_member_V13.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18179: /* module 71 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_reset_members_V13 - members */;
            return _toStringVecAccountId_V13(
                &m->basic.technicalcommitteemembership_reset_members_V13.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18180: /* module 71 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_change_key_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.technicalcommitteemembership_change_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18181: /* module 71 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_set_prime_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.technicalcommitteemembership_set_prime_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18182: /* module 71 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0: /* oraclemembership_add_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.oraclemembership_add_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0: /* oraclemembership_remove_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.oraclemembership_remove_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        case 0: /* oraclemembership_swap_member_V13 - remove */;
            return _toStringAccountId_V13(
                &m->basic.oraclemembership_swap_member_V13.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* oraclemembership_swap_member_V13 - add */;
            return _toStringAccountId_V13(
                &m->basic.oraclemembership_swap_member_V13.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18435: /* module 72 call 3 */
        switch (itemIdx) {
        case 0: /* oraclemembership_reset_members_V13 - members */;
            return _toStringVecAccountId_V13(
                &m->basic.oraclemembership_reset_members_V13.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18436: /* module 72 call 4 */
        switch (itemIdx) {
        case 0: /* oraclemembership_change_key_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.oraclemembership_change_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18437: /* module 72 call 5 */
        switch (itemIdx) {
        case 0: /* oraclemembership_set_prime_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.oraclemembership_set_prime_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18438: /* module 72 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_add_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.liquidstakingagentsmembership_add_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_remove_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.liquidstakingagentsmembership_remove_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_swap_member_V13 - remove */;
            return _toStringAccountId_V13(
                &m->basic.liquidstakingagentsmembership_swap_member_V13.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstakingagentsmembership_swap_member_V13 - add */;
            return _toStringAccountId_V13(
                &m->basic.liquidstakingagentsmembership_swap_member_V13.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_reset_members_V13 - members */;
            return _toStringVecAccountId_V13(
                &m->basic.liquidstakingagentsmembership_reset_members_V13.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_change_key_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.liquidstakingagentsmembership_change_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_set_prime_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.liquidstakingagentsmembership_set_prime_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18944: /* module 74 call 0 */
        switch (itemIdx) {
        case 0: /* bridgemembership_add_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.bridgemembership_add_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18945: /* module 74 call 1 */
        switch (itemIdx) {
        case 0: /* bridgemembership_remove_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.bridgemembership_remove_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18946: /* module 74 call 2 */
        switch (itemIdx) {
        case 0: /* bridgemembership_swap_member_V13 - remove */;
            return _toStringAccountId_V13(
                &m->basic.bridgemembership_swap_member_V13.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridgemembership_swap_member_V13 - add */;
            return _toStringAccountId_V13(
                &m->basic.bridgemembership_swap_member_V13.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18947: /* module 74 call 3 */
        switch (itemIdx) {
        case 0: /* bridgemembership_reset_members_V13 - members */;
            return _toStringVecAccountId_V13(
                &m->basic.bridgemembership_reset_members_V13.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18948: /* module 74 call 4 */
        switch (itemIdx) {
        case 0: /* bridgemembership_change_key_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.bridgemembership_change_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18949: /* module 74 call 5 */
        switch (itemIdx) {
        case 0: /* bridgemembership_set_prime_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.bridgemembership_set_prime_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18950: /* module 74 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 19200: /* module 75 call 0 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_add_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_add_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19201: /* module 75 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_remove_member_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_remove_member_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19202: /* module 75 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_swap_member_V13 - remove */;
            return _toStringAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_swap_member_V13.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloansautomatorsmembership_swap_member_V13 - add */;
            return _toStringAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_swap_member_V13.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19203: /* module 75 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_reset_members_V13 - members */;
            return _toStringVecAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_reset_members_V13.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19204: /* module 75 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_change_key_V13 - new_ */;
            return _toStringAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_change_key_V13.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19205: /* module 75 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_set_prime_V13 - who */;
            return _toStringAccountId_V13(
                &m->basic.crowdloansautomatorsmembership_set_prime_V13.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19206: /* module 75 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 23045: /* module 90 call 5 */
        switch (itemIdx) {
        case 0: /* bridge_set_bridge_token_status_V13 - bridge_token_id */;
            return _toStringCurrencyId_V13(
                &m->basic.bridge_set_bridge_token_status_V13.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_set_bridge_token_status_V13 - enable */;
            return _toStringbool(
                &m->basic.bridge_set_bridge_token_status_V13.enable,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23296: /* module 91 call 0 */
        switch (itemIdx) {
        case 0: /* emergencyshutdown_toggle_pallet_V13 - pallet_idx */;
            return _toStringu8(
                &m->basic.emergencyshutdown_toggle_pallet_V13.pallet_idx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23297: /* module 91 call 1 */
        switch (itemIdx) {
        case 0: /* emergencyshutdown_toggle_call_V13 - pallet_idx */;
            return _toStringu8(
                &m->basic.emergencyshutdown_toggle_call_V13.pallet_idx,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* emergencyshutdown_toggle_call_V13 - call_idx */;
            return _toStringu8(
                &m->basic.emergencyshutdown_toggle_call_V13.call_idx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23554: /* module 92 call 2 */
        switch (itemIdx) {
        case 0: /* farming_set_pool_cool_down_duration_V13 - asset */;
            return _toStringAssetIdOfT_V13(
                &m->basic.farming_set_pool_cool_down_duration_V13.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_set_pool_cool_down_duration_V13 - reward_asset */;
            return _toStringAssetIdOfT_V13(
                &m->basic.farming_set_pool_cool_down_duration_V13.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_set_pool_cool_down_duration_V13 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_set_pool_cool_down_duration_V13.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_set_pool_cool_down_duration_V13 - cool_down_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_set_pool_cool_down_duration_V13.cool_down_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23555: /* module 92 call 3 */
        switch (itemIdx) {
        case 0: /* farming_reset_pool_unlock_height_V13 - asset */;
            return _toStringAssetIdOfT_V13(
                &m->basic.farming_reset_pool_unlock_height_V13.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_reset_pool_unlock_height_V13 - reward_asset */;
            return _toStringAssetIdOfT_V13(
                &m->basic.farming_reset_pool_unlock_height_V13.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_reset_pool_unlock_height_V13 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_reset_pool_unlock_height_V13.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 24067: /* module 94 call 3 */
        switch (itemIdx) {
        case 0: /* streaming_set_minimum_deposit_V13 - asset_id */;
            return _toStringAssetIdOfT_V13(
                &m->basic.streaming_set_minimum_deposit_V13.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* streaming_set_minimum_deposit_V13 - minimum_deposit */;
            return _toStringBalance(
                &m->basic.streaming_set_minimum_deposit_V13.minimum_deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* parachainsystem_authorize_upgrade_V13 - code_hash */;
            return _toStringHash(
                &m->basic.parachainsystem_authorize_upgrade_V13.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* parachainsystem_enact_authorized_upgrade_V13 - code */;
            return _toStringVecu8(
                &m->basic.parachainsystem_enact_authorized_upgrade_V13.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V13(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V13(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: // Timestamp:Set
    case 512: // Utility:Batch
    case 514: // Utility:Batch all
    case 1028: // Balances:Transfer all
    case 1029: // Balances:Force unreserve
    case 1536: // Assets:Create
    case 1537: // Assets:Force create
    case 1538: // Assets:Destroy
    case 1539: // Assets:Mint
    case 1540: // Assets:Burn
    case 1541: // Assets:Transfer
    case 1542: // Assets:Transfer keep alive
    case 1543: // Assets:Force transfer
    case 1544: // Assets:Freeze
    case 1545: // Assets:Thaw
    case 1546: // Assets:Freeze asset
    case 1547: // Assets:Thaw asset
    case 1548: // Assets:Transfer ownership
    case 1549: // Assets:Set team
    case 1550: // Assets:Set metadata
    case 1551: // Assets:Clear metadata
    case 1552: // Assets:Force set metadata
    case 1553: // Assets:Force clear metadata
    case 1554: // Assets:Force asset status
    case 1555: // Assets:Approve transfer
    case 1556: // Assets:Cancel approval
    case 1557: // Assets:Force cancel approval
    case 1558: // Assets:Transfer approved
    case 1559: // Assets:Touch
    case 1560: // Assets:Refund
    case 1798: // Proxy:Announce
    case 1799: // Proxy:Remove announcement
    case 1800: // Proxy:Reject announcement
    case 2048: // Identity:Add registrar
    case 2051: // Identity:Clear identity
    case 2052: // Identity:Request judgement
    case 2053: // Identity:Cancel request
    case 2054: // Identity:Set fee
    case 2055: // Identity:Set account id
    case 2058: // Identity:Kill identity
    case 2061: // Identity:Remove sub
    case 2062: // Identity:Quit sub
    case 2560: // Sudo:Sudo
    case 2561: // Sudo:Sudo unchecked weight
    case 2562: // Sudo:Set key
    case 2563: // Sudo:Sudo as
    case 2816: // Democracy:Propose
    case 2817: // Democracy:Second
    case 2819: // Democracy:Emergency cancel
    case 2820: // Democracy:External propose
    case 2821: // Democracy:External propose majority
    case 2822: // Democracy:External propose default
    case 2823: // Democracy:Fast track
    case 2824: // Democracy:Veto external
    case 2825: // Democracy:Cancel referendum
    case 2826: // Democracy:Cancel queued
    case 2827: // Democracy:Delegate
    case 2828: // Democracy:Undelegate
    case 2829: // Democracy:Clear public proposals
    case 2830: // Democracy:Note preimage
    case 2831: // Democracy:Note preimage operational
    case 2832: // Democracy:Note imminent preimage
    case 2833: // Democracy:Note imminent preimage operational
    case 2834: // Democracy:Reap preimage
    case 2835: // Democracy:Unlock
    case 2836: // Democracy:Remove vote
    case 2837: // Democracy:Remove other vote
    case 2838: // Democracy:Enact proposal
    case 2840: // Democracy:Cancel proposal
    case 3072: // GeneralCouncil:Set members
    case 3073: // GeneralCouncil:Execute
    case 3074: // GeneralCouncil:Propose
    case 3075: // GeneralCouncil:Vote
    case 3076: // GeneralCouncil:Close
    case 3077: // GeneralCouncil:Disapprove proposal
    case 3328: // TechnicalCommittee:Set members
    case 3329: // TechnicalCommittee:Execute
    case 3330: // TechnicalCommittee:Propose
    case 3331: // TechnicalCommittee:Vote
    case 3332: // TechnicalCommittee:Close
    case 3333: // TechnicalCommittee:Disapprove proposal
    case 3584: // Treasury:Propose spend
    case 3585: // Treasury:Reject proposal
    case 3586: // Treasury:Approve proposal
    case 4096: // Preimage:Note preimage
    case 4097: // Preimage:Unnote preimage
    case 4098: // Preimage:Request preimage
    case 4099: // Preimage:Unrequest preimage
    case 5633: // XcmpQueue:Suspend xcm execution
    case 5634: // XcmpQueue:Resume xcm execution
    case 5635: // XcmpQueue:Update suspend threshold
    case 5636: // XcmpQueue:Update drop threshold
    case 5637: // XcmpQueue:Update resume threshold
    case 5638: // XcmpQueue:Update threshold weight
    case 5639: // XcmpQueue:Update weight restrict decay
    case 5640: // XcmpQueue:Update xcmp max individual weight
    case 7936: // CollatorSelection:Set invulnerables
    case 7937: // CollatorSelection:Set desired candidates
    case 7938: // CollatorSelection:Set candidacy bond
    case 7939: // CollatorSelection:Register as candidate
    case 7940: // CollatorSelection:Leave intent
    case 8192: // Session:Set keys
    case 8193: // Session:Purge keys
    case 11776: // Vesting:Claim
    case 11779: // Vesting:Claim for
    case 12805: // Loans:Add reward
    case 12806: // Loans:Withdraw missing reward
    case 12807: // Loans:Update market reward speed
    case 12808: // Loans:Claim reward
    case 12809: // Loans:Claim reward for market
    case 12820: // Loans:Reduce incentive reserves
    case 13316: // Crowdloans:Set vrf
    case 15360: // LiquidStaking:Stake
    case 15361: // LiquidStaking:Unstake
    case 15362: // LiquidStaking:Update reserve factor
    case 15363: // LiquidStaking:Update staking ledger cap
    case 15369: // LiquidStaking:Nominate
    case 15371: // LiquidStaking:Claim for
    case 15373: // LiquidStaking:Force set current era
    case 15374: // LiquidStaking:Force advance era
    case 15375: // LiquidStaking:Force matching
    case 15377: // LiquidStaking:Set current era
    case 17920: // GeneralCouncilMembership:Add member
    case 17921: // GeneralCouncilMembership:Remove member
    case 17922: // GeneralCouncilMembership:Swap member
    case 17923: // GeneralCouncilMembership:Reset members
    case 17924: // GeneralCouncilMembership:Change key
    case 17925: // GeneralCouncilMembership:Set prime
    case 17926: // GeneralCouncilMembership:Clear prime
    case 18176: // TechnicalCommitteeMembership:Add member
    case 18177: // TechnicalCommitteeMembership:Remove member
    case 18178: // TechnicalCommitteeMembership:Swap member
    case 18179: // TechnicalCommitteeMembership:Reset members
    case 18180: // TechnicalCommitteeMembership:Change key
    case 18181: // TechnicalCommitteeMembership:Set prime
    case 18182: // TechnicalCommitteeMembership:Clear prime
    case 18432: // OracleMembership:Add member
    case 18433: // OracleMembership:Remove member
    case 18434: // OracleMembership:Swap member
    case 18435: // OracleMembership:Reset members
    case 18436: // OracleMembership:Change key
    case 18437: // OracleMembership:Set prime
    case 18438: // OracleMembership:Clear prime
    case 18688: // LiquidStakingAgentsMembership:Add member
    case 18689: // LiquidStakingAgentsMembership:Remove member
    case 18690: // LiquidStakingAgentsMembership:Swap member
    case 18691: // LiquidStakingAgentsMembership:Reset members
    case 18692: // LiquidStakingAgentsMembership:Change key
    case 18693: // LiquidStakingAgentsMembership:Set prime
    case 18694: // LiquidStakingAgentsMembership:Clear prime
    case 18944: // BridgeMembership:Add member
    case 18945: // BridgeMembership:Remove member
    case 18946: // BridgeMembership:Swap member
    case 18947: // BridgeMembership:Reset members
    case 18948: // BridgeMembership:Change key
    case 18949: // BridgeMembership:Set prime
    case 18950: // BridgeMembership:Clear prime
    case 19200: // CrowdloansAutomatorsMembership:Add member
    case 19201: // CrowdloansAutomatorsMembership:Remove member
    case 19202: // CrowdloansAutomatorsMembership:Swap member
    case 19203: // CrowdloansAutomatorsMembership:Reset members
    case 19204: // CrowdloansAutomatorsMembership:Change key
    case 19205: // CrowdloansAutomatorsMembership:Set prime
    case 19206: // CrowdloansAutomatorsMembership:Clear prime
    case 23045: // Bridge:Set bridge token status
    case 23296: // EmergencyShutdown:Toggle pallet
    case 23297: // EmergencyShutdown:Toggle call
    case 23554: // Farming:Set pool cool down duration
    case 23555: // Farming:Reset pool unlock height
    case 24067: // Streaming:Set minimum deposit
    case 5122: // ParachainSystem:Authorize upgrade
    case 5123: // ParachainSystem:Enact authorized upgrade
        return false;
    default:
        return true;
    }
}
