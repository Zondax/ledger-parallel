/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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

#include "substrate_dispatch_V17.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_utility_batch_V17(
    parser_context_t* c, pd_utility_batch_V17_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V17(
    parser_context_t* c, pd_utility_batch_all_V17_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V17(
    parser_context_t* c, pd_utility_force_batch_V17_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V17(
    parser_context_t* c, pd_balances_transfer_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V17(
    parser_context_t* c, pd_balances_force_transfer_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V17(
    parser_context_t* c, pd_balances_transfer_keep_alive_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V17(
    parser_context_t* c, pd_balances_transfer_all_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V17(
    parser_context_t* c, pd_session_set_keys_V17_t* m)
{
    CHECK_ERROR(_readKeys_V17(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V17(
    parser_context_t* c, pd_session_purge_keys_V17_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V17(
    parser_context_t* c, pd_system_fill_block_V17_t* m)
{
    CHECK_ERROR(_readPerbill_V17(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V17(
    parser_context_t* c, pd_system_remark_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V17(
    parser_context_t* c, pd_system_set_heap_pages_V17_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V17(
    parser_context_t* c, pd_system_set_code_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V17(
    parser_context_t* c, pd_system_set_code_without_checks_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V17(
    parser_context_t* c, pd_system_remark_with_event_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V17(
    parser_context_t* c, pd_timestamp_set_V17_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V17(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V17(
    parser_context_t* c, pd_multisig_as_multi_V17_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V17(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V17(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V17(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V17(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V17(
    parser_context_t* c, pd_multisig_approve_as_multi_V17_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V17(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V17(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V17(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V17(
    parser_context_t* c, pd_multisig_cancel_as_multi_V17_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V17(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V17(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V17(
    parser_context_t* c, pd_balances_set_balance_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V17(
    parser_context_t* c, pd_balances_force_unreserve_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_create_V17(
    parser_context_t* c, pd_assets_create_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V17(
    parser_context_t* c, pd_assets_force_create_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactu128(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_V17(
    parser_context_t* c, pd_assets_destroy_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readDestroyWitness_V17(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V17(
    parser_context_t* c, pd_assets_mint_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->beneficiary))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V17(
    parser_context_t* c, pd_assets_burn_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V17(
    parser_context_t* c, pd_assets_transfer_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->target))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_keep_alive_V17(
    parser_context_t* c, pd_assets_transfer_keep_alive_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->target))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V17(
    parser_context_t* c, pd_assets_force_transfer_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V17(
    parser_context_t* c, pd_assets_freeze_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V17(
    parser_context_t* c, pd_assets_thaw_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_asset_V17(
    parser_context_t* c, pd_assets_freeze_asset_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_asset_V17(
    parser_context_t* c, pd_assets_thaw_asset_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V17(
    parser_context_t* c, pd_assets_transfer_ownership_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V17(
    parser_context_t* c, pd_assets_set_team_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_metadata_V17(
    parser_context_t* c, pd_assets_set_metadata_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_clear_metadata_V17(
    parser_context_t* c, pd_assets_clear_metadata_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_set_metadata_V17(
    parser_context_t* c, pd_assets_force_set_metadata_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_clear_metadata_V17(
    parser_context_t* c, pd_assets_force_clear_metadata_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_asset_status_V17(
    parser_context_t* c, pd_assets_force_asset_status_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->freezer))
    CHECK_ERROR(_readCompactu128(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_approve_transfer_V17(
    parser_context_t* c, pd_assets_approve_transfer_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->delegate))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V17(
    parser_context_t* c, pd_assets_cancel_approval_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_cancel_approval_V17(
    parser_context_t* c, pd_assets_force_cancel_approval_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_approved_V17(
    parser_context_t* c, pd_assets_transfer_approved_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->destination))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_V17(
    parser_context_t* c, pd_assets_touch_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_V17(
    parser_context_t* c, pd_assets_refund_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V17(
    parser_context_t* c, pd_proxy_proxy_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V17(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V17(
    parser_context_t* c, pd_proxy_add_proxy_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V17(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V17(
    parser_context_t* c, pd_proxy_remove_proxy_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V17(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V17(
    parser_context_t* c, pd_proxy_remove_proxies_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V17(
    parser_context_t* c, pd_proxy_anonymous_V17_t* m)
{
    CHECK_ERROR(_readProxyType_V17(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V17(
    parser_context_t* c, pd_proxy_kill_anonymous_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V17(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V17(
    parser_context_t* c, pd_proxy_announce_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V17(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V17(
    parser_context_t* c, pd_proxy_remove_announcement_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V17(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V17(
    parser_context_t* c, pd_proxy_reject_announcement_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V17(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V17(
    parser_context_t* c, pd_proxy_proxy_announced_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V17(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V17(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V17(
    parser_context_t* c, pd_identity_add_registrar_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V17(
    parser_context_t* c, pd_identity_clear_identity_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V17(
    parser_context_t* c, pd_identity_request_judgement_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V17(
    parser_context_t* c, pd_identity_cancel_request_V17_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V17(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V17(
    parser_context_t* c, pd_identity_set_fee_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V17(
    parser_context_t* c, pd_identity_set_account_id_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V17(
    parser_context_t* c, pd_identity_kill_identity_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V17(
    parser_context_t* c, pd_identity_remove_sub_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V17(
    parser_context_t* c, pd_identity_quit_sub_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V17(
    parser_context_t* c, pd_democracy_propose_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V17(
    parser_context_t* c, pd_democracy_second_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V17(
    parser_context_t* c, pd_democracy_emergency_cancel_V17_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V17(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V17(
    parser_context_t* c, pd_democracy_external_propose_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V17(
    parser_context_t* c, pd_democracy_external_propose_majority_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V17(
    parser_context_t* c, pd_democracy_external_propose_default_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V17(
    parser_context_t* c, pd_democracy_fast_track_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V17(
    parser_context_t* c, pd_democracy_veto_external_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V17(
    parser_context_t* c, pd_democracy_cancel_referendum_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V17(
    parser_context_t* c, pd_democracy_cancel_queued_V17_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V17(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V17(
    parser_context_t* c, pd_democracy_delegate_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->to))
    CHECK_ERROR(_readConviction_V17(c, &m->conviction))
    CHECK_ERROR(_readBalance(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V17(
    parser_context_t* c, pd_democracy_undelegate_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V17(
    parser_context_t* c, pd_democracy_clear_public_proposals_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V17(
    parser_context_t* c, pd_democracy_note_preimage_V17_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V17(
    parser_context_t* c, pd_democracy_note_preimage_operational_V17_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V17(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V17_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V17(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V17_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V17(
    parser_context_t* c, pd_democracy_reap_preimage_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V17(
    parser_context_t* c, pd_democracy_unlock_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V17(
    parser_context_t* c, pd_democracy_remove_vote_V17_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V17(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V17(
    parser_context_t* c, pd_democracy_remove_other_vote_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V17(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V17(
    parser_context_t* c, pd_democracy_enact_proposal_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V17(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V17(
    parser_context_t* c, pd_democracy_cancel_proposal_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_set_members_V17(
    parser_context_t* c, pd_generalcouncil_set_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V17(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V17(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_execute_V17(
    parser_context_t* c, pd_generalcouncil_execute_V17_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_propose_V17(
    parser_context_t* c, pd_generalcouncil_propose_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_vote_V17(
    parser_context_t* c, pd_generalcouncil_vote_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_close_V17(
    parser_context_t* c, pd_generalcouncil_close_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncil_disapprove_proposal_V17(
    parser_context_t* c, pd_generalcouncil_disapprove_proposal_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V17(
    parser_context_t* c, pd_technicalcommittee_set_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V17(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V17(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V17(
    parser_context_t* c, pd_technicalcommittee_execute_V17_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V17(
    parser_context_t* c, pd_technicalcommittee_propose_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V17(
    parser_context_t* c, pd_technicalcommittee_vote_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V17(
    parser_context_t* c, pd_technicalcommittee_close_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V17(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V17(
    parser_context_t* c, pd_treasury_propose_spend_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V17(
    parser_context_t* c, pd_treasury_reject_proposal_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V17(
    parser_context_t* c, pd_treasury_approve_proposal_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_spend_V17(
    parser_context_t* c, pd_treasury_spend_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_remove_approval_V17(
    parser_context_t* c, pd_treasury_remove_approval_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V17(
    parser_context_t* c, pd_preimage_note_preimage_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V17(
    parser_context_t* c, pd_preimage_unnote_preimage_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V17(
    parser_context_t* c, pd_preimage_request_preimage_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V17(
    parser_context_t* c, pd_preimage_unrequest_preimage_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_service_overweight_V17(
    parser_context_t* c, pd_xcmpqueue_service_overweight_V17_t* m)
{
    CHECK_ERROR(_readOverweightIndex_V17(c, &m->index))
    CHECK_ERROR(_readWeight_V17(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_suspend_xcm_execution_V17(
    parser_context_t* c, pd_xcmpqueue_suspend_xcm_execution_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_resume_xcm_execution_V17(
    parser_context_t* c, pd_xcmpqueue_resume_xcm_execution_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_suspend_threshold_V17(
    parser_context_t* c, pd_xcmpqueue_update_suspend_threshold_V17_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_drop_threshold_V17(
    parser_context_t* c, pd_xcmpqueue_update_drop_threshold_V17_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_resume_threshold_V17(
    parser_context_t* c, pd_xcmpqueue_update_resume_threshold_V17_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_threshold_weight_V17(
    parser_context_t* c, pd_xcmpqueue_update_threshold_weight_V17_t* m)
{
    CHECK_ERROR(_readWeight_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_weight_restrict_decay_V17(
    parser_context_t* c, pd_xcmpqueue_update_weight_restrict_decay_V17_t* m)
{
    CHECK_ERROR(_readWeight_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_xcmp_max_individual_weight_V17(
    parser_context_t* c, pd_xcmpqueue_update_xcmp_max_individual_weight_V17_t* m)
{
    CHECK_ERROR(_readWeight_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dmpqueue_service_overweight_V17(
    parser_context_t* c, pd_dmpqueue_service_overweight_V17_t* m)
{
    CHECK_ERROR(_readOverweightIndex_V17(c, &m->index))
    CHECK_ERROR(_readWeight_V17(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_invulnerables_V17(
    parser_context_t* c, pd_collatorselection_set_invulnerables_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_desired_candidates_V17(
    parser_context_t* c, pd_collatorselection_set_desired_candidates_V17_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_candidacy_bond_V17(
    parser_context_t* c, pd_collatorselection_set_candidacy_bond_V17_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->bond))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_as_candidate_V17(
    parser_context_t* c, pd_collatorselection_register_as_candidate_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_leave_intent_V17(
    parser_context_t* c, pd_collatorselection_leave_intent_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xtokens_transfer_V17(
    parser_context_t* c, pd_xtokens_transfer_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->currency_id))
    CHECK_ERROR(_readu128(c, &m->amount))
    CHECK_ERROR(_readBoxVersionedMultiLocation_V17(c, &m->dest))
    CHECK_ERROR(_readWeight_V17(c, &m->dest_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_V17(
    parser_context_t* c, pd_vesting_claim_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V17(
    parser_context_t* c, pd_vesting_vested_transfer_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readVestingScheduleOf_V17(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_update_vesting_schedules_V17(
    parser_context_t* c, pd_vesting_update_vesting_schedules_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->who))
    CHECK_ERROR(_readVecVestingScheduleOf_V17(c, &m->vesting_schedules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_for_V17(
    parser_context_t* c, pd_vesting_claim_for_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_add_market_V17(
    parser_context_t* c, pd_loans_add_market_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readMarketBalanceOfT_V17(c, &m->market))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_activate_market_V17(
    parser_context_t* c, pd_loans_activate_market_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_update_rate_model_V17(
    parser_context_t* c, pd_loans_update_rate_model_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readInterestRateModel_V17(c, &m->rate_model))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_update_market_V17(
    parser_context_t* c, pd_loans_update_market_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readOptionRatio_V17(c, &m->collateral_factor))
    CHECK_ERROR(_readOptionRatio_V17(c, &m->liquidation_threshold))
    CHECK_ERROR(_readOptionRatio_V17(c, &m->reserve_factor))
    CHECK_ERROR(_readOptionRatio_V17(c, &m->close_factor))
    CHECK_ERROR(_readOptionRatio_V17(c, &m->liquidate_incentive_reserved_factor))
    CHECK_ERROR(_readOptionRate_V17(c, &m->liquidate_incentive))
    CHECK_ERROR(_readOptionBalance(c, &m->supply_cap))
    CHECK_ERROR(_readOptionBalance(c, &m->borrow_cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_force_update_market_V17(
    parser_context_t* c, pd_loans_force_update_market_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readMarketBalanceOfT_V17(c, &m->market))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_add_reward_V17(
    parser_context_t* c, pd_loans_add_reward_V17_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_withdraw_missing_reward_V17(
    parser_context_t* c, pd_loans_withdraw_missing_reward_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->target_account))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_update_market_reward_speed_V17(
    parser_context_t* c, pd_loans_update_market_reward_speed_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readOptionBalance(c, &m->supply_reward_per_block))
    CHECK_ERROR(_readOptionBalance(c, &m->borrow_reward_per_block))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_claim_reward_V17(
    parser_context_t* c, pd_loans_claim_reward_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_claim_reward_for_market_V17(
    parser_context_t* c, pd_loans_claim_reward_for_market_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_mint_V17(
    parser_context_t* c, pd_loans_mint_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->mint_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_redeem_V17(
    parser_context_t* c, pd_loans_redeem_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->redeem_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_redeem_all_V17(
    parser_context_t* c, pd_loans_redeem_all_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_borrow_V17(
    parser_context_t* c, pd_loans_borrow_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->borrow_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_repay_borrow_V17(
    parser_context_t* c, pd_loans_repay_borrow_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->repay_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_repay_borrow_all_V17(
    parser_context_t* c, pd_loans_repay_borrow_all_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_collateral_asset_V17(
    parser_context_t* c, pd_loans_collateral_asset_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readbool(c, &m->enable))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_liquidate_borrow_V17(
    parser_context_t* c, pd_loans_liquidate_borrow_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->borrower))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->liquidation_asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->repay_amount))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->collateral_asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_add_reserves_V17(
    parser_context_t* c, pd_loans_add_reserves_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->payer))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->add_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_reduce_reserves_V17(
    parser_context_t* c, pd_loans_reduce_reserves_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->receiver))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->reduce_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_reduce_incentive_reserves_V17(
    parser_context_t* c, pd_loans_reduce_incentive_reserves_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->receiver))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->redeem_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_loans_update_liquidation_free_collateral_V17(
    parser_context_t* c, pd_loans_update_liquidation_free_collateral_V17_t* m)
{
    CHECK_ERROR(_readVecAssetIdOf_V17(c, &m->collaterals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_prices_set_price_V17(
    parser_context_t* c, pd_prices_set_price_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->asset_id))
    CHECK_ERROR(_readPrice_V17(c, &m->price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_prices_reset_price_V17(
    parser_context_t* c, pd_prices_reset_price_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->asset_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_create_vault_V17(
    parser_context_t* c, pd_crowdloans_create_vault_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->ctoken))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    CHECK_ERROR(_readContributionStrategy_V17(c, &m->contribution_strategy))
    CHECK_ERROR(_readCompactBalance(c, &m->cap))
    CHECK_ERROR(_readBlockNumber(c, &m->end_block))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_update_vault_V17(
    parser_context_t* c, pd_crowdloans_update_vault_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readOptionBalance(c, &m->cap))
    CHECK_ERROR(_readOptionBlockNumber(c, &m->end_block))
    CHECK_ERROR(_readOptionContributionStrategy_V17(c, &m->contribution_strategy))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_open_V17(
    parser_context_t* c, pd_crowdloans_open_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_contribute_V17(
    parser_context_t* c, pd_crowdloans_contribute_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readVecu8(c, &m->referral_code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_set_vrf_V17(
    parser_context_t* c, pd_crowdloans_set_vrf_V17_t* m)
{
    CHECK_ERROR(_readbool(c, &m->flag))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_close_V17(
    parser_context_t* c, pd_crowdloans_close_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_reopen_V17(
    parser_context_t* c, pd_crowdloans_reopen_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_auction_succeeded_V17(
    parser_context_t* c, pd_crowdloans_auction_succeeded_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_auction_failed_V17(
    parser_context_t* c, pd_crowdloans_auction_failed_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_claim_V17(
    parser_context_t* c, pd_crowdloans_claim_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_claim_for_V17(
    parser_context_t* c, pd_crowdloans_claim_for_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_withdraw_V17(
    parser_context_t* c, pd_crowdloans_withdraw_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_withdraw_for_V17(
    parser_context_t* c, pd_crowdloans_withdraw_for_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_redeem_V17(
    parser_context_t* c, pd_crowdloans_redeem_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_slot_expired_V17(
    parser_context_t* c, pd_crowdloans_slot_expired_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_migrate_pending_V17(
    parser_context_t* c, pd_crowdloans_migrate_pending_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_refund_V17(
    parser_context_t* c, pd_crowdloans_refund_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_dissolve_vault_V17(
    parser_context_t* c, pd_crowdloans_dissolve_vault_V17_t* m)
{
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloans_refund_for_V17(
    parser_context_t* c, pd_crowdloans_refund_for_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    CHECK_ERROR(_readParaId_V17(c, &m->crowdloan))
    CHECK_ERROR(_readChildStorageKind_V17(c, &m->kind))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_start))
    CHECK_ERROR(_readLeasePeriod_V17(c, &m->lease_end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_stake_V17(
    parser_context_t* c, pd_liquidstaking_stake_V17_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_unstake_V17(
    parser_context_t* c, pd_liquidstaking_unstake_V17_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->liquid_amount))
    CHECK_ERROR(_readUnstakeProvider_V17(c, &m->unstake_provider))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_update_reserve_factor_V17(
    parser_context_t* c, pd_liquidstaking_update_reserve_factor_V17_t* m)
{
    CHECK_ERROR(_readRatio_V17(c, &m->reserve_factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_update_staking_ledger_cap_V17(
    parser_context_t* c, pd_liquidstaking_update_staking_ledger_cap_V17_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_bond_V17(
    parser_context_t* c, pd_liquidstaking_bond_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V17(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_bond_extra_V17(
    parser_context_t* c, pd_liquidstaking_bond_extra_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_unbond_V17(
    parser_context_t* c, pd_liquidstaking_unbond_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_rebond_V17(
    parser_context_t* c, pd_liquidstaking_rebond_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_withdraw_unbonded_V17(
    parser_context_t* c, pd_liquidstaking_withdraw_unbonded_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_nominate_V17(
    parser_context_t* c, pd_liquidstaking_nominate_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readVecAccountId_V17(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_claim_for_V17(
    parser_context_t* c, pd_liquidstaking_claim_for_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_set_era_start_block_V17(
    parser_context_t* c, pd_liquidstaking_force_set_era_start_block_V17_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_set_current_era_V17(
    parser_context_t* c, pd_liquidstaking_force_set_current_era_V17_t* m)
{
    CHECK_ERROR(_readEraIndex_V17(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_advance_era_V17(
    parser_context_t* c, pd_liquidstaking_force_advance_era_V17_t* m)
{
    CHECK_ERROR(_readEraIndex_V17(c, &m->offset))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_matching_V17(
    parser_context_t* c, pd_liquidstaking_force_matching_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_force_set_staking_ledger_V17(
    parser_context_t* c, pd_liquidstaking_force_set_staking_ledger_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readStakingLedgerAccountIdBalanceOfT_V17(c, &m->staking_ledger))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_set_current_era_V17(
    parser_context_t* c, pd_liquidstaking_set_current_era_V17_t* m)
{
    CHECK_ERROR(_readEraIndex_V17(c, &m->era))
    CHECK_ERROR(_readVecVecu8(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_set_staking_ledger_V17(
    parser_context_t* c, pd_liquidstaking_set_staking_ledger_V17_t* m)
{
    CHECK_ERROR(_readDerivativeIndex_V17(c, &m->derivative_index))
    CHECK_ERROR(_readStakingLedgerAccountIdBalanceOfT_V17(c, &m->staking_ledger))
    CHECK_ERROR(_readVecVecu8(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_reduce_reserves_V17(
    parser_context_t* c, pd_liquidstaking_reduce_reserves_V17_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->receiver))
    CHECK_ERROR(_readCompactu128(c, &m->reduce_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstaking_cancel_unstake_V17(
    parser_context_t* c, pd_liquidstaking_cancel_unstake_V17_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_add_member_V17(
    parser_context_t* c, pd_generalcouncilmembership_add_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_remove_member_V17(
    parser_context_t* c, pd_generalcouncilmembership_remove_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_swap_member_V17(
    parser_context_t* c, pd_generalcouncilmembership_swap_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->remove))
    CHECK_ERROR(_readAccountId_V17(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_reset_members_V17(
    parser_context_t* c, pd_generalcouncilmembership_reset_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_change_key_V17(
    parser_context_t* c, pd_generalcouncilmembership_change_key_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_set_prime_V17(
    parser_context_t* c, pd_generalcouncilmembership_set_prime_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_generalcouncilmembership_clear_prime_V17(
    parser_context_t* c, pd_generalcouncilmembership_clear_prime_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member_V17(
    parser_context_t* c, pd_technicalcommitteemembership_add_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_remove_member_V17(
    parser_context_t* c, pd_technicalcommitteemembership_remove_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member_V17(
    parser_context_t* c, pd_technicalcommitteemembership_swap_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->remove))
    CHECK_ERROR(_readAccountId_V17(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_reset_members_V17(
    parser_context_t* c, pd_technicalcommitteemembership_reset_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_change_key_V17(
    parser_context_t* c, pd_technicalcommitteemembership_change_key_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_set_prime_V17(
    parser_context_t* c, pd_technicalcommitteemembership_set_prime_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_clear_prime_V17(
    parser_context_t* c, pd_technicalcommitteemembership_clear_prime_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_add_member_V17(
    parser_context_t* c, pd_oraclemembership_add_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_remove_member_V17(
    parser_context_t* c, pd_oraclemembership_remove_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_swap_member_V17(
    parser_context_t* c, pd_oraclemembership_swap_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->remove))
    CHECK_ERROR(_readAccountId_V17(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_reset_members_V17(
    parser_context_t* c, pd_oraclemembership_reset_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_change_key_V17(
    parser_context_t* c, pd_oraclemembership_change_key_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_set_prime_V17(
    parser_context_t* c, pd_oraclemembership_set_prime_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_oraclemembership_clear_prime_V17(
    parser_context_t* c, pd_oraclemembership_clear_prime_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_add_member_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_add_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_remove_member_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_remove_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_swap_member_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_swap_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->remove))
    CHECK_ERROR(_readAccountId_V17(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_reset_members_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_reset_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_change_key_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_change_key_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_set_prime_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_set_prime_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_liquidstakingagentsmembership_clear_prime_V17(
    parser_context_t* c, pd_liquidstakingagentsmembership_clear_prime_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_add_member_V17(
    parser_context_t* c, pd_bridgemembership_add_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_remove_member_V17(
    parser_context_t* c, pd_bridgemembership_remove_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_swap_member_V17(
    parser_context_t* c, pd_bridgemembership_swap_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->remove))
    CHECK_ERROR(_readAccountId_V17(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_reset_members_V17(
    parser_context_t* c, pd_bridgemembership_reset_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_change_key_V17(
    parser_context_t* c, pd_bridgemembership_change_key_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_set_prime_V17(
    parser_context_t* c, pd_bridgemembership_set_prime_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgemembership_clear_prime_V17(
    parser_context_t* c, pd_bridgemembership_clear_prime_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_add_member_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_add_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_remove_member_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_remove_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_swap_member_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_swap_member_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->remove))
    CHECK_ERROR(_readAccountId_V17(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_reset_members_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_reset_members_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId_V17(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_change_key_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_change_key_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_set_prime_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_set_prime_V17_t* m)
{
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloansautomatorsmembership_clear_prime_V17(
    parser_context_t* c, pd_crowdloansautomatorsmembership_clear_prime_V17_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_amm_add_liquidity_V17(
    parser_context_t* c, pd_amm_add_liquidity_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfAssetIdOf_V17(c, &m->pair))
    CHECK_ERROR(_readBalanceOfBalanceOf_V17(c, &m->desired_amounts))
    CHECK_ERROR(_readBalanceOfBalanceOf_V17(c, &m->minimum_amounts))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_amm_remove_liquidity_V17(
    parser_context_t* c, pd_amm_remove_liquidity_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfAssetIdOf_V17(c, &m->pair))
    CHECK_ERROR(_readCompactu128(c, &m->liquidity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_amm_create_pool_V17(
    parser_context_t* c, pd_amm_create_pool_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfAssetIdOf_V17(c, &m->pair))
    CHECK_ERROR(_readBalanceOfBalanceOf_V17(c, &m->liquidity_amounts))
    CHECK_ERROR(_readAccountId_V17(c, &m->lptoken_receiver))
    CHECK_ERROR(_readAssetIdOf_V17(c, &m->lp_token_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ammroute_swap_exact_tokens_for_tokens_V17(
    parser_context_t* c, pd_ammroute_swap_exact_tokens_for_tokens_V17_t* m)
{
    CHECK_ERROR(_readVecAssetIdOf_V17(c, &m->route))
    CHECK_ERROR(_readCompactu128(c, &m->amount_in))
    CHECK_ERROR(_readCompactu128(c, &m->min_amount_out))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ammroute_swap_tokens_for_exact_tokens_V17(
    parser_context_t* c, pd_ammroute_swap_tokens_for_exact_tokens_V17_t* m)
{
    CHECK_ERROR(_readVecAssetIdOf_V17(c, &m->route))
    CHECK_ERROR(_readCompactu128(c, &m->amount_out))
    CHECK_ERROR(_readCompactu128(c, &m->max_amount_in))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_currencyadapter_force_set_lock_V17(
    parser_context_t* c, pd_currencyadapter_force_set_lock_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_currencyadapter_force_remove_lock_V17(
    parser_context_t* c, pd_currencyadapter_force_remove_lock_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAccountId_V17(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_register_chain_V17(
    parser_context_t* c, pd_bridge_register_chain_V17_t* m)
{
    CHECK_ERROR(_readChainId_V17(c, &m->chain_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unregister_chain_V17(
    parser_context_t* c, pd_bridge_unregister_chain_V17_t* m)
{
    CHECK_ERROR(_readChainId_V17(c, &m->chain_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_register_bridge_token_V17(
    parser_context_t* c, pd_bridge_register_bridge_token_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readBridgeToken_V17(c, &m->bridge_token))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unregister_bridge_token_V17(
    parser_context_t* c, pd_bridge_unregister_bridge_token_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_set_bridge_token_fee_V17(
    parser_context_t* c, pd_bridge_set_bridge_token_fee_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    CHECK_ERROR(_readBalance(c, &m->new_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_set_bridge_token_status_V17(
    parser_context_t* c, pd_bridge_set_bridge_token_status_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    CHECK_ERROR(_readbool(c, &m->enable))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_set_bridge_token_cap_V17(
    parser_context_t* c, pd_bridge_set_bridge_token_cap_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    CHECK_ERROR(_readBridgeType_V17(c, &m->bridge_type))
    CHECK_ERROR(_readBalance(c, &m->new_cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_clean_cap_accumulated_value_V17(
    parser_context_t* c, pd_bridge_clean_cap_accumulated_value_V17_t* m)
{
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    CHECK_ERROR(_readBridgeType_V17(c, &m->bridge_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_teleport_V17(
    parser_context_t* c, pd_bridge_teleport_V17_t* m)
{
    CHECK_ERROR(_readChainId_V17(c, &m->dest_id))
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    CHECK_ERROR(_readTeleAccount_V17(c, &m->to))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_materialize_V17(
    parser_context_t* c, pd_bridge_materialize_V17_t* m)
{
    CHECK_ERROR(_readChainId_V17(c, &m->src_id))
    CHECK_ERROR(_readChainNonce_V17(c, &m->src_nonce))
    CHECK_ERROR(_readCurrencyId_V17(c, &m->bridge_token_id))
    CHECK_ERROR(_readAccountId_V17(c, &m->to))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readbool(c, &m->favour))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_emergencyshutdown_toggle_pallet_V17(
    parser_context_t* c, pd_emergencyshutdown_toggle_pallet_V17_t* m)
{
    CHECK_ERROR(_readu8(c, &m->pallet_idx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_emergencyshutdown_toggle_call_V17(
    parser_context_t* c, pd_emergencyshutdown_toggle_call_V17_t* m)
{
    CHECK_ERROR(_readu8(c, &m->pallet_idx))
    CHECK_ERROR(_readu8(c, &m->call_idx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_create_V17(
    parser_context_t* c, pd_farming_create_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readBlockNumber(c, &m->cool_down_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_set_pool_status_V17(
    parser_context_t* c, pd_farming_set_pool_status_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readbool(c, &m->is_active))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_set_pool_cool_down_duration_V17(
    parser_context_t* c, pd_farming_set_pool_cool_down_duration_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readBlockNumber(c, &m->cool_down_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_reset_pool_unlock_height_V17(
    parser_context_t* c, pd_farming_reset_pool_unlock_height_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_deposit_V17(
    parser_context_t* c, pd_farming_deposit_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_withdraw_V17(
    parser_context_t* c, pd_farming_withdraw_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_redeem_V17(
    parser_context_t* c, pd_farming_redeem_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_claim_V17(
    parser_context_t* c, pd_farming_claim_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_farming_dispatch_reward_V17(
    parser_context_t* c, pd_farming_dispatch_reward_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset))
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->reward_asset))
    CHECK_ERROR(_readBlockNumber(c, &m->lock_duration))
    CHECK_ERROR(_readLookupasStaticLookupSource_V17(c, &m->payer))
    CHECK_ERROR(_readu128(c, &m->amount))
    CHECK_ERROR(_readBlockNumber(c, &m->reward_duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmhelper_update_xcm_weight_fee_V17(
    parser_context_t* c, pd_xcmhelper_update_xcm_weight_fee_V17_t* m)
{
    CHECK_ERROR(_readXcmCall_V17(c, &m->xcm_call))
    CHECK_ERROR(_readXcmWeightFeeMiscWeightBalanceOfT_V17(c, &m->xcm_weight_fee_misc))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_streaming_set_minimum_deposit_V17(
    parser_context_t* c, pd_streaming_set_minimum_deposit_V17_t* m)
{
    CHECK_ERROR(_readAssetIdOfT_V17(c, &m->asset_id))
    CHECK_ERROR(_readBalance(c, &m->minimum_deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainsystem_authorize_upgrade_V17(
    parser_context_t* c, pd_parachainsystem_authorize_upgrade_V17_t* m)
{
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainsystem_enact_authorized_upgrade_V17(
    parser_context_t* c, pd_parachainsystem_enact_authorized_upgrade_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V17(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V17_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V17(c, &method->basic.utility_batch_V17))
        break;
    case 514: /* module 2 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V17(c, &method->basic.utility_batch_all_V17))
        break;
    case 516: /* module 2 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V17(c, &method->basic.utility_force_batch_V17))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V17(c, &method->nested.balances_transfer_V17))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V17(c, &method->nested.balances_force_transfer_V17))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V17(c, &method->nested.balances_transfer_keep_alive_V17))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V17(c, &method->basic.balances_transfer_all_V17))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V17(c, &method->basic.session_set_keys_V17))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V17(c, &method->basic.session_purge_keys_V17))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V17(c, &method->nested.system_fill_block_V17))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V17(c, &method->nested.system_remark_V17))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V17(c, &method->nested.system_set_heap_pages_V17))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V17(c, &method->nested.system_set_code_V17))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V17(c, &method->nested.system_set_code_without_checks_V17))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V17(c, &method->nested.system_remark_with_event_V17))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V17(c, &method->basic.timestamp_set_V17))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V17(c, &method->nested.multisig_as_multi_threshold_1_V17))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V17(c, &method->nested.multisig_as_multi_V17))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V17(c, &method->nested.multisig_approve_as_multi_V17))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V17(c, &method->nested.multisig_cancel_as_multi_V17))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V17(c, &method->nested.balances_set_balance_V17))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V17(c, &method->basic.balances_force_unreserve_V17))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_assets_create_V17(c, &method->basic.assets_create_V17))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V17(c, &method->basic.assets_force_create_V17))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_assets_destroy_V17(c, &method->basic.assets_destroy_V17))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_assets_mint_V17(c, &method->basic.assets_mint_V17))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_assets_burn_V17(c, &method->basic.assets_burn_V17))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_assets_transfer_V17(c, &method->basic.assets_transfer_V17))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_assets_transfer_keep_alive_V17(c, &method->basic.assets_transfer_keep_alive_V17))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V17(c, &method->basic.assets_force_transfer_V17))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_assets_freeze_V17(c, &method->basic.assets_freeze_V17))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_assets_thaw_V17(c, &method->basic.assets_thaw_V17))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_assets_freeze_asset_V17(c, &method->basic.assets_freeze_asset_V17))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_assets_thaw_asset_V17(c, &method->basic.assets_thaw_asset_V17))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V17(c, &method->basic.assets_transfer_ownership_V17))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_assets_set_team_V17(c, &method->basic.assets_set_team_V17))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_assets_set_metadata_V17(c, &method->basic.assets_set_metadata_V17))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_assets_clear_metadata_V17(c, &method->basic.assets_clear_metadata_V17))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_assets_force_set_metadata_V17(c, &method->basic.assets_force_set_metadata_V17))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_assets_force_clear_metadata_V17(c, &method->basic.assets_force_clear_metadata_V17))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_assets_force_asset_status_V17(c, &method->basic.assets_force_asset_status_V17))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_assets_approve_transfer_V17(c, &method->basic.assets_approve_transfer_V17))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V17(c, &method->basic.assets_cancel_approval_V17))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_assets_force_cancel_approval_V17(c, &method->basic.assets_force_cancel_approval_V17))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_assets_transfer_approved_V17(c, &method->basic.assets_transfer_approved_V17))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_assets_touch_V17(c, &method->basic.assets_touch_V17))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_assets_refund_V17(c, &method->basic.assets_refund_V17))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V17(c, &method->nested.proxy_proxy_V17))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V17(c, &method->basic.proxy_add_proxy_V17))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V17(c, &method->basic.proxy_remove_proxy_V17))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V17(c, &method->basic.proxy_remove_proxies_V17))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V17(c, &method->basic.proxy_anonymous_V17))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V17(c, &method->basic.proxy_kill_anonymous_V17))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V17(c, &method->basic.proxy_announce_V17))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V17(c, &method->basic.proxy_remove_announcement_V17))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V17(c, &method->basic.proxy_reject_announcement_V17))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V17(c, &method->basic.proxy_proxy_announced_V17))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V17(c, &method->basic.identity_add_registrar_V17))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V17(c, &method->basic.identity_clear_identity_V17))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V17(c, &method->basic.identity_request_judgement_V17))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V17(c, &method->basic.identity_cancel_request_V17))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V17(c, &method->basic.identity_set_fee_V17))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V17(c, &method->basic.identity_set_account_id_V17))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V17(c, &method->basic.identity_kill_identity_V17))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V17(c, &method->basic.identity_remove_sub_V17))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V17(c, &method->basic.identity_quit_sub_V17))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V17(c, &method->basic.democracy_propose_V17))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V17(c, &method->basic.democracy_second_V17))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V17(c, &method->basic.democracy_emergency_cancel_V17))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V17(c, &method->basic.democracy_external_propose_V17))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V17(c, &method->basic.democracy_external_propose_majority_V17))
        break;
    case 2822: /* module 11 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V17(c, &method->basic.democracy_external_propose_default_V17))
        break;
    case 2823: /* module 11 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V17(c, &method->basic.democracy_fast_track_V17))
        break;
    case 2824: /* module 11 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V17(c, &method->basic.democracy_veto_external_V17))
        break;
    case 2825: /* module 11 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V17(c, &method->basic.democracy_cancel_referendum_V17))
        break;
    case 2826: /* module 11 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V17(c, &method->basic.democracy_cancel_queued_V17))
        break;
    case 2827: /* module 11 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V17(c, &method->basic.democracy_delegate_V17))
        break;
    case 2828: /* module 11 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V17(c, &method->basic.democracy_undelegate_V17))
        break;
    case 2829: /* module 11 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V17(c, &method->basic.democracy_clear_public_proposals_V17))
        break;
    case 2830: /* module 11 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V17(c, &method->basic.democracy_note_preimage_V17))
        break;
    case 2831: /* module 11 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V17(c, &method->basic.democracy_note_preimage_operational_V17))
        break;
    case 2832: /* module 11 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V17(c, &method->basic.democracy_note_imminent_preimage_V17))
        break;
    case 2833: /* module 11 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V17(c, &method->basic.democracy_note_imminent_preimage_operational_V17))
        break;
    case 2834: /* module 11 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V17(c, &method->basic.democracy_reap_preimage_V17))
        break;
    case 2835: /* module 11 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V17(c, &method->basic.democracy_unlock_V17))
        break;
    case 2836: /* module 11 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V17(c, &method->basic.democracy_remove_vote_V17))
        break;
    case 2837: /* module 11 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V17(c, &method->basic.democracy_remove_other_vote_V17))
        break;
    case 2838: /* module 11 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V17(c, &method->basic.democracy_enact_proposal_V17))
        break;
    case 2840: /* module 11 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V17(c, &method->basic.democracy_cancel_proposal_V17))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_generalcouncil_set_members_V17(c, &method->basic.generalcouncil_set_members_V17))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_generalcouncil_execute_V17(c, &method->basic.generalcouncil_execute_V17))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_generalcouncil_propose_V17(c, &method->basic.generalcouncil_propose_V17))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_generalcouncil_vote_V17(c, &method->basic.generalcouncil_vote_V17))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_generalcouncil_close_V17(c, &method->basic.generalcouncil_close_V17))
        break;
    case 3077: /* module 12 call 5 */
        CHECK_ERROR(_readMethod_generalcouncil_disapprove_proposal_V17(c, &method->basic.generalcouncil_disapprove_proposal_V17))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V17(c, &method->basic.technicalcommittee_set_members_V17))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V17(c, &method->basic.technicalcommittee_execute_V17))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V17(c, &method->basic.technicalcommittee_propose_V17))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V17(c, &method->basic.technicalcommittee_vote_V17))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V17(c, &method->basic.technicalcommittee_close_V17))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V17(c, &method->basic.technicalcommittee_disapprove_proposal_V17))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V17(c, &method->basic.treasury_propose_spend_V17))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V17(c, &method->basic.treasury_reject_proposal_V17))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V17(c, &method->basic.treasury_approve_proposal_V17))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_treasury_spend_V17(c, &method->basic.treasury_spend_V17))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_treasury_remove_approval_V17(c, &method->basic.treasury_remove_approval_V17))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V17(c, &method->basic.preimage_note_preimage_V17))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V17(c, &method->basic.preimage_unnote_preimage_V17))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V17(c, &method->basic.preimage_request_preimage_V17))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V17(c, &method->basic.preimage_unrequest_preimage_V17))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_xcmpqueue_service_overweight_V17(c, &method->basic.xcmpqueue_service_overweight_V17))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_xcmpqueue_suspend_xcm_execution_V17(c, &method->basic.xcmpqueue_suspend_xcm_execution_V17))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_xcmpqueue_resume_xcm_execution_V17(c, &method->basic.xcmpqueue_resume_xcm_execution_V17))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_suspend_threshold_V17(c, &method->basic.xcmpqueue_update_suspend_threshold_V17))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_drop_threshold_V17(c, &method->basic.xcmpqueue_update_drop_threshold_V17))
        break;
    case 5637: /* module 22 call 5 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_resume_threshold_V17(c, &method->basic.xcmpqueue_update_resume_threshold_V17))
        break;
    case 5638: /* module 22 call 6 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_threshold_weight_V17(c, &method->basic.xcmpqueue_update_threshold_weight_V17))
        break;
    case 5639: /* module 22 call 7 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_weight_restrict_decay_V17(c, &method->basic.xcmpqueue_update_weight_restrict_decay_V17))
        break;
    case 5640: /* module 22 call 8 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_xcmp_max_individual_weight_V17(c, &method->basic.xcmpqueue_update_xcmp_max_individual_weight_V17))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_dmpqueue_service_overweight_V17(c, &method->basic.dmpqueue_service_overweight_V17))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_collatorselection_set_invulnerables_V17(c, &method->basic.collatorselection_set_invulnerables_V17))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_collatorselection_set_desired_candidates_V17(c, &method->basic.collatorselection_set_desired_candidates_V17))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_collatorselection_set_candidacy_bond_V17(c, &method->basic.collatorselection_set_candidacy_bond_V17))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_collatorselection_register_as_candidate_V17(c, &method->basic.collatorselection_register_as_candidate_V17))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_collatorselection_leave_intent_V17(c, &method->basic.collatorselection_leave_intent_V17))
        break;
    case 11008: /* module 43 call 0 */
        CHECK_ERROR(_readMethod_xtokens_transfer_V17(c, &method->basic.xtokens_transfer_V17))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_vesting_claim_V17(c, &method->basic.vesting_claim_V17))
        break;
    case 11777: /* module 46 call 1 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V17(c, &method->basic.vesting_vested_transfer_V17))
        break;
    case 11778: /* module 46 call 2 */
        CHECK_ERROR(_readMethod_vesting_update_vesting_schedules_V17(c, &method->basic.vesting_update_vesting_schedules_V17))
        break;
    case 11779: /* module 46 call 3 */
        CHECK_ERROR(_readMethod_vesting_claim_for_V17(c, &method->basic.vesting_claim_for_V17))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_loans_add_market_V17(c, &method->nested.loans_add_market_V17))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_loans_activate_market_V17(c, &method->nested.loans_activate_market_V17))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_loans_update_rate_model_V17(c, &method->nested.loans_update_rate_model_V17))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_loans_update_market_V17(c, &method->nested.loans_update_market_V17))
        break;
    case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_loans_force_update_market_V17(c, &method->nested.loans_force_update_market_V17))
        break;
    case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_loans_add_reward_V17(c, &method->nested.loans_add_reward_V17))
        break;
    case 12806: /* module 50 call 6 */
        CHECK_ERROR(_readMethod_loans_withdraw_missing_reward_V17(c, &method->nested.loans_withdraw_missing_reward_V17))
        break;
    case 12807: /* module 50 call 7 */
        CHECK_ERROR(_readMethod_loans_update_market_reward_speed_V17(c, &method->nested.loans_update_market_reward_speed_V17))
        break;
    case 12808: /* module 50 call 8 */
        CHECK_ERROR(_readMethod_loans_claim_reward_V17(c, &method->nested.loans_claim_reward_V17))
        break;
    case 12809: /* module 50 call 9 */
        CHECK_ERROR(_readMethod_loans_claim_reward_for_market_V17(c, &method->nested.loans_claim_reward_for_market_V17))
        break;
    case 12810: /* module 50 call 10 */
        CHECK_ERROR(_readMethod_loans_mint_V17(c, &method->nested.loans_mint_V17))
        break;
    case 12811: /* module 50 call 11 */
        CHECK_ERROR(_readMethod_loans_redeem_V17(c, &method->nested.loans_redeem_V17))
        break;
    case 12812: /* module 50 call 12 */
        CHECK_ERROR(_readMethod_loans_redeem_all_V17(c, &method->nested.loans_redeem_all_V17))
        break;
    case 12813: /* module 50 call 13 */
        CHECK_ERROR(_readMethod_loans_borrow_V17(c, &method->nested.loans_borrow_V17))
        break;
    case 12814: /* module 50 call 14 */
        CHECK_ERROR(_readMethod_loans_repay_borrow_V17(c, &method->nested.loans_repay_borrow_V17))
        break;
    case 12815: /* module 50 call 15 */
        CHECK_ERROR(_readMethod_loans_repay_borrow_all_V17(c, &method->nested.loans_repay_borrow_all_V17))
        break;
    case 12816: /* module 50 call 16 */
        CHECK_ERROR(_readMethod_loans_collateral_asset_V17(c, &method->nested.loans_collateral_asset_V17))
        break;
    case 12817: /* module 50 call 17 */
        CHECK_ERROR(_readMethod_loans_liquidate_borrow_V17(c, &method->nested.loans_liquidate_borrow_V17))
        break;
    case 12818: /* module 50 call 18 */
        CHECK_ERROR(_readMethod_loans_add_reserves_V17(c, &method->nested.loans_add_reserves_V17))
        break;
    case 12819: /* module 50 call 19 */
        CHECK_ERROR(_readMethod_loans_reduce_reserves_V17(c, &method->nested.loans_reduce_reserves_V17))
        break;
    case 12820: /* module 50 call 20 */
        CHECK_ERROR(_readMethod_loans_reduce_incentive_reserves_V17(c, &method->nested.loans_reduce_incentive_reserves_V17))
        break;
    case 12821: /* module 50 call 21 */
        CHECK_ERROR(_readMethod_loans_update_liquidation_free_collateral_V17(c, &method->nested.loans_update_liquidation_free_collateral_V17))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_prices_set_price_V17(c, &method->basic.prices_set_price_V17))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_prices_reset_price_V17(c, &method->basic.prices_reset_price_V17))
        break;
    case 13312: /* module 52 call 0 */
        CHECK_ERROR(_readMethod_crowdloans_create_vault_V17(c, &method->basic.crowdloans_create_vault_V17))
        break;
    case 13313: /* module 52 call 1 */
        CHECK_ERROR(_readMethod_crowdloans_update_vault_V17(c, &method->basic.crowdloans_update_vault_V17))
        break;
    case 13314: /* module 52 call 2 */
        CHECK_ERROR(_readMethod_crowdloans_open_V17(c, &method->basic.crowdloans_open_V17))
        break;
    case 13315: /* module 52 call 3 */
        CHECK_ERROR(_readMethod_crowdloans_contribute_V17(c, &method->basic.crowdloans_contribute_V17))
        break;
    case 13316: /* module 52 call 4 */
        CHECK_ERROR(_readMethod_crowdloans_set_vrf_V17(c, &method->basic.crowdloans_set_vrf_V17))
        break;
    case 13317: /* module 52 call 5 */
        CHECK_ERROR(_readMethod_crowdloans_close_V17(c, &method->basic.crowdloans_close_V17))
        break;
    case 13318: /* module 52 call 6 */
        CHECK_ERROR(_readMethod_crowdloans_reopen_V17(c, &method->basic.crowdloans_reopen_V17))
        break;
    case 13319: /* module 52 call 7 */
        CHECK_ERROR(_readMethod_crowdloans_auction_succeeded_V17(c, &method->basic.crowdloans_auction_succeeded_V17))
        break;
    case 13320: /* module 52 call 8 */
        CHECK_ERROR(_readMethod_crowdloans_auction_failed_V17(c, &method->basic.crowdloans_auction_failed_V17))
        break;
    case 13321: /* module 52 call 9 */
        CHECK_ERROR(_readMethod_crowdloans_claim_V17(c, &method->basic.crowdloans_claim_V17))
        break;
    case 13322: /* module 52 call 10 */
        CHECK_ERROR(_readMethod_crowdloans_claim_for_V17(c, &method->basic.crowdloans_claim_for_V17))
        break;
    case 13323: /* module 52 call 11 */
        CHECK_ERROR(_readMethod_crowdloans_withdraw_V17(c, &method->basic.crowdloans_withdraw_V17))
        break;
    case 13324: /* module 52 call 12 */
        CHECK_ERROR(_readMethod_crowdloans_withdraw_for_V17(c, &method->basic.crowdloans_withdraw_for_V17))
        break;
    case 13325: /* module 52 call 13 */
        CHECK_ERROR(_readMethod_crowdloans_redeem_V17(c, &method->basic.crowdloans_redeem_V17))
        break;
    case 13326: /* module 52 call 14 */
        CHECK_ERROR(_readMethod_crowdloans_slot_expired_V17(c, &method->basic.crowdloans_slot_expired_V17))
        break;
    case 13327: /* module 52 call 15 */
        CHECK_ERROR(_readMethod_crowdloans_migrate_pending_V17(c, &method->basic.crowdloans_migrate_pending_V17))
        break;
    case 13329: /* module 52 call 17 */
        CHECK_ERROR(_readMethod_crowdloans_refund_V17(c, &method->basic.crowdloans_refund_V17))
        break;
    case 13330: /* module 52 call 18 */
        CHECK_ERROR(_readMethod_crowdloans_dissolve_vault_V17(c, &method->basic.crowdloans_dissolve_vault_V17))
        break;
    case 13331: /* module 52 call 19 */
        CHECK_ERROR(_readMethod_crowdloans_refund_for_V17(c, &method->basic.crowdloans_refund_for_V17))
        break;
    case 15360: /* module 60 call 0 */
        CHECK_ERROR(_readMethod_liquidstaking_stake_V17(c, &method->nested.liquidstaking_stake_V17))
        break;
    case 15361: /* module 60 call 1 */
        CHECK_ERROR(_readMethod_liquidstaking_unstake_V17(c, &method->nested.liquidstaking_unstake_V17))
        break;
    case 15362: /* module 60 call 2 */
        CHECK_ERROR(_readMethod_liquidstaking_update_reserve_factor_V17(c, &method->nested.liquidstaking_update_reserve_factor_V17))
        break;
    case 15363: /* module 60 call 3 */
        CHECK_ERROR(_readMethod_liquidstaking_update_staking_ledger_cap_V17(c, &method->nested.liquidstaking_update_staking_ledger_cap_V17))
        break;
    case 15364: /* module 60 call 4 */
        CHECK_ERROR(_readMethod_liquidstaking_bond_V17(c, &method->nested.liquidstaking_bond_V17))
        break;
    case 15365: /* module 60 call 5 */
        CHECK_ERROR(_readMethod_liquidstaking_bond_extra_V17(c, &method->nested.liquidstaking_bond_extra_V17))
        break;
    case 15366: /* module 60 call 6 */
        CHECK_ERROR(_readMethod_liquidstaking_unbond_V17(c, &method->nested.liquidstaking_unbond_V17))
        break;
    case 15367: /* module 60 call 7 */
        CHECK_ERROR(_readMethod_liquidstaking_rebond_V17(c, &method->nested.liquidstaking_rebond_V17))
        break;
    case 15368: /* module 60 call 8 */
        CHECK_ERROR(_readMethod_liquidstaking_withdraw_unbonded_V17(c, &method->nested.liquidstaking_withdraw_unbonded_V17))
        break;
    case 15369: /* module 60 call 9 */
        CHECK_ERROR(_readMethod_liquidstaking_nominate_V17(c, &method->nested.liquidstaking_nominate_V17))
        break;
    case 15371: /* module 60 call 11 */
        CHECK_ERROR(_readMethod_liquidstaking_claim_for_V17(c, &method->nested.liquidstaking_claim_for_V17))
        break;
    case 15372: /* module 60 call 12 */
        CHECK_ERROR(_readMethod_liquidstaking_force_set_era_start_block_V17(c, &method->nested.liquidstaking_force_set_era_start_block_V17))
        break;
    case 15373: /* module 60 call 13 */
        CHECK_ERROR(_readMethod_liquidstaking_force_set_current_era_V17(c, &method->nested.liquidstaking_force_set_current_era_V17))
        break;
    case 15374: /* module 60 call 14 */
        CHECK_ERROR(_readMethod_liquidstaking_force_advance_era_V17(c, &method->nested.liquidstaking_force_advance_era_V17))
        break;
    case 15375: /* module 60 call 15 */
        CHECK_ERROR(_readMethod_liquidstaking_force_matching_V17(c, &method->nested.liquidstaking_force_matching_V17))
        break;
    case 15376: /* module 60 call 16 */
        CHECK_ERROR(_readMethod_liquidstaking_force_set_staking_ledger_V17(c, &method->nested.liquidstaking_force_set_staking_ledger_V17))
        break;
    case 15377: /* module 60 call 17 */
        CHECK_ERROR(_readMethod_liquidstaking_set_current_era_V17(c, &method->nested.liquidstaking_set_current_era_V17))
        break;
    case 15378: /* module 60 call 18 */
        CHECK_ERROR(_readMethod_liquidstaking_set_staking_ledger_V17(c, &method->nested.liquidstaking_set_staking_ledger_V17))
        break;
    case 15379: /* module 60 call 19 */
        CHECK_ERROR(_readMethod_liquidstaking_reduce_reserves_V17(c, &method->nested.liquidstaking_reduce_reserves_V17))
        break;
    case 15380: /* module 60 call 20 */
        CHECK_ERROR(_readMethod_liquidstaking_cancel_unstake_V17(c, &method->nested.liquidstaking_cancel_unstake_V17))
        break;
    case 17920: /* module 70 call 0 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_add_member_V17(c, &method->basic.generalcouncilmembership_add_member_V17))
        break;
    case 17921: /* module 70 call 1 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_remove_member_V17(c, &method->basic.generalcouncilmembership_remove_member_V17))
        break;
    case 17922: /* module 70 call 2 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_swap_member_V17(c, &method->basic.generalcouncilmembership_swap_member_V17))
        break;
    case 17923: /* module 70 call 3 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_reset_members_V17(c, &method->basic.generalcouncilmembership_reset_members_V17))
        break;
    case 17924: /* module 70 call 4 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_change_key_V17(c, &method->basic.generalcouncilmembership_change_key_V17))
        break;
    case 17925: /* module 70 call 5 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_set_prime_V17(c, &method->basic.generalcouncilmembership_set_prime_V17))
        break;
    case 17926: /* module 70 call 6 */
        CHECK_ERROR(_readMethod_generalcouncilmembership_clear_prime_V17(c, &method->basic.generalcouncilmembership_clear_prime_V17))
        break;
    case 18176: /* module 71 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V17(c, &method->basic.technicalcommitteemembership_add_member_V17))
        break;
    case 18177: /* module 71 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V17(c, &method->basic.technicalcommitteemembership_remove_member_V17))
        break;
    case 18178: /* module 71 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V17(c, &method->basic.technicalcommitteemembership_swap_member_V17))
        break;
    case 18179: /* module 71 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V17(c, &method->basic.technicalcommitteemembership_reset_members_V17))
        break;
    case 18180: /* module 71 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_change_key_V17(c, &method->basic.technicalcommitteemembership_change_key_V17))
        break;
    case 18181: /* module 71 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_prime_V17(c, &method->basic.technicalcommitteemembership_set_prime_V17))
        break;
    case 18182: /* module 71 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_clear_prime_V17(c, &method->basic.technicalcommitteemembership_clear_prime_V17))
        break;
    case 18432: /* module 72 call 0 */
        CHECK_ERROR(_readMethod_oraclemembership_add_member_V17(c, &method->basic.oraclemembership_add_member_V17))
        break;
    case 18433: /* module 72 call 1 */
        CHECK_ERROR(_readMethod_oraclemembership_remove_member_V17(c, &method->basic.oraclemembership_remove_member_V17))
        break;
    case 18434: /* module 72 call 2 */
        CHECK_ERROR(_readMethod_oraclemembership_swap_member_V17(c, &method->basic.oraclemembership_swap_member_V17))
        break;
    case 18435: /* module 72 call 3 */
        CHECK_ERROR(_readMethod_oraclemembership_reset_members_V17(c, &method->basic.oraclemembership_reset_members_V17))
        break;
    case 18436: /* module 72 call 4 */
        CHECK_ERROR(_readMethod_oraclemembership_change_key_V17(c, &method->basic.oraclemembership_change_key_V17))
        break;
    case 18437: /* module 72 call 5 */
        CHECK_ERROR(_readMethod_oraclemembership_set_prime_V17(c, &method->basic.oraclemembership_set_prime_V17))
        break;
    case 18438: /* module 72 call 6 */
        CHECK_ERROR(_readMethod_oraclemembership_clear_prime_V17(c, &method->basic.oraclemembership_clear_prime_V17))
        break;
    case 18688: /* module 73 call 0 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_add_member_V17(c, &method->basic.liquidstakingagentsmembership_add_member_V17))
        break;
    case 18689: /* module 73 call 1 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_remove_member_V17(c, &method->basic.liquidstakingagentsmembership_remove_member_V17))
        break;
    case 18690: /* module 73 call 2 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_swap_member_V17(c, &method->basic.liquidstakingagentsmembership_swap_member_V17))
        break;
    case 18691: /* module 73 call 3 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_reset_members_V17(c, &method->basic.liquidstakingagentsmembership_reset_members_V17))
        break;
    case 18692: /* module 73 call 4 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_change_key_V17(c, &method->basic.liquidstakingagentsmembership_change_key_V17))
        break;
    case 18693: /* module 73 call 5 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_set_prime_V17(c, &method->basic.liquidstakingagentsmembership_set_prime_V17))
        break;
    case 18694: /* module 73 call 6 */
        CHECK_ERROR(_readMethod_liquidstakingagentsmembership_clear_prime_V17(c, &method->basic.liquidstakingagentsmembership_clear_prime_V17))
        break;
    case 18944: /* module 74 call 0 */
        CHECK_ERROR(_readMethod_bridgemembership_add_member_V17(c, &method->basic.bridgemembership_add_member_V17))
        break;
    case 18945: /* module 74 call 1 */
        CHECK_ERROR(_readMethod_bridgemembership_remove_member_V17(c, &method->basic.bridgemembership_remove_member_V17))
        break;
    case 18946: /* module 74 call 2 */
        CHECK_ERROR(_readMethod_bridgemembership_swap_member_V17(c, &method->basic.bridgemembership_swap_member_V17))
        break;
    case 18947: /* module 74 call 3 */
        CHECK_ERROR(_readMethod_bridgemembership_reset_members_V17(c, &method->basic.bridgemembership_reset_members_V17))
        break;
    case 18948: /* module 74 call 4 */
        CHECK_ERROR(_readMethod_bridgemembership_change_key_V17(c, &method->basic.bridgemembership_change_key_V17))
        break;
    case 18949: /* module 74 call 5 */
        CHECK_ERROR(_readMethod_bridgemembership_set_prime_V17(c, &method->basic.bridgemembership_set_prime_V17))
        break;
    case 18950: /* module 74 call 6 */
        CHECK_ERROR(_readMethod_bridgemembership_clear_prime_V17(c, &method->basic.bridgemembership_clear_prime_V17))
        break;
    case 19200: /* module 75 call 0 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_add_member_V17(c, &method->basic.crowdloansautomatorsmembership_add_member_V17))
        break;
    case 19201: /* module 75 call 1 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_remove_member_V17(c, &method->basic.crowdloansautomatorsmembership_remove_member_V17))
        break;
    case 19202: /* module 75 call 2 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_swap_member_V17(c, &method->basic.crowdloansautomatorsmembership_swap_member_V17))
        break;
    case 19203: /* module 75 call 3 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_reset_members_V17(c, &method->basic.crowdloansautomatorsmembership_reset_members_V17))
        break;
    case 19204: /* module 75 call 4 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_change_key_V17(c, &method->basic.crowdloansautomatorsmembership_change_key_V17))
        break;
    case 19205: /* module 75 call 5 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_set_prime_V17(c, &method->basic.crowdloansautomatorsmembership_set_prime_V17))
        break;
    case 19206: /* module 75 call 6 */
        CHECK_ERROR(_readMethod_crowdloansautomatorsmembership_clear_prime_V17(c, &method->basic.crowdloansautomatorsmembership_clear_prime_V17))
        break;
    case 20480: /* module 80 call 0 */
        CHECK_ERROR(_readMethod_amm_add_liquidity_V17(c, &method->basic.amm_add_liquidity_V17))
        break;
    case 20481: /* module 80 call 1 */
        CHECK_ERROR(_readMethod_amm_remove_liquidity_V17(c, &method->basic.amm_remove_liquidity_V17))
        break;
    case 20482: /* module 80 call 2 */
        CHECK_ERROR(_readMethod_amm_create_pool_V17(c, &method->basic.amm_create_pool_V17))
        break;
    case 20736: /* module 81 call 0 */
        CHECK_ERROR(_readMethod_ammroute_swap_exact_tokens_for_tokens_V17(c, &method->basic.ammroute_swap_exact_tokens_for_tokens_V17))
        break;
    case 20737: /* module 81 call 1 */
        CHECK_ERROR(_readMethod_ammroute_swap_tokens_for_exact_tokens_V17(c, &method->basic.ammroute_swap_tokens_for_exact_tokens_V17))
        break;
    case 20992: /* module 82 call 0 */
        CHECK_ERROR(_readMethod_currencyadapter_force_set_lock_V17(c, &method->basic.currencyadapter_force_set_lock_V17))
        break;
    case 20993: /* module 82 call 1 */
        CHECK_ERROR(_readMethod_currencyadapter_force_remove_lock_V17(c, &method->basic.currencyadapter_force_remove_lock_V17))
        break;
    case 23040: /* module 90 call 0 */
        CHECK_ERROR(_readMethod_bridge_register_chain_V17(c, &method->basic.bridge_register_chain_V17))
        break;
    case 23041: /* module 90 call 1 */
        CHECK_ERROR(_readMethod_bridge_unregister_chain_V17(c, &method->basic.bridge_unregister_chain_V17))
        break;
    case 23042: /* module 90 call 2 */
        CHECK_ERROR(_readMethod_bridge_register_bridge_token_V17(c, &method->basic.bridge_register_bridge_token_V17))
        break;
    case 23043: /* module 90 call 3 */
        CHECK_ERROR(_readMethod_bridge_unregister_bridge_token_V17(c, &method->basic.bridge_unregister_bridge_token_V17))
        break;
    case 23044: /* module 90 call 4 */
        CHECK_ERROR(_readMethod_bridge_set_bridge_token_fee_V17(c, &method->basic.bridge_set_bridge_token_fee_V17))
        break;
    case 23045: /* module 90 call 5 */
        CHECK_ERROR(_readMethod_bridge_set_bridge_token_status_V17(c, &method->basic.bridge_set_bridge_token_status_V17))
        break;
    case 23046: /* module 90 call 6 */
        CHECK_ERROR(_readMethod_bridge_set_bridge_token_cap_V17(c, &method->basic.bridge_set_bridge_token_cap_V17))
        break;
    case 23047: /* module 90 call 7 */
        CHECK_ERROR(_readMethod_bridge_clean_cap_accumulated_value_V17(c, &method->basic.bridge_clean_cap_accumulated_value_V17))
        break;
    case 23048: /* module 90 call 8 */
        CHECK_ERROR(_readMethod_bridge_teleport_V17(c, &method->basic.bridge_teleport_V17))
        break;
    case 23049: /* module 90 call 9 */
        CHECK_ERROR(_readMethod_bridge_materialize_V17(c, &method->basic.bridge_materialize_V17))
        break;
    case 23296: /* module 91 call 0 */
        CHECK_ERROR(_readMethod_emergencyshutdown_toggle_pallet_V17(c, &method->basic.emergencyshutdown_toggle_pallet_V17))
        break;
    case 23297: /* module 91 call 1 */
        CHECK_ERROR(_readMethod_emergencyshutdown_toggle_call_V17(c, &method->basic.emergencyshutdown_toggle_call_V17))
        break;
    case 23552: /* module 92 call 0 */
        CHECK_ERROR(_readMethod_farming_create_V17(c, &method->basic.farming_create_V17))
        break;
    case 23553: /* module 92 call 1 */
        CHECK_ERROR(_readMethod_farming_set_pool_status_V17(c, &method->basic.farming_set_pool_status_V17))
        break;
    case 23554: /* module 92 call 2 */
        CHECK_ERROR(_readMethod_farming_set_pool_cool_down_duration_V17(c, &method->basic.farming_set_pool_cool_down_duration_V17))
        break;
    case 23555: /* module 92 call 3 */
        CHECK_ERROR(_readMethod_farming_reset_pool_unlock_height_V17(c, &method->basic.farming_reset_pool_unlock_height_V17))
        break;
    case 23556: /* module 92 call 4 */
        CHECK_ERROR(_readMethod_farming_deposit_V17(c, &method->basic.farming_deposit_V17))
        break;
    case 23557: /* module 92 call 5 */
        CHECK_ERROR(_readMethod_farming_withdraw_V17(c, &method->basic.farming_withdraw_V17))
        break;
    case 23558: /* module 92 call 6 */
        CHECK_ERROR(_readMethod_farming_redeem_V17(c, &method->basic.farming_redeem_V17))
        break;
    case 23559: /* module 92 call 7 */
        CHECK_ERROR(_readMethod_farming_claim_V17(c, &method->basic.farming_claim_V17))
        break;
    case 23560: /* module 92 call 8 */
        CHECK_ERROR(_readMethod_farming_dispatch_reward_V17(c, &method->basic.farming_dispatch_reward_V17))
        break;
    case 23808: /* module 93 call 0 */
        CHECK_ERROR(_readMethod_xcmhelper_update_xcm_weight_fee_V17(c, &method->basic.xcmhelper_update_xcm_weight_fee_V17))
        break;
    case 24067: /* module 94 call 3 */
        CHECK_ERROR(_readMethod_streaming_set_minimum_deposit_V17(c, &method->basic.streaming_set_minimum_deposit_V17))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_parachainsystem_authorize_upgrade_V17(c, &method->basic.parachainsystem_authorize_upgrade_V17))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_parachainsystem_enact_authorized_upgrade_V17(c, &method->basic.parachainsystem_enact_authorized_upgrade_V17))
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

const char* _getMethod_ModuleName_V17(uint8_t moduleIdx)
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
    case 23:
        return STR_MO_DMPQUEUE;
    case 31:
        return STR_MO_COLLATORSELECTION;
    case 43:
        return STR_MO_XTOKENS;
    case 46:
        return STR_MO_VESTING;
    case 50:
        return STR_MO_LOANS;
    case 51:
        return STR_MO_PRICES;
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
    case 80:
        return STR_MO_AMM;
    case 81:
        return STR_MO_AMMROUTE;
    case 82:
        return STR_MO_CURRENCYADAPTER;
    case 90:
        return STR_MO_BRIDGE;
    case 91:
        return STR_MO_EMERGENCYSHUTDOWN;
    case 92:
        return STR_MO_FARMING;
    case 93:
        return STR_MO_XCMHELPER;
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

const char* _getMethod_Name_V17(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return STR_ME_BATCH;
    case 514: /* module 2 call 2 */
        return STR_ME_BATCH_ALL;
    case 516: /* module 2 call 4 */
        return STR_ME_FORCE_BATCH;
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
        return _getMethod_Name_V17_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V17_ParserFull(uint16_t callPrivIdx)
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
    case 1792: /* module 7 call 0 */
        return STR_ME_PROXY;
    case 1793: /* module 7 call 1 */
        return STR_ME_ADD_PROXY;
    case 1794: /* module 7 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 1795: /* module 7 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 1796: /* module 7 call 4 */
        return STR_ME_ANONYMOUS;
    case 1797: /* module 7 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 1798: /* module 7 call 6 */
        return STR_ME_ANNOUNCE;
    case 1799: /* module 7 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 1800: /* module 7 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 1801: /* module 7 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
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
    case 3587: /* module 14 call 3 */
        return STR_ME_SPEND;
    case 3588: /* module 14 call 4 */
        return STR_ME_REMOVE_APPROVAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 4097: /* module 16 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 4098: /* module 16 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 4099: /* module 16 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 5632: /* module 22 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
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
    case 5888: /* module 23 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
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
    case 11008: /* module 43 call 0 */
        return STR_ME_TRANSFER;
    case 11776: /* module 46 call 0 */
        return STR_ME_CLAIM;
    case 11777: /* module 46 call 1 */
        return STR_ME_VESTED_TRANSFER;
    case 11778: /* module 46 call 2 */
        return STR_ME_UPDATE_VESTING_SCHEDULES;
    case 11779: /* module 46 call 3 */
        return STR_ME_CLAIM_FOR;
    case 12800: /* module 50 call 0 */
        return STR_ME_ADD_MARKET;
    case 12801: /* module 50 call 1 */
        return STR_ME_ACTIVATE_MARKET;
    case 12802: /* module 50 call 2 */
        return STR_ME_UPDATE_RATE_MODEL;
    case 12803: /* module 50 call 3 */
        return STR_ME_UPDATE_MARKET;
    case 12804: /* module 50 call 4 */
        return STR_ME_FORCE_UPDATE_MARKET;
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
    case 12810: /* module 50 call 10 */
        return STR_ME_MINT;
    case 12811: /* module 50 call 11 */
        return STR_ME_REDEEM;
    case 12812: /* module 50 call 12 */
        return STR_ME_REDEEM_ALL;
    case 12813: /* module 50 call 13 */
        return STR_ME_BORROW;
    case 12814: /* module 50 call 14 */
        return STR_ME_REPAY_BORROW;
    case 12815: /* module 50 call 15 */
        return STR_ME_REPAY_BORROW_ALL;
    case 12816: /* module 50 call 16 */
        return STR_ME_COLLATERAL_ASSET;
    case 12817: /* module 50 call 17 */
        return STR_ME_LIQUIDATE_BORROW;
    case 12818: /* module 50 call 18 */
        return STR_ME_ADD_RESERVES;
    case 12819: /* module 50 call 19 */
        return STR_ME_REDUCE_RESERVES;
    case 12820: /* module 50 call 20 */
        return STR_ME_REDUCE_INCENTIVE_RESERVES;
    case 12821: /* module 50 call 21 */
        return STR_ME_UPDATE_LIQUIDATION_FREE_COLLATERAL;
    case 13056: /* module 51 call 0 */
        return STR_ME_SET_PRICE;
    case 13057: /* module 51 call 1 */
        return STR_ME_RESET_PRICE;
    case 13312: /* module 52 call 0 */
        return STR_ME_CREATE_VAULT;
    case 13313: /* module 52 call 1 */
        return STR_ME_UPDATE_VAULT;
    case 13314: /* module 52 call 2 */
        return STR_ME_OPEN;
    case 13315: /* module 52 call 3 */
        return STR_ME_CONTRIBUTE;
    case 13316: /* module 52 call 4 */
        return STR_ME_SET_VRF;
    case 13317: /* module 52 call 5 */
        return STR_ME_CLOSE;
    case 13318: /* module 52 call 6 */
        return STR_ME_REOPEN;
    case 13319: /* module 52 call 7 */
        return STR_ME_AUCTION_SUCCEEDED;
    case 13320: /* module 52 call 8 */
        return STR_ME_AUCTION_FAILED;
    case 13321: /* module 52 call 9 */
        return STR_ME_CLAIM;
    case 13322: /* module 52 call 10 */
        return STR_ME_CLAIM_FOR;
    case 13323: /* module 52 call 11 */
        return STR_ME_WITHDRAW;
    case 13324: /* module 52 call 12 */
        return STR_ME_WITHDRAW_FOR;
    case 13325: /* module 52 call 13 */
        return STR_ME_REDEEM;
    case 13326: /* module 52 call 14 */
        return STR_ME_SLOT_EXPIRED;
    case 13327: /* module 52 call 15 */
        return STR_ME_MIGRATE_PENDING;
    case 13329: /* module 52 call 17 */
        return STR_ME_REFUND;
    case 13330: /* module 52 call 18 */
        return STR_ME_DISSOLVE_VAULT;
    case 13331: /* module 52 call 19 */
        return STR_ME_REFUND_FOR;
    case 15360: /* module 60 call 0 */
        return STR_ME_STAKE;
    case 15361: /* module 60 call 1 */
        return STR_ME_UNSTAKE;
    case 15362: /* module 60 call 2 */
        return STR_ME_UPDATE_RESERVE_FACTOR;
    case 15363: /* module 60 call 3 */
        return STR_ME_UPDATE_STAKING_LEDGER_CAP;
    case 15364: /* module 60 call 4 */
        return STR_ME_BOND;
    case 15365: /* module 60 call 5 */
        return STR_ME_BOND_EXTRA;
    case 15366: /* module 60 call 6 */
        return STR_ME_UNBOND;
    case 15367: /* module 60 call 7 */
        return STR_ME_REBOND;
    case 15368: /* module 60 call 8 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 15369: /* module 60 call 9 */
        return STR_ME_NOMINATE;
    case 15371: /* module 60 call 11 */
        return STR_ME_CLAIM_FOR;
    case 15372: /* module 60 call 12 */
        return STR_ME_FORCE_SET_ERA_START_BLOCK;
    case 15373: /* module 60 call 13 */
        return STR_ME_FORCE_SET_CURRENT_ERA;
    case 15374: /* module 60 call 14 */
        return STR_ME_FORCE_ADVANCE_ERA;
    case 15375: /* module 60 call 15 */
        return STR_ME_FORCE_MATCHING;
    case 15376: /* module 60 call 16 */
        return STR_ME_FORCE_SET_STAKING_LEDGER;
    case 15377: /* module 60 call 17 */
        return STR_ME_SET_CURRENT_ERA;
    case 15378: /* module 60 call 18 */
        return STR_ME_SET_STAKING_LEDGER;
    case 15379: /* module 60 call 19 */
        return STR_ME_REDUCE_RESERVES;
    case 15380: /* module 60 call 20 */
        return STR_ME_CANCEL_UNSTAKE;
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
    case 20480: /* module 80 call 0 */
        return STR_ME_ADD_LIQUIDITY;
    case 20481: /* module 80 call 1 */
        return STR_ME_REMOVE_LIQUIDITY;
    case 20482: /* module 80 call 2 */
        return STR_ME_CREATE_POOL;
    case 20736: /* module 81 call 0 */
        return STR_ME_SWAP_EXACT_TOKENS_FOR_TOKENS;
    case 20737: /* module 81 call 1 */
        return STR_ME_SWAP_TOKENS_FOR_EXACT_TOKENS;
    case 20992: /* module 82 call 0 */
        return STR_ME_FORCE_SET_LOCK;
    case 20993: /* module 82 call 1 */
        return STR_ME_FORCE_REMOVE_LOCK;
    case 23040: /* module 90 call 0 */
        return STR_ME_REGISTER_CHAIN;
    case 23041: /* module 90 call 1 */
        return STR_ME_UNREGISTER_CHAIN;
    case 23042: /* module 90 call 2 */
        return STR_ME_REGISTER_BRIDGE_TOKEN;
    case 23043: /* module 90 call 3 */
        return STR_ME_UNREGISTER_BRIDGE_TOKEN;
    case 23044: /* module 90 call 4 */
        return STR_ME_SET_BRIDGE_TOKEN_FEE;
    case 23045: /* module 90 call 5 */
        return STR_ME_SET_BRIDGE_TOKEN_STATUS;
    case 23046: /* module 90 call 6 */
        return STR_ME_SET_BRIDGE_TOKEN_CAP;
    case 23047: /* module 90 call 7 */
        return STR_ME_CLEAN_CAP_ACCUMULATED_VALUE;
    case 23048: /* module 90 call 8 */
        return STR_ME_TELEPORT;
    case 23049: /* module 90 call 9 */
        return STR_ME_MATERIALIZE;
    case 23296: /* module 91 call 0 */
        return STR_ME_TOGGLE_PALLET;
    case 23297: /* module 91 call 1 */
        return STR_ME_TOGGLE_CALL;
    case 23552: /* module 92 call 0 */
        return STR_ME_CREATE;
    case 23553: /* module 92 call 1 */
        return STR_ME_SET_POOL_STATUS;
    case 23554: /* module 92 call 2 */
        return STR_ME_SET_POOL_COOL_DOWN_DURATION;
    case 23555: /* module 92 call 3 */
        return STR_ME_RESET_POOL_UNLOCK_HEIGHT;
    case 23556: /* module 92 call 4 */
        return STR_ME_DEPOSIT;
    case 23557: /* module 92 call 5 */
        return STR_ME_WITHDRAW;
    case 23558: /* module 92 call 6 */
        return STR_ME_REDEEM;
    case 23559: /* module 92 call 7 */
        return STR_ME_CLAIM;
    case 23560: /* module 92 call 8 */
        return STR_ME_DISPATCH_REWARD;
    case 23808: /* module 93 call 0 */
        return STR_ME_UPDATE_XCM_WEIGHT_FEE;
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

uint8_t _getMethod_NumItems_V17(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return 1;
    case 514: /* module 2 call 2 */
        return 1;
    case 516: /* module 2 call 4 */
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
    case 1792: /* module 7 call 0 */
        return 3;
    case 1793: /* module 7 call 1 */
        return 3;
    case 1794: /* module 7 call 2 */
        return 3;
    case 1795: /* module 7 call 3 */
        return 0;
    case 1796: /* module 7 call 4 */
        return 3;
    case 1797: /* module 7 call 5 */
        return 5;
    case 1798: /* module 7 call 6 */
        return 2;
    case 1799: /* module 7 call 7 */
        return 2;
    case 1800: /* module 7 call 8 */
        return 2;
    case 1801: /* module 7 call 9 */
        return 4;
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
    case 3587: /* module 14 call 3 */
        return 2;
    case 3588: /* module 14 call 4 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 1;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4099: /* module 16 call 3 */
        return 1;
    case 5632: /* module 22 call 0 */
        return 2;
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
    case 5888: /* module 23 call 0 */
        return 2;
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
    case 11008: /* module 43 call 0 */
        return 4;
    case 11776: /* module 46 call 0 */
        return 0;
    case 11777: /* module 46 call 1 */
        return 2;
    case 11778: /* module 46 call 2 */
        return 2;
    case 11779: /* module 46 call 3 */
        return 1;
    case 12800: /* module 50 call 0 */
        return 2;
    case 12801: /* module 50 call 1 */
        return 1;
    case 12802: /* module 50 call 2 */
        return 2;
    case 12803: /* module 50 call 3 */
        return 9;
    case 12804: /* module 50 call 4 */
        return 2;
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
    case 12810: /* module 50 call 10 */
        return 2;
    case 12811: /* module 50 call 11 */
        return 2;
    case 12812: /* module 50 call 12 */
        return 1;
    case 12813: /* module 50 call 13 */
        return 2;
    case 12814: /* module 50 call 14 */
        return 2;
    case 12815: /* module 50 call 15 */
        return 1;
    case 12816: /* module 50 call 16 */
        return 2;
    case 12817: /* module 50 call 17 */
        return 4;
    case 12818: /* module 50 call 18 */
        return 3;
    case 12819: /* module 50 call 19 */
        return 3;
    case 12820: /* module 50 call 20 */
        return 3;
    case 12821: /* module 50 call 21 */
        return 1;
    case 13056: /* module 51 call 0 */
        return 2;
    case 13057: /* module 51 call 1 */
        return 1;
    case 13312: /* module 52 call 0 */
        return 7;
    case 13313: /* module 52 call 1 */
        return 4;
    case 13314: /* module 52 call 2 */
        return 1;
    case 13315: /* module 52 call 3 */
        return 3;
    case 13316: /* module 52 call 4 */
        return 1;
    case 13317: /* module 52 call 5 */
        return 1;
    case 13318: /* module 52 call 6 */
        return 1;
    case 13319: /* module 52 call 7 */
        return 1;
    case 13320: /* module 52 call 8 */
        return 1;
    case 13321: /* module 52 call 9 */
        return 3;
    case 13322: /* module 52 call 10 */
        return 4;
    case 13323: /* module 52 call 11 */
        return 3;
    case 13324: /* module 52 call 12 */
        return 4;
    case 13325: /* module 52 call 13 */
        return 4;
    case 13326: /* module 52 call 14 */
        return 1;
    case 13327: /* module 52 call 15 */
        return 1;
    case 13329: /* module 52 call 17 */
        return 3;
    case 13330: /* module 52 call 18 */
        return 3;
    case 13331: /* module 52 call 19 */
        return 6;
    case 15360: /* module 60 call 0 */
        return 1;
    case 15361: /* module 60 call 1 */
        return 2;
    case 15362: /* module 60 call 2 */
        return 1;
    case 15363: /* module 60 call 3 */
        return 1;
    case 15364: /* module 60 call 4 */
        return 3;
    case 15365: /* module 60 call 5 */
        return 2;
    case 15366: /* module 60 call 6 */
        return 2;
    case 15367: /* module 60 call 7 */
        return 2;
    case 15368: /* module 60 call 8 */
        return 2;
    case 15369: /* module 60 call 9 */
        return 2;
    case 15371: /* module 60 call 11 */
        return 1;
    case 15372: /* module 60 call 12 */
        return 1;
    case 15373: /* module 60 call 13 */
        return 1;
    case 15374: /* module 60 call 14 */
        return 1;
    case 15375: /* module 60 call 15 */
        return 0;
    case 15376: /* module 60 call 16 */
        return 2;
    case 15377: /* module 60 call 17 */
        return 2;
    case 15378: /* module 60 call 18 */
        return 3;
    case 15379: /* module 60 call 19 */
        return 2;
    case 15380: /* module 60 call 20 */
        return 1;
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
    case 20480: /* module 80 call 0 */
        return 3;
    case 20481: /* module 80 call 1 */
        return 2;
    case 20482: /* module 80 call 2 */
        return 4;
    case 20736: /* module 81 call 0 */
        return 3;
    case 20737: /* module 81 call 1 */
        return 3;
    case 20992: /* module 82 call 0 */
        return 3;
    case 20993: /* module 82 call 1 */
        return 2;
    case 23040: /* module 90 call 0 */
        return 1;
    case 23041: /* module 90 call 1 */
        return 1;
    case 23042: /* module 90 call 2 */
        return 2;
    case 23043: /* module 90 call 3 */
        return 1;
    case 23044: /* module 90 call 4 */
        return 2;
    case 23045: /* module 90 call 5 */
        return 2;
    case 23046: /* module 90 call 6 */
        return 3;
    case 23047: /* module 90 call 7 */
        return 2;
    case 23048: /* module 90 call 8 */
        return 4;
    case 23049: /* module 90 call 9 */
        return 6;
    case 23296: /* module 91 call 0 */
        return 1;
    case 23297: /* module 91 call 1 */
        return 2;
    case 23552: /* module 92 call 0 */
        return 4;
    case 23553: /* module 92 call 1 */
        return 4;
    case 23554: /* module 92 call 2 */
        return 4;
    case 23555: /* module 92 call 3 */
        return 3;
    case 23556: /* module 92 call 4 */
        return 4;
    case 23557: /* module 92 call 5 */
        return 4;
    case 23558: /* module 92 call 6 */
        return 3;
    case 23559: /* module 92 call 7 */
        return 3;
    case 23560: /* module 92 call 8 */
        return 6;
    case 23808: /* module 93 call 0 */
        return 2;
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

const char* _getMethod_ItemName_V17(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
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
    case 516: /* module 2 call 4 */
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
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
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
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
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
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
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
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
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
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
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
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_dest_weight;
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_vesting_schedules;
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
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_market;
        default:
            return NULL;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        default:
            return NULL;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_rate_model;
        default:
            return NULL;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_collateral_factor;
        case 2:
            return STR_IT_liquidation_threshold;
        case 3:
            return STR_IT_reserve_factor;
        case 4:
            return STR_IT_close_factor;
        case 5:
            return STR_IT_liquidate_incentive_reserved_factor;
        case 6:
            return STR_IT_liquidate_incentive;
        case 7:
            return STR_IT_supply_cap;
        case 8:
            return STR_IT_borrow_cap;
        default:
            return NULL;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_market;
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
    case 12810: /* module 50 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_mint_amount;
        default:
            return NULL;
        }
    case 12811: /* module 50 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_redeem_amount;
        default:
            return NULL;
        }
    case 12812: /* module 50 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        default:
            return NULL;
        }
    case 12813: /* module 50 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_borrow_amount;
        default:
            return NULL;
        }
    case 12814: /* module 50 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_repay_amount;
        default:
            return NULL;
        }
    case 12815: /* module 50 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        default:
            return NULL;
        }
    case 12816: /* module 50 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_enable;
        default:
            return NULL;
        }
    case 12817: /* module 50 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_borrower;
        case 1:
            return STR_IT_liquidation_asset_id;
        case 2:
            return STR_IT_repay_amount;
        case 3:
            return STR_IT_collateral_asset_id;
        default:
            return NULL;
        }
    case 12818: /* module 50 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payer;
        case 1:
            return STR_IT_asset_id;
        case 2:
            return STR_IT_add_amount;
        default:
            return NULL;
        }
    case 12819: /* module 50 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receiver;
        case 1:
            return STR_IT_asset_id;
        case 2:
            return STR_IT_reduce_amount;
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
    case 12821: /* module 50 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collaterals;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_price;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        default:
            return NULL;
        }
    case 13312: /* module 52 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_ctoken;
        case 2:
            return STR_IT_lease_start;
        case 3:
            return STR_IT_lease_end;
        case 4:
            return STR_IT_contribution_strategy;
        case 5:
            return STR_IT_cap;
        case 6:
            return STR_IT_end_block;
        default:
            return NULL;
        }
    case 13313: /* module 52 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_end_block;
        case 3:
            return STR_IT_contribution_strategy;
        default:
            return NULL;
        }
    case 13314: /* module 52 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13315: /* module 52 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_referral_code;
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
    case 13317: /* module 52 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13318: /* module 52 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13319: /* module 52 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13320: /* module 52 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13321: /* module 52 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_lease_start;
        case 2:
            return STR_IT_lease_end;
        default:
            return NULL;
        }
    case 13322: /* module 52 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_crowdloan;
        case 2:
            return STR_IT_lease_start;
        case 3:
            return STR_IT_lease_end;
        default:
            return NULL;
        }
    case 13323: /* module 52 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_lease_start;
        case 2:
            return STR_IT_lease_end;
        default:
            return NULL;
        }
    case 13324: /* module 52 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_crowdloan;
        case 2:
            return STR_IT_lease_start;
        case 3:
            return STR_IT_lease_end;
        default:
            return NULL;
        }
    case 13325: /* module 52 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_lease_start;
        case 2:
            return STR_IT_lease_end;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 13326: /* module 52 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13327: /* module 52 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        default:
            return NULL;
        }
    case 13329: /* module 52 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_lease_start;
        case 2:
            return STR_IT_lease_end;
        default:
            return NULL;
        }
    case 13330: /* module 52 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_crowdloan;
        case 1:
            return STR_IT_lease_start;
        case 2:
            return STR_IT_lease_end;
        default:
            return NULL;
        }
    case 13331: /* module 52 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_crowdloan;
        case 2:
            return STR_IT_kind;
        case 3:
            return STR_IT_amount;
        case 4:
            return STR_IT_lease_start;
        case 5:
            return STR_IT_lease_end;
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
        case 1:
            return STR_IT_unstake_provider;
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
    case 15364: /* module 60 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 15365: /* module 60 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 15366: /* module 60 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 15367: /* module 60 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 15368: /* module 60 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_num_slashing_spans;
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
    case 15372: /* module 60 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_block_number;
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
    case 15376: /* module 60 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_staking_ledger;
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
    case 15378: /* module 60 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_derivative_index;
        case 1:
            return STR_IT_staking_ledger;
        case 2:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 15379: /* module 60 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receiver;
        case 1:
            return STR_IT_reduce_amount;
        default:
            return NULL;
        }
    case 15380: /* module 60 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
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
    case 20480: /* module 80 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pair;
        case 1:
            return STR_IT_desired_amounts;
        case 2:
            return STR_IT_minimum_amounts;
        default:
            return NULL;
        }
    case 20481: /* module 80 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pair;
        case 1:
            return STR_IT_liquidity;
        default:
            return NULL;
        }
    case 20482: /* module 80 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pair;
        case 1:
            return STR_IT_liquidity_amounts;
        case 2:
            return STR_IT_lptoken_receiver;
        case 3:
            return STR_IT_lp_token_id;
        default:
            return NULL;
        }
    case 20736: /* module 81 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_route;
        case 1:
            return STR_IT_amount_in;
        case 2:
            return STR_IT_min_amount_out;
        default:
            return NULL;
        }
    case 20737: /* module 81 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_route;
        case 1:
            return STR_IT_amount_out;
        case 2:
            return STR_IT_max_amount_in;
        default:
            return NULL;
        }
    case 20992: /* module 82 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 20993: /* module 82 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 23040: /* module 90 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_chain_id;
        default:
            return NULL;
        }
    case 23041: /* module 90 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_chain_id;
        default:
            return NULL;
        }
    case 23042: /* module 90 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset_id;
        case 1:
            return STR_IT_bridge_token;
        default:
            return NULL;
        }
    case 23043: /* module 90 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_token_id;
        default:
            return NULL;
        }
    case 23044: /* module 90 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_token_id;
        case 1:
            return STR_IT_new_fee;
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
    case 23046: /* module 90 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_token_id;
        case 1:
            return STR_IT_bridge_type;
        case 2:
            return STR_IT_new_cap;
        default:
            return NULL;
        }
    case 23047: /* module 90 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_token_id;
        case 1:
            return STR_IT_bridge_type;
        default:
            return NULL;
        }
    case 23048: /* module 90 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest_id;
        case 1:
            return STR_IT_bridge_token_id;
        case 2:
            return STR_IT_to;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 23049: /* module 90 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_src_id;
        case 1:
            return STR_IT_src_nonce;
        case 2:
            return STR_IT_bridge_token_id;
        case 3:
            return STR_IT_to;
        case 4:
            return STR_IT_amount;
        case 5:
            return STR_IT_favour;
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
    case 23552: /* module 92 call 0 */
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
    case 23553: /* module 92 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_reward_asset;
        case 2:
            return STR_IT_lock_duration;
        case 3:
            return STR_IT_is_active;
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
    case 23556: /* module 92 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_reward_asset;
        case 2:
            return STR_IT_lock_duration;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 23557: /* module 92 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_reward_asset;
        case 2:
            return STR_IT_lock_duration;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 23558: /* module 92 call 6 */
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
    case 23559: /* module 92 call 7 */
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
    case 23560: /* module 92 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_reward_asset;
        case 2:
            return STR_IT_lock_duration;
        case 3:
            return STR_IT_payer;
        case 4:
            return STR_IT_amount;
        case 5:
            return STR_IT_reward_duration;
        default:
            return NULL;
        }
    case 23808: /* module 93 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_xcm_call;
        case 1:
            return STR_IT_xcm_weight_fee_misc;
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

parser_error_t _getMethod_ItemValue_V17(
    pd_Method_V17_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V17 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V17.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 514: /* module 2 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V17 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V17.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 516: /* module 2 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V17 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V17.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.balances_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V17 - source */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.balances_force_transfer_V17.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.balances_force_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.balances_transfer_keep_alive_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.balances_transfer_all_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V17 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V17.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V17 - keys */;
            return _toStringKeys_V17(
                &m->basic.session_set_keys_V17.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V17 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V17.proof,
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
        case 0: /* system_fill_block_V17 - ratio */;
            return _toStringPerbill_V17(
                &m->nested.system_fill_block_V17.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V17 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V17.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V17 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V17.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V17 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V17 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V17 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V17.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V17 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V17.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V17 - other_signatories */;
            return _toStringVecAccountId_V17(
                &m->nested.multisig_as_multi_threshold_1_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V17 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V17 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V17 - other_signatories */;
            return _toStringVecAccountId_V17(
                &m->nested.multisig_as_multi_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V17 - maybe_timepoint */;
            return _toStringOptionTimepoint_V17(
                &m->nested.multisig_as_multi_V17.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V17 - call */;
            return _toStringOpaqueCall_V17(
                &m->nested.multisig_as_multi_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V17 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V17.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V17 - max_weight */;
            return _toStringWeight_V17(
                &m->nested.multisig_as_multi_V17.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V17 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V17 - other_signatories */;
            return _toStringVecAccountId_V17(
                &m->nested.multisig_approve_as_multi_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V17 - maybe_timepoint */;
            return _toStringOptionTimepoint_V17(
                &m->nested.multisig_approve_as_multi_V17.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V17 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V17 - max_weight */;
            return _toStringWeight_V17(
                &m->nested.multisig_approve_as_multi_V17.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V17 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V17 - other_signatories */;
            return _toStringVecAccountId_V17(
                &m->nested.multisig_cancel_as_multi_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V17 - timepoint */;
            return _toStringTimepoint_V17(
                &m->nested.multisig_cancel_as_multi_V17.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V17 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V17 - who */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.balances_set_balance_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V17 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V17.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V17 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V17.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V17 - who */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.balances_force_unreserve_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V17 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* assets_create_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_create_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_create_V17 - admin */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_create_V17.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_create_V17 - min_balance */;
            return _toStringBalance(
                &m->basic.assets_create_V17.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_create_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V17 - owner */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_create_V17.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V17 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_create_V17.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V17 - min_balance */;
            return _toStringCompactu128(
                &m->basic.assets_force_create_V17.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* assets_destroy_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_destroy_V17 - witness */;
            return _toStringDestroyWitness_V17(
                &m->basic.assets_destroy_V17.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* assets_mint_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_mint_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V17 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_mint_V17.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_mint_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* assets_burn_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_burn_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V17 - who */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_burn_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_burn_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V17 - target */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_transfer_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0: /* assets_transfer_keep_alive_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_keep_alive_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_keep_alive_V17 - target */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_transfer_keep_alive_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_keep_alive_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_transfer_keep_alive_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_transfer_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V17 - source */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_transfer_V17.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_force_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_freeze_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V17 - who */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_freeze_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_thaw_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V17 - who */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_thaw_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* assets_freeze_asset_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_freeze_asset_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* assets_thaw_asset_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_thaw_asset_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_ownership_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V17 - owner */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_transfer_ownership_V17.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_team_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V17 - issuer */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_set_team_V17.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V17 - admin */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_set_team_V17.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V17 - freezer */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_set_team_V17.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* assets_set_metadata_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_metadata_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_metadata_V17 - name */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V17.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_metadata_V17 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V17.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_metadata_V17 - decimals */;
            return _toStringu8(
                &m->basic.assets_set_metadata_V17.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* assets_clear_metadata_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_clear_metadata_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0: /* assets_force_set_metadata_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_set_metadata_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_set_metadata_V17 - name */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V17.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_set_metadata_V17 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V17.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_set_metadata_V17 - decimals */;
            return _toStringu8(
                &m->basic.assets_force_set_metadata_V17.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_set_metadata_V17 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_set_metadata_V17.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* assets_force_clear_metadata_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_clear_metadata_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* assets_force_asset_status_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_asset_status_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_asset_status_V17 - owner */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_asset_status_V17.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_asset_status_V17 - issuer */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_asset_status_V17.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_asset_status_V17 - admin */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_asset_status_V17.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_asset_status_V17 - freezer */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_asset_status_V17.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assets_force_asset_status_V17 - min_balance */;
            return _toStringCompactu128(
                &m->basic.assets_force_asset_status_V17.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assets_force_asset_status_V17 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V17.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* assets_force_asset_status_V17 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V17.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* assets_approve_transfer_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_approve_transfer_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_approve_transfer_V17 - delegate */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_approve_transfer_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_approve_transfer_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_approve_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_cancel_approval_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V17 - delegate */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_cancel_approval_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* assets_force_cancel_approval_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_cancel_approval_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_cancel_approval_V17 - owner */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_cancel_approval_V17.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_cancel_approval_V17 - delegate */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_force_cancel_approval_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* assets_transfer_approved_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_approved_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_approved_V17 - owner */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_transfer_approved_V17.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_approved_V17 - destination */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.assets_transfer_approved_V17.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_transfer_approved_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.assets_transfer_approved_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* assets_touch_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_touch_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* assets_refund_V17 - id */;
            return _toStringCompactu32(
                &m->basic.assets_refund_V17.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_V17 - allow_burn */;
            return _toStringbool(
                &m->basic.assets_refund_V17.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V17 - real */;
            return _toStringAccountId_V17(
                &m->nested.proxy_proxy_V17.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V17 - force_proxy_type */;
            return _toStringOptionProxyType_V17(
                &m->nested.proxy_proxy_V17.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V17 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V17 - delegate */;
            return _toStringAccountId_V17(
                &m->basic.proxy_add_proxy_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V17 - proxy_type */;
            return _toStringProxyType_V17(
                &m->basic.proxy_add_proxy_V17.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V17 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V17.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V17 - delegate */;
            return _toStringAccountId_V17(
                &m->basic.proxy_remove_proxy_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V17 - proxy_type */;
            return _toStringProxyType_V17(
                &m->basic.proxy_remove_proxy_V17.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V17 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V17.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V17 - proxy_type */;
            return _toStringProxyType_V17(
                &m->basic.proxy_anonymous_V17.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V17 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V17.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V17 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V17 - spawner */;
            return _toStringAccountId_V17(
                &m->basic.proxy_kill_anonymous_V17.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V17 - proxy_type */;
            return _toStringProxyType_V17(
                &m->basic.proxy_kill_anonymous_V17.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V17 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V17 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V17.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V17 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V17.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V17 - real */;
            return _toStringAccountId_V17(
                &m->basic.proxy_announce_V17.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V17 - call_hash */;
            return _toStringCallHashOf_V17(
                &m->basic.proxy_announce_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V17 - real */;
            return _toStringAccountId_V17(
                &m->basic.proxy_remove_announcement_V17.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V17 - call_hash */;
            return _toStringCallHashOf_V17(
                &m->basic.proxy_remove_announcement_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V17 - delegate */;
            return _toStringAccountId_V17(
                &m->basic.proxy_reject_announcement_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V17 - call_hash */;
            return _toStringCallHashOf_V17(
                &m->basic.proxy_reject_announcement_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V17 - delegate */;
            return _toStringAccountId_V17(
                &m->basic.proxy_proxy_announced_V17.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V17 - real */;
            return _toStringAccountId_V17(
                &m->basic.proxy_proxy_announced_V17.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V17 - force_proxy_type */;
            return _toStringOptionProxyType_V17(
                &m->basic.proxy_proxy_announced_V17.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V17 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V17 - account */;
            return _toStringAccountId_V17(
                &m->basic.identity_add_registrar_V17.account,
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
        case 0: /* identity_request_judgement_V17 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V17.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V17 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V17.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V17 - reg_index */;
            return _toStringRegistrarIndex_V17(
                &m->basic.identity_cancel_request_V17.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V17 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V17 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V17.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V17 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.identity_set_account_id_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V17 - target */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.identity_kill_identity_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V17 - sub */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.identity_remove_sub_V17.sub,
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
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.democracy_propose_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V17 - proposal */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V17 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V17.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V17 - ref_index */;
            return _toStringReferendumIndex_V17(
                &m->basic.democracy_emergency_cancel_V17.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2822: /* module 11 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2823: /* module 11 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V17 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V17.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V17 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V17.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2824: /* module 11 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2825: /* module 11 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V17 - ref_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_referendum_V17.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2826: /* module 11 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V17 - which */;
            return _toStringReferendumIndex_V17(
                &m->basic.democracy_cancel_queued_V17.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2827: /* module 11 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V17 - to */;
            return _toStringAccountId_V17(
                &m->basic.democracy_delegate_V17.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V17 - conviction */;
            return _toStringConviction_V17(
                &m->basic.democracy_delegate_V17.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V17 - balance */;
            return _toStringBalance(
                &m->basic.democracy_delegate_V17.balance,
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
        case 0: /* democracy_note_preimage_V17 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V17.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2831: /* module 11 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V17 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V17.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2832: /* module 11 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V17 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V17.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2833: /* module 11 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V17 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V17.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2834: /* module 11 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V17 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V17.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2835: /* module 11 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V17 - target */;
            return _toStringAccountId_V17(
                &m->basic.democracy_unlock_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2836: /* module 11 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V17 - index */;
            return _toStringReferendumIndex_V17(
                &m->basic.democracy_remove_vote_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2837: /* module 11 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V17 - target */;
            return _toStringAccountId_V17(
                &m->basic.democracy_remove_other_vote_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V17 - index */;
            return _toStringReferendumIndex_V17(
                &m->basic.democracy_remove_other_vote_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2838: /* module 11 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V17 - index */;
            return _toStringReferendumIndex_V17(
                &m->basic.democracy_enact_proposal_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2840: /* module 11 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V17 - prop_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_proposal_V17.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* generalcouncil_set_members_V17 - new_members */;
            return _toStringVecAccountId_V17(
                &m->basic.generalcouncil_set_members_V17.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_set_members_V17 - prime */;
            return _toStringOptionAccountId_V17(
                &m->basic.generalcouncil_set_members_V17.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_set_members_V17 - old_count */;
            return _toStringMemberCount_V17(
                &m->basic.generalcouncil_set_members_V17.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* generalcouncil_execute_V17 - proposal */;
            return _toStringProposal(
                &m->basic.generalcouncil_execute_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_execute_V17 - length_bound */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_execute_V17.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* generalcouncil_propose_V17 - threshold */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_propose_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_propose_V17 - proposal */;
            return _toStringProposal(
                &m->basic.generalcouncil_propose_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_propose_V17 - length_bound */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_propose_V17.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* generalcouncil_vote_V17 - proposal */;
            return _toStringHash(
                &m->basic.generalcouncil_vote_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_vote_V17 - index */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_vote_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_vote_V17 - approve */;
            return _toStringbool(
                &m->basic.generalcouncil_vote_V17.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* generalcouncil_close_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.generalcouncil_close_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncil_close_V17 - index */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_close_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* generalcouncil_close_V17 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.generalcouncil_close_V17.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* generalcouncil_close_V17 - length_bound */;
            return _toStringCompactu32(
                &m->basic.generalcouncil_close_V17.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0: /* generalcouncil_disapprove_proposal_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.generalcouncil_disapprove_proposal_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V17 - new_members */;
            return _toStringVecAccountId_V17(
                &m->basic.technicalcommittee_set_members_V17.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V17 - prime */;
            return _toStringOptionAccountId_V17(
                &m->basic.technicalcommittee_set_members_V17.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V17 - old_count */;
            return _toStringMemberCount_V17(
                &m->basic.technicalcommittee_set_members_V17.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V17 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V17 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V17.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V17 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V17 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V17 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V17.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V17 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V17.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V17 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V17 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V17.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V17 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V17 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.technicalcommittee_close_V17.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V17 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V17.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V17 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V17.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V17 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.treasury_propose_spend_V17.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V17 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V17.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V17 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V17.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_spend_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_spend_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_spend_V17 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.treasury_spend_V17.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_remove_approval_V17 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_remove_approval_V17.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V17 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V17.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V17 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V17.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V17 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V17.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V17 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V17.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_service_overweight_V17 - index */;
            return _toStringOverweightIndex_V17(
                &m->basic.xcmpqueue_service_overweight_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpqueue_service_overweight_V17 - weight_limit */;
            return _toStringWeight_V17(
                &m->basic.xcmpqueue_service_overweight_V17.weight_limit,
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
        case 0: /* xcmpqueue_update_suspend_threshold_V17 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_suspend_threshold_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_drop_threshold_V17 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_drop_threshold_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_resume_threshold_V17 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_resume_threshold_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_threshold_weight_V17 - new_ */;
            return _toStringWeight_V17(
                &m->basic.xcmpqueue_update_threshold_weight_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_weight_restrict_decay_V17 - new_ */;
            return _toStringWeight_V17(
                &m->basic.xcmpqueue_update_weight_restrict_decay_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5640: /* module 22 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_xcmp_max_individual_weight_V17 - new_ */;
            return _toStringWeight_V17(
                &m->basic.xcmpqueue_update_xcmp_max_individual_weight_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* dmpqueue_service_overweight_V17 - index */;
            return _toStringOverweightIndex_V17(
                &m->basic.dmpqueue_service_overweight_V17.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dmpqueue_service_overweight_V17 - weight_limit */;
            return _toStringWeight_V17(
                &m->basic.dmpqueue_service_overweight_V17.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_invulnerables_V17 - new_ */;
            return _toStringVecAccountId_V17(
                &m->basic.collatorselection_set_invulnerables_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_desired_candidates_V17 - max */;
            return _toStringu32(
                &m->basic.collatorselection_set_desired_candidates_V17.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_candidacy_bond_V17 - bond */;
            return _toStringBalance(
                &m->basic.collatorselection_set_candidacy_bond_V17.bond,
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
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_V17 - currency_id */;
            return _toStringCurrencyId_V17(
                &m->basic.xtokens_transfer_V17.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_V17 - amount */;
            return _toStringu128(
                &m->basic.xtokens_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_V17 - dest */;
            return _toStringBoxVersionedMultiLocation_V17(
                &m->basic.xtokens_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xtokens_transfer_V17 - dest_weight */;
            return _toStringWeight_V17(
                &m->basic.xtokens_transfer_V17.dest_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.vesting_vested_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V17 - schedule */;
            return _toStringVestingScheduleOf_V17(
                &m->basic.vesting_vested_transfer_V17.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_update_vesting_schedules_V17 - who */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.vesting_update_vesting_schedules_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_update_vesting_schedules_V17 - vesting_schedules */;
            return _toStringVecVestingScheduleOf_V17(
                &m->basic.vesting_update_vesting_schedules_V17.vesting_schedules,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_claim_for_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.vesting_claim_for_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0: /* loans_add_market_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_add_market_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_add_market_V17 - market */;
            return _toStringMarketBalanceOfT_V17(
                &m->nested.loans_add_market_V17.market,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0: /* loans_activate_market_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_activate_market_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0: /* loans_update_rate_model_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_update_rate_model_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_update_rate_model_V17 - rate_model */;
            return _toStringInterestRateModel_V17(
                &m->nested.loans_update_rate_model_V17.rate_model,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* loans_update_market_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_update_market_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_update_market_V17 - collateral_factor */;
            return _toStringOptionRatio_V17(
                &m->nested.loans_update_market_V17.collateral_factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_update_market_V17 - liquidation_threshold */;
            return _toStringOptionRatio_V17(
                &m->nested.loans_update_market_V17.liquidation_threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* loans_update_market_V17 - reserve_factor */;
            return _toStringOptionRatio_V17(
                &m->nested.loans_update_market_V17.reserve_factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* loans_update_market_V17 - close_factor */;
            return _toStringOptionRatio_V17(
                &m->nested.loans_update_market_V17.close_factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* loans_update_market_V17 - liquidate_incentive_reserved_factor */;
            return _toStringOptionRatio_V17(
                &m->nested.loans_update_market_V17.liquidate_incentive_reserved_factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* loans_update_market_V17 - liquidate_incentive */;
            return _toStringOptionRate_V17(
                &m->nested.loans_update_market_V17.liquidate_incentive,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* loans_update_market_V17 - supply_cap */;
            return _toStringOptionBalance(
                &m->nested.loans_update_market_V17.supply_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 8: /* loans_update_market_V17 - borrow_cap */;
            return _toStringOptionBalance(
                &m->nested.loans_update_market_V17.borrow_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0: /* loans_force_update_market_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_force_update_market_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_force_update_market_V17 - market */;
            return _toStringMarketBalanceOfT_V17(
                &m->nested.loans_force_update_market_V17.market,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0: /* loans_add_reward_V17 - amount */;
            return _toStringBalance(
                &m->nested.loans_add_reward_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0: /* loans_withdraw_missing_reward_V17 - target_account */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.loans_withdraw_missing_reward_V17.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_withdraw_missing_reward_V17 - amount */;
            return _toStringBalance(
                &m->nested.loans_withdraw_missing_reward_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0: /* loans_update_market_reward_speed_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_update_market_reward_speed_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_update_market_reward_speed_V17 - supply_reward_per_block */;
            return _toStringOptionBalance(
                &m->nested.loans_update_market_reward_speed_V17.supply_reward_per_block,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_update_market_reward_speed_V17 - borrow_reward_per_block */;
            return _toStringOptionBalance(
                &m->nested.loans_update_market_reward_speed_V17.borrow_reward_per_block,
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
        case 0: /* loans_claim_reward_for_market_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_claim_reward_for_market_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12810: /* module 50 call 10 */
        switch (itemIdx) {
        case 0: /* loans_mint_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_mint_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_mint_V17 - mint_amount */;
            return _toStringCompactu128(
                &m->nested.loans_mint_V17.mint_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12811: /* module 50 call 11 */
        switch (itemIdx) {
        case 0: /* loans_redeem_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_redeem_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_redeem_V17 - redeem_amount */;
            return _toStringCompactu128(
                &m->nested.loans_redeem_V17.redeem_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12812: /* module 50 call 12 */
        switch (itemIdx) {
        case 0: /* loans_redeem_all_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_redeem_all_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12813: /* module 50 call 13 */
        switch (itemIdx) {
        case 0: /* loans_borrow_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_borrow_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_borrow_V17 - borrow_amount */;
            return _toStringCompactu128(
                &m->nested.loans_borrow_V17.borrow_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12814: /* module 50 call 14 */
        switch (itemIdx) {
        case 0: /* loans_repay_borrow_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_repay_borrow_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_repay_borrow_V17 - repay_amount */;
            return _toStringCompactu128(
                &m->nested.loans_repay_borrow_V17.repay_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12815: /* module 50 call 15 */
        switch (itemIdx) {
        case 0: /* loans_repay_borrow_all_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_repay_borrow_all_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12816: /* module 50 call 16 */
        switch (itemIdx) {
        case 0: /* loans_collateral_asset_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_collateral_asset_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_collateral_asset_V17 - enable */;
            return _toStringbool(
                &m->nested.loans_collateral_asset_V17.enable,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12817: /* module 50 call 17 */
        switch (itemIdx) {
        case 0: /* loans_liquidate_borrow_V17 - borrower */;
            return _toStringAccountId_V17(
                &m->nested.loans_liquidate_borrow_V17.borrower,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_liquidate_borrow_V17 - liquidation_asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_liquidate_borrow_V17.liquidation_asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_liquidate_borrow_V17 - repay_amount */;
            return _toStringCompactu128(
                &m->nested.loans_liquidate_borrow_V17.repay_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* loans_liquidate_borrow_V17 - collateral_asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_liquidate_borrow_V17.collateral_asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12818: /* module 50 call 18 */
        switch (itemIdx) {
        case 0: /* loans_add_reserves_V17 - payer */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.loans_add_reserves_V17.payer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_add_reserves_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_add_reserves_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_add_reserves_V17 - add_amount */;
            return _toStringCompactu128(
                &m->nested.loans_add_reserves_V17.add_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12819: /* module 50 call 19 */
        switch (itemIdx) {
        case 0: /* loans_reduce_reserves_V17 - receiver */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.loans_reduce_reserves_V17.receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_reduce_reserves_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_reduce_reserves_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_reduce_reserves_V17 - reduce_amount */;
            return _toStringCompactu128(
                &m->nested.loans_reduce_reserves_V17.reduce_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12820: /* module 50 call 20 */
        switch (itemIdx) {
        case 0: /* loans_reduce_incentive_reserves_V17 - receiver */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.loans_reduce_incentive_reserves_V17.receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* loans_reduce_incentive_reserves_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->nested.loans_reduce_incentive_reserves_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* loans_reduce_incentive_reserves_V17 - redeem_amount */;
            return _toStringCompactu128(
                &m->nested.loans_reduce_incentive_reserves_V17.redeem_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12821: /* module 50 call 21 */
        switch (itemIdx) {
        case 0: /* loans_update_liquidation_free_collateral_V17 - collaterals */;
            return _toStringVecAssetIdOf_V17(
                &m->nested.loans_update_liquidation_free_collateral_V17.collaterals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* prices_set_price_V17 - asset_id */;
            return _toStringCurrencyId_V17(
                &m->basic.prices_set_price_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* prices_set_price_V17 - price */;
            return _toStringPrice_V17(
                &m->basic.prices_set_price_V17.price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* prices_reset_price_V17 - asset_id */;
            return _toStringCurrencyId_V17(
                &m->basic.prices_reset_price_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13312: /* module 52 call 0 */
        switch (itemIdx) {
        case 0: /* crowdloans_create_vault_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_create_vault_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_create_vault_V17 - ctoken */;
            return _toStringAssetIdOfT_V17(
                &m->basic.crowdloans_create_vault_V17.ctoken,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_create_vault_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_create_vault_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloans_create_vault_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_create_vault_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloans_create_vault_V17 - contribution_strategy */;
            return _toStringContributionStrategy_V17(
                &m->basic.crowdloans_create_vault_V17.contribution_strategy,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloans_create_vault_V17 - cap */;
            return _toStringCompactBalance(
                &m->basic.crowdloans_create_vault_V17.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* crowdloans_create_vault_V17 - end_block */;
            return _toStringBlockNumber(
                &m->basic.crowdloans_create_vault_V17.end_block,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13313: /* module 52 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloans_update_vault_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_update_vault_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_update_vault_V17 - cap */;
            return _toStringOptionBalance(
                &m->basic.crowdloans_update_vault_V17.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_update_vault_V17 - end_block */;
            return _toStringOptionBlockNumber(
                &m->basic.crowdloans_update_vault_V17.end_block,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloans_update_vault_V17 - contribution_strategy */;
            return _toStringOptionContributionStrategy_V17(
                &m->basic.crowdloans_update_vault_V17.contribution_strategy,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13314: /* module 52 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloans_open_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_open_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13315: /* module 52 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloans_contribute_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_contribute_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_contribute_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.crowdloans_contribute_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_contribute_V17 - referral_code */;
            return _toStringVecu8(
                &m->basic.crowdloans_contribute_V17.referral_code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloans_set_vrf_V17 - flag */;
            return _toStringbool(
                &m->basic.crowdloans_set_vrf_V17.flag,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13317: /* module 52 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloans_close_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_close_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13318: /* module 52 call 6 */
        switch (itemIdx) {
        case 0: /* crowdloans_reopen_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_reopen_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13319: /* module 52 call 7 */
        switch (itemIdx) {
        case 0: /* crowdloans_auction_succeeded_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_auction_succeeded_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13320: /* module 52 call 8 */
        switch (itemIdx) {
        case 0: /* crowdloans_auction_failed_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_auction_failed_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13321: /* module 52 call 9 */
        switch (itemIdx) {
        case 0: /* crowdloans_claim_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_claim_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_claim_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_claim_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_claim_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_claim_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13322: /* module 52 call 10 */
        switch (itemIdx) {
        case 0: /* crowdloans_claim_for_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.crowdloans_claim_for_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_claim_for_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_claim_for_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_claim_for_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_claim_for_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloans_claim_for_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_claim_for_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13323: /* module 52 call 11 */
        switch (itemIdx) {
        case 0: /* crowdloans_withdraw_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_withdraw_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_withdraw_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_withdraw_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_withdraw_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_withdraw_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13324: /* module 52 call 12 */
        switch (itemIdx) {
        case 0: /* crowdloans_withdraw_for_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.crowdloans_withdraw_for_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_withdraw_for_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_withdraw_for_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_withdraw_for_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_withdraw_for_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloans_withdraw_for_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_withdraw_for_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13325: /* module 52 call 13 */
        switch (itemIdx) {
        case 0: /* crowdloans_redeem_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_redeem_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_redeem_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_redeem_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_redeem_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_redeem_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloans_redeem_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.crowdloans_redeem_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13326: /* module 52 call 14 */
        switch (itemIdx) {
        case 0: /* crowdloans_slot_expired_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_slot_expired_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13327: /* module 52 call 15 */
        switch (itemIdx) {
        case 0: /* crowdloans_migrate_pending_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_migrate_pending_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13329: /* module 52 call 17 */
        switch (itemIdx) {
        case 0: /* crowdloans_refund_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_refund_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_refund_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_refund_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_refund_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_refund_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13330: /* module 52 call 18 */
        switch (itemIdx) {
        case 0: /* crowdloans_dissolve_vault_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_dissolve_vault_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_dissolve_vault_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_dissolve_vault_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_dissolve_vault_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_dissolve_vault_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13331: /* module 52 call 19 */
        switch (itemIdx) {
        case 0: /* crowdloans_refund_for_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.crowdloans_refund_for_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloans_refund_for_V17 - crowdloan */;
            return _toStringParaId_V17(
                &m->basic.crowdloans_refund_for_V17.crowdloan,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloans_refund_for_V17 - kind */;
            return _toStringChildStorageKind_V17(
                &m->basic.crowdloans_refund_for_V17.kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloans_refund_for_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.crowdloans_refund_for_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloans_refund_for_V17 - lease_start */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_refund_for_V17.lease_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloans_refund_for_V17 - lease_end */;
            return _toStringLeasePeriod_V17(
                &m->basic.crowdloans_refund_for_V17.lease_end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0: /* liquidstaking_stake_V17 - amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_stake_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0: /* liquidstaking_unstake_V17 - liquid_amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_unstake_V17.liquid_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_unstake_V17 - unstake_provider */;
            return _toStringUnstakeProvider_V17(
                &m->nested.liquidstaking_unstake_V17.unstake_provider,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0: /* liquidstaking_update_reserve_factor_V17 - reserve_factor */;
            return _toStringRatio_V17(
                &m->nested.liquidstaking_update_reserve_factor_V17.reserve_factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15363: /* module 60 call 3 */
        switch (itemIdx) {
        case 0: /* liquidstaking_update_staking_ledger_cap_V17 - cap */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_update_staking_ledger_cap_V17.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15364: /* module 60 call 4 */
        switch (itemIdx) {
        case 0: /* liquidstaking_bond_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_bond_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_bond_V17 - amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_bond_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* liquidstaking_bond_V17 - payee */;
            return _toStringRewardDestination_V17(
                &m->nested.liquidstaking_bond_V17.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15365: /* module 60 call 5 */
        switch (itemIdx) {
        case 0: /* liquidstaking_bond_extra_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_bond_extra_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_bond_extra_V17 - amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_bond_extra_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15366: /* module 60 call 6 */
        switch (itemIdx) {
        case 0: /* liquidstaking_unbond_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_unbond_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_unbond_V17 - amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_unbond_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15367: /* module 60 call 7 */
        switch (itemIdx) {
        case 0: /* liquidstaking_rebond_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_rebond_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_rebond_V17 - amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_rebond_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15368: /* module 60 call 8 */
        switch (itemIdx) {
        case 0: /* liquidstaking_withdraw_unbonded_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_withdraw_unbonded_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_withdraw_unbonded_V17 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.liquidstaking_withdraw_unbonded_V17.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15369: /* module 60 call 9 */
        switch (itemIdx) {
        case 0: /* liquidstaking_nominate_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_nominate_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_nominate_V17 - targets */;
            return _toStringVecAccountId_V17(
                &m->nested.liquidstaking_nominate_V17.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15371: /* module 60 call 11 */
        switch (itemIdx) {
        case 0: /* liquidstaking_claim_for_V17 - dest */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.liquidstaking_claim_for_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15372: /* module 60 call 12 */
        switch (itemIdx) {
        case 0: /* liquidstaking_force_set_era_start_block_V17 - block_number */;
            return _toStringBlockNumber(
                &m->nested.liquidstaking_force_set_era_start_block_V17.block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15373: /* module 60 call 13 */
        switch (itemIdx) {
        case 0: /* liquidstaking_force_set_current_era_V17 - era */;
            return _toStringEraIndex_V17(
                &m->nested.liquidstaking_force_set_current_era_V17.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15374: /* module 60 call 14 */
        switch (itemIdx) {
        case 0: /* liquidstaking_force_advance_era_V17 - offset */;
            return _toStringEraIndex_V17(
                &m->nested.liquidstaking_force_advance_era_V17.offset,
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
    case 15376: /* module 60 call 16 */
        switch (itemIdx) {
        case 0: /* liquidstaking_force_set_staking_ledger_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_force_set_staking_ledger_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_force_set_staking_ledger_V17 - staking_ledger */;
            return _toStringStakingLedgerAccountIdBalanceOfT_V17(
                &m->nested.liquidstaking_force_set_staking_ledger_V17.staking_ledger,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15377: /* module 60 call 17 */
        switch (itemIdx) {
        case 0: /* liquidstaking_set_current_era_V17 - era */;
            return _toStringEraIndex_V17(
                &m->nested.liquidstaking_set_current_era_V17.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_set_current_era_V17 - proof */;
            return _toStringVecVecu8(
                &m->nested.liquidstaking_set_current_era_V17.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15378: /* module 60 call 18 */
        switch (itemIdx) {
        case 0: /* liquidstaking_set_staking_ledger_V17 - derivative_index */;
            return _toStringDerivativeIndex_V17(
                &m->nested.liquidstaking_set_staking_ledger_V17.derivative_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_set_staking_ledger_V17 - staking_ledger */;
            return _toStringStakingLedgerAccountIdBalanceOfT_V17(
                &m->nested.liquidstaking_set_staking_ledger_V17.staking_ledger,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* liquidstaking_set_staking_ledger_V17 - proof */;
            return _toStringVecVecu8(
                &m->nested.liquidstaking_set_staking_ledger_V17.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15379: /* module 60 call 19 */
        switch (itemIdx) {
        case 0: /* liquidstaking_reduce_reserves_V17 - receiver */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->nested.liquidstaking_reduce_reserves_V17.receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstaking_reduce_reserves_V17 - reduce_amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_reduce_reserves_V17.reduce_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15380: /* module 60 call 20 */
        switch (itemIdx) {
        case 0: /* liquidstaking_cancel_unstake_V17 - amount */;
            return _toStringCompactu128(
                &m->nested.liquidstaking_cancel_unstake_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17920: /* module 70 call 0 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_add_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.generalcouncilmembership_add_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17921: /* module 70 call 1 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_remove_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.generalcouncilmembership_remove_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17922: /* module 70 call 2 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_swap_member_V17 - remove */;
            return _toStringAccountId_V17(
                &m->basic.generalcouncilmembership_swap_member_V17.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* generalcouncilmembership_swap_member_V17 - add */;
            return _toStringAccountId_V17(
                &m->basic.generalcouncilmembership_swap_member_V17.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17923: /* module 70 call 3 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_reset_members_V17 - members */;
            return _toStringVecAccountId_V17(
                &m->basic.generalcouncilmembership_reset_members_V17.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17924: /* module 70 call 4 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_change_key_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.generalcouncilmembership_change_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        case 0: /* generalcouncilmembership_set_prime_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.generalcouncilmembership_set_prime_V17.who,
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
        case 0: /* technicalcommitteemembership_add_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.technicalcommitteemembership_add_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18177: /* module 71 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_remove_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.technicalcommitteemembership_remove_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18178: /* module 71 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_swap_member_V17 - remove */;
            return _toStringAccountId_V17(
                &m->basic.technicalcommitteemembership_swap_member_V17.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_swap_member_V17 - add */;
            return _toStringAccountId_V17(
                &m->basic.technicalcommitteemembership_swap_member_V17.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18179: /* module 71 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_reset_members_V17 - members */;
            return _toStringVecAccountId_V17(
                &m->basic.technicalcommitteemembership_reset_members_V17.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18180: /* module 71 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_change_key_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.technicalcommitteemembership_change_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18181: /* module 71 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_set_prime_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.technicalcommitteemembership_set_prime_V17.who,
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
        case 0: /* oraclemembership_add_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.oraclemembership_add_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0: /* oraclemembership_remove_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.oraclemembership_remove_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        case 0: /* oraclemembership_swap_member_V17 - remove */;
            return _toStringAccountId_V17(
                &m->basic.oraclemembership_swap_member_V17.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* oraclemembership_swap_member_V17 - add */;
            return _toStringAccountId_V17(
                &m->basic.oraclemembership_swap_member_V17.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18435: /* module 72 call 3 */
        switch (itemIdx) {
        case 0: /* oraclemembership_reset_members_V17 - members */;
            return _toStringVecAccountId_V17(
                &m->basic.oraclemembership_reset_members_V17.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18436: /* module 72 call 4 */
        switch (itemIdx) {
        case 0: /* oraclemembership_change_key_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.oraclemembership_change_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18437: /* module 72 call 5 */
        switch (itemIdx) {
        case 0: /* oraclemembership_set_prime_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.oraclemembership_set_prime_V17.who,
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
        case 0: /* liquidstakingagentsmembership_add_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.liquidstakingagentsmembership_add_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_remove_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.liquidstakingagentsmembership_remove_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_swap_member_V17 - remove */;
            return _toStringAccountId_V17(
                &m->basic.liquidstakingagentsmembership_swap_member_V17.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* liquidstakingagentsmembership_swap_member_V17 - add */;
            return _toStringAccountId_V17(
                &m->basic.liquidstakingagentsmembership_swap_member_V17.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_reset_members_V17 - members */;
            return _toStringVecAccountId_V17(
                &m->basic.liquidstakingagentsmembership_reset_members_V17.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_change_key_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.liquidstakingagentsmembership_change_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0: /* liquidstakingagentsmembership_set_prime_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.liquidstakingagentsmembership_set_prime_V17.who,
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
        case 0: /* bridgemembership_add_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.bridgemembership_add_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18945: /* module 74 call 1 */
        switch (itemIdx) {
        case 0: /* bridgemembership_remove_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.bridgemembership_remove_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18946: /* module 74 call 2 */
        switch (itemIdx) {
        case 0: /* bridgemembership_swap_member_V17 - remove */;
            return _toStringAccountId_V17(
                &m->basic.bridgemembership_swap_member_V17.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridgemembership_swap_member_V17 - add */;
            return _toStringAccountId_V17(
                &m->basic.bridgemembership_swap_member_V17.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18947: /* module 74 call 3 */
        switch (itemIdx) {
        case 0: /* bridgemembership_reset_members_V17 - members */;
            return _toStringVecAccountId_V17(
                &m->basic.bridgemembership_reset_members_V17.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18948: /* module 74 call 4 */
        switch (itemIdx) {
        case 0: /* bridgemembership_change_key_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.bridgemembership_change_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18949: /* module 74 call 5 */
        switch (itemIdx) {
        case 0: /* bridgemembership_set_prime_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.bridgemembership_set_prime_V17.who,
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
        case 0: /* crowdloansautomatorsmembership_add_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_add_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19201: /* module 75 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_remove_member_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_remove_member_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19202: /* module 75 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_swap_member_V17 - remove */;
            return _toStringAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_swap_member_V17.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloansautomatorsmembership_swap_member_V17 - add */;
            return _toStringAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_swap_member_V17.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19203: /* module 75 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_reset_members_V17 - members */;
            return _toStringVecAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_reset_members_V17.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19204: /* module 75 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_change_key_V17 - new_ */;
            return _toStringAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_change_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 19205: /* module 75 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloansautomatorsmembership_set_prime_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.crowdloansautomatorsmembership_set_prime_V17.who,
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
    case 20480: /* module 80 call 0 */
        switch (itemIdx) {
        case 0: /* amm_add_liquidity_V17 - pair */;
            return _toStringAssetIdOfAssetIdOf_V17(
                &m->basic.amm_add_liquidity_V17.pair,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* amm_add_liquidity_V17 - desired_amounts */;
            return _toStringBalanceOfBalanceOf_V17(
                &m->basic.amm_add_liquidity_V17.desired_amounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* amm_add_liquidity_V17 - minimum_amounts */;
            return _toStringBalanceOfBalanceOf_V17(
                &m->basic.amm_add_liquidity_V17.minimum_amounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 20481: /* module 80 call 1 */
        switch (itemIdx) {
        case 0: /* amm_remove_liquidity_V17 - pair */;
            return _toStringAssetIdOfAssetIdOf_V17(
                &m->basic.amm_remove_liquidity_V17.pair,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* amm_remove_liquidity_V17 - liquidity */;
            return _toStringCompactu128(
                &m->basic.amm_remove_liquidity_V17.liquidity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 20482: /* module 80 call 2 */
        switch (itemIdx) {
        case 0: /* amm_create_pool_V17 - pair */;
            return _toStringAssetIdOfAssetIdOf_V17(
                &m->basic.amm_create_pool_V17.pair,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* amm_create_pool_V17 - liquidity_amounts */;
            return _toStringBalanceOfBalanceOf_V17(
                &m->basic.amm_create_pool_V17.liquidity_amounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* amm_create_pool_V17 - lptoken_receiver */;
            return _toStringAccountId_V17(
                &m->basic.amm_create_pool_V17.lptoken_receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* amm_create_pool_V17 - lp_token_id */;
            return _toStringAssetIdOf_V17(
                &m->basic.amm_create_pool_V17.lp_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 20736: /* module 81 call 0 */
        switch (itemIdx) {
        case 0: /* ammroute_swap_exact_tokens_for_tokens_V17 - route */;
            return _toStringVecAssetIdOf_V17(
                &m->basic.ammroute_swap_exact_tokens_for_tokens_V17.route,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* ammroute_swap_exact_tokens_for_tokens_V17 - amount_in */;
            return _toStringCompactu128(
                &m->basic.ammroute_swap_exact_tokens_for_tokens_V17.amount_in,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* ammroute_swap_exact_tokens_for_tokens_V17 - min_amount_out */;
            return _toStringCompactu128(
                &m->basic.ammroute_swap_exact_tokens_for_tokens_V17.min_amount_out,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 20737: /* module 81 call 1 */
        switch (itemIdx) {
        case 0: /* ammroute_swap_tokens_for_exact_tokens_V17 - route */;
            return _toStringVecAssetIdOf_V17(
                &m->basic.ammroute_swap_tokens_for_exact_tokens_V17.route,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* ammroute_swap_tokens_for_exact_tokens_V17 - amount_out */;
            return _toStringCompactu128(
                &m->basic.ammroute_swap_tokens_for_exact_tokens_V17.amount_out,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* ammroute_swap_tokens_for_exact_tokens_V17 - max_amount_in */;
            return _toStringCompactu128(
                &m->basic.ammroute_swap_tokens_for_exact_tokens_V17.max_amount_in,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 20992: /* module 82 call 0 */
        switch (itemIdx) {
        case 0: /* currencyadapter_force_set_lock_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.currencyadapter_force_set_lock_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* currencyadapter_force_set_lock_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.currencyadapter_force_set_lock_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* currencyadapter_force_set_lock_V17 - amount */;
            return _toStringCompactu128(
                &m->basic.currencyadapter_force_set_lock_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 20993: /* module 82 call 1 */
        switch (itemIdx) {
        case 0: /* currencyadapter_force_remove_lock_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.currencyadapter_force_remove_lock_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* currencyadapter_force_remove_lock_V17 - who */;
            return _toStringAccountId_V17(
                &m->basic.currencyadapter_force_remove_lock_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23040: /* module 90 call 0 */
        switch (itemIdx) {
        case 0: /* bridge_register_chain_V17 - chain_id */;
            return _toStringChainId_V17(
                &m->basic.bridge_register_chain_V17.chain_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23041: /* module 90 call 1 */
        switch (itemIdx) {
        case 0: /* bridge_unregister_chain_V17 - chain_id */;
            return _toStringChainId_V17(
                &m->basic.bridge_unregister_chain_V17.chain_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23042: /* module 90 call 2 */
        switch (itemIdx) {
        case 0: /* bridge_register_bridge_token_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->basic.bridge_register_bridge_token_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_register_bridge_token_V17 - bridge_token */;
            return _toStringBridgeToken_V17(
                &m->basic.bridge_register_bridge_token_V17.bridge_token,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23043: /* module 90 call 3 */
        switch (itemIdx) {
        case 0: /* bridge_unregister_bridge_token_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_unregister_bridge_token_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23044: /* module 90 call 4 */
        switch (itemIdx) {
        case 0: /* bridge_set_bridge_token_fee_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_set_bridge_token_fee_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_set_bridge_token_fee_V17 - new_fee */;
            return _toStringBalance(
                &m->basic.bridge_set_bridge_token_fee_V17.new_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23045: /* module 90 call 5 */
        switch (itemIdx) {
        case 0: /* bridge_set_bridge_token_status_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_set_bridge_token_status_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_set_bridge_token_status_V17 - enable */;
            return _toStringbool(
                &m->basic.bridge_set_bridge_token_status_V17.enable,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23046: /* module 90 call 6 */
        switch (itemIdx) {
        case 0: /* bridge_set_bridge_token_cap_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_set_bridge_token_cap_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_set_bridge_token_cap_V17 - bridge_type */;
            return _toStringBridgeType_V17(
                &m->basic.bridge_set_bridge_token_cap_V17.bridge_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bridge_set_bridge_token_cap_V17 - new_cap */;
            return _toStringBalance(
                &m->basic.bridge_set_bridge_token_cap_V17.new_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23047: /* module 90 call 7 */
        switch (itemIdx) {
        case 0: /* bridge_clean_cap_accumulated_value_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_clean_cap_accumulated_value_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_clean_cap_accumulated_value_V17 - bridge_type */;
            return _toStringBridgeType_V17(
                &m->basic.bridge_clean_cap_accumulated_value_V17.bridge_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23048: /* module 90 call 8 */
        switch (itemIdx) {
        case 0: /* bridge_teleport_V17 - dest_id */;
            return _toStringChainId_V17(
                &m->basic.bridge_teleport_V17.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_teleport_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_teleport_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bridge_teleport_V17 - to */;
            return _toStringTeleAccount_V17(
                &m->basic.bridge_teleport_V17.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* bridge_teleport_V17 - amount */;
            return _toStringBalance(
                &m->basic.bridge_teleport_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23049: /* module 90 call 9 */
        switch (itemIdx) {
        case 0: /* bridge_materialize_V17 - src_id */;
            return _toStringChainId_V17(
                &m->basic.bridge_materialize_V17.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_materialize_V17 - src_nonce */;
            return _toStringChainNonce_V17(
                &m->basic.bridge_materialize_V17.src_nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bridge_materialize_V17 - bridge_token_id */;
            return _toStringCurrencyId_V17(
                &m->basic.bridge_materialize_V17.bridge_token_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* bridge_materialize_V17 - to */;
            return _toStringAccountId_V17(
                &m->basic.bridge_materialize_V17.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* bridge_materialize_V17 - amount */;
            return _toStringBalance(
                &m->basic.bridge_materialize_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* bridge_materialize_V17 - favour */;
            return _toStringbool(
                &m->basic.bridge_materialize_V17.favour,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23296: /* module 91 call 0 */
        switch (itemIdx) {
        case 0: /* emergencyshutdown_toggle_pallet_V17 - pallet_idx */;
            return _toStringu8(
                &m->basic.emergencyshutdown_toggle_pallet_V17.pallet_idx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23297: /* module 91 call 1 */
        switch (itemIdx) {
        case 0: /* emergencyshutdown_toggle_call_V17 - pallet_idx */;
            return _toStringu8(
                &m->basic.emergencyshutdown_toggle_call_V17.pallet_idx,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* emergencyshutdown_toggle_call_V17 - call_idx */;
            return _toStringu8(
                &m->basic.emergencyshutdown_toggle_call_V17.call_idx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23552: /* module 92 call 0 */
        switch (itemIdx) {
        case 0: /* farming_create_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_create_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_create_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_create_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_create_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_create_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_create_V17 - cool_down_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_create_V17.cool_down_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23553: /* module 92 call 1 */
        switch (itemIdx) {
        case 0: /* farming_set_pool_status_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_set_pool_status_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_set_pool_status_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_set_pool_status_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_set_pool_status_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_set_pool_status_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_set_pool_status_V17 - is_active */;
            return _toStringbool(
                &m->basic.farming_set_pool_status_V17.is_active,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23554: /* module 92 call 2 */
        switch (itemIdx) {
        case 0: /* farming_set_pool_cool_down_duration_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_set_pool_cool_down_duration_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_set_pool_cool_down_duration_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_set_pool_cool_down_duration_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_set_pool_cool_down_duration_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_set_pool_cool_down_duration_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_set_pool_cool_down_duration_V17 - cool_down_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_set_pool_cool_down_duration_V17.cool_down_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23555: /* module 92 call 3 */
        switch (itemIdx) {
        case 0: /* farming_reset_pool_unlock_height_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_reset_pool_unlock_height_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_reset_pool_unlock_height_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_reset_pool_unlock_height_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_reset_pool_unlock_height_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_reset_pool_unlock_height_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23556: /* module 92 call 4 */
        switch (itemIdx) {
        case 0: /* farming_deposit_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_deposit_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_deposit_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_deposit_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_deposit_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_deposit_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_deposit_V17 - amount */;
            return _toStringu128(
                &m->basic.farming_deposit_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23557: /* module 92 call 5 */
        switch (itemIdx) {
        case 0: /* farming_withdraw_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_withdraw_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_withdraw_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_withdraw_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_withdraw_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_withdraw_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_withdraw_V17 - amount */;
            return _toStringu128(
                &m->basic.farming_withdraw_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23558: /* module 92 call 6 */
        switch (itemIdx) {
        case 0: /* farming_redeem_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_redeem_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_redeem_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_redeem_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_redeem_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_redeem_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23559: /* module 92 call 7 */
        switch (itemIdx) {
        case 0: /* farming_claim_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_claim_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_claim_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_claim_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_claim_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_claim_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23560: /* module 92 call 8 */
        switch (itemIdx) {
        case 0: /* farming_dispatch_reward_V17 - asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_dispatch_reward_V17.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* farming_dispatch_reward_V17 - reward_asset */;
            return _toStringAssetIdOfT_V17(
                &m->basic.farming_dispatch_reward_V17.reward_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* farming_dispatch_reward_V17 - lock_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_dispatch_reward_V17.lock_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* farming_dispatch_reward_V17 - payer */;
            return _toStringLookupasStaticLookupSource_V17(
                &m->basic.farming_dispatch_reward_V17.payer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* farming_dispatch_reward_V17 - amount */;
            return _toStringu128(
                &m->basic.farming_dispatch_reward_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* farming_dispatch_reward_V17 - reward_duration */;
            return _toStringBlockNumber(
                &m->basic.farming_dispatch_reward_V17.reward_duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23808: /* module 93 call 0 */
        switch (itemIdx) {
        case 0: /* xcmhelper_update_xcm_weight_fee_V17 - xcm_call */;
            return _toStringXcmCall_V17(
                &m->basic.xcmhelper_update_xcm_weight_fee_V17.xcm_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmhelper_update_xcm_weight_fee_V17 - xcm_weight_fee_misc */;
            return _toStringXcmWeightFeeMiscWeightBalanceOfT_V17(
                &m->basic.xcmhelper_update_xcm_weight_fee_V17.xcm_weight_fee_misc,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 24067: /* module 94 call 3 */
        switch (itemIdx) {
        case 0: /* streaming_set_minimum_deposit_V17 - asset_id */;
            return _toStringAssetIdOfT_V17(
                &m->basic.streaming_set_minimum_deposit_V17.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* streaming_set_minimum_deposit_V17 - minimum_deposit */;
            return _toStringBalance(
                &m->basic.streaming_set_minimum_deposit_V17.minimum_deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* parachainsystem_authorize_upgrade_V17 - code_hash */;
            return _toStringHash(
                &m->basic.parachainsystem_authorize_upgrade_V17.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* parachainsystem_enact_authorized_upgrade_V17 - code */;
            return _toStringVecu8(
                &m->basic.parachainsystem_enact_authorized_upgrade_V17.code,
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

bool _getMethod_ItemIsExpert_V17(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V17(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: // Timestamp:Set
    case 512: // Utility:Batch
    case 514: // Utility:Batch all
    case 516: // Utility:Force batch
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
    case 1793: // Proxy:Add proxy
    case 1794: // Proxy:Remove proxy
    case 1795: // Proxy:Remove proxies
    case 1796: // Proxy:Anonymous
    case 1797: // Proxy:Kill anonymous
    case 1798: // Proxy:Announce
    case 1799: // Proxy:Remove announcement
    case 1800: // Proxy:Reject announcement
    case 1801: // Proxy:Proxy announced
    case 2048: // Identity:Add registrar
    case 2051: // Identity:Clear identity
    case 2052: // Identity:Request judgement
    case 2053: // Identity:Cancel request
    case 2054: // Identity:Set fee
    case 2055: // Identity:Set account id
    case 2058: // Identity:Kill identity
    case 2061: // Identity:Remove sub
    case 2062: // Identity:Quit sub
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
    case 3587: // Treasury:Spend
    case 3588: // Treasury:Remove approval
    case 4096: // Preimage:Note preimage
    case 4097: // Preimage:Unnote preimage
    case 4098: // Preimage:Request preimage
    case 4099: // Preimage:Unrequest preimage
    case 5632: // XcmpQueue:Service overweight
    case 5633: // XcmpQueue:Suspend xcm execution
    case 5634: // XcmpQueue:Resume xcm execution
    case 5635: // XcmpQueue:Update suspend threshold
    case 5636: // XcmpQueue:Update drop threshold
    case 5637: // XcmpQueue:Update resume threshold
    case 5638: // XcmpQueue:Update threshold weight
    case 5639: // XcmpQueue:Update weight restrict decay
    case 5640: // XcmpQueue:Update xcmp max individual weight
    case 5888: // DmpQueue:Service overweight
    case 7936: // CollatorSelection:Set invulnerables
    case 7937: // CollatorSelection:Set desired candidates
    case 7938: // CollatorSelection:Set candidacy bond
    case 7939: // CollatorSelection:Register as candidate
    case 7940: // CollatorSelection:Leave intent
    case 8192: // Session:Set keys
    case 8193: // Session:Purge keys
    case 11008: // XTokens:Transfer
    case 11776: // Vesting:Claim
    case 11777: // Vesting:Vested transfer
    case 11778: // Vesting:Update vesting schedules
    case 11779: // Vesting:Claim for
    case 13056: // Prices:Set price
    case 13057: // Prices:Reset price
    case 13312: // Crowdloans:Create vault
    case 13313: // Crowdloans:Update vault
    case 13314: // Crowdloans:Open
    case 13315: // Crowdloans:Contribute
    case 13316: // Crowdloans:Set vrf
    case 13317: // Crowdloans:Close
    case 13318: // Crowdloans:Reopen
    case 13319: // Crowdloans:Auction succeeded
    case 13320: // Crowdloans:Auction failed
    case 13321: // Crowdloans:Claim
    case 13322: // Crowdloans:Claim for
    case 13323: // Crowdloans:Withdraw
    case 13324: // Crowdloans:Withdraw for
    case 13325: // Crowdloans:Redeem
    case 13326: // Crowdloans:Slot expired
    case 13327: // Crowdloans:Migrate pending
    case 13329: // Crowdloans:Refund
    case 13330: // Crowdloans:Dissolve vault
    case 13331: // Crowdloans:Refund for
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
    case 20480: // AMM:Add liquidity
    case 20481: // AMM:Remove liquidity
    case 20482: // AMM:Create pool
    case 20736: // AMMRoute:Swap exact tokens for tokens
    case 20737: // AMMRoute:Swap tokens for exact tokens
    case 20992: // CurrencyAdapter:Force set lock
    case 20993: // CurrencyAdapter:Force remove lock
    case 23040: // Bridge:Register chain
    case 23041: // Bridge:Unregister chain
    case 23042: // Bridge:Register bridge token
    case 23043: // Bridge:Unregister bridge token
    case 23044: // Bridge:Set bridge token fee
    case 23045: // Bridge:Set bridge token status
    case 23046: // Bridge:Set bridge token cap
    case 23047: // Bridge:Clean cap accumulated value
    case 23048: // Bridge:Teleport
    case 23049: // Bridge:Materialize
    case 23296: // EmergencyShutdown:Toggle pallet
    case 23297: // EmergencyShutdown:Toggle call
    case 23552: // Farming:Create
    case 23553: // Farming:Set pool status
    case 23554: // Farming:Set pool cool down duration
    case 23555: // Farming:Reset pool unlock height
    case 23556: // Farming:Deposit
    case 23557: // Farming:Withdraw
    case 23558: // Farming:Redeem
    case 23559: // Farming:Claim
    case 23560: // Farming:Dispatch reward
    case 23808: // XcmHelper:Update xcm weight fee
    case 24067: // Streaming:Set minimum deposit
    case 5122: // ParachainSystem:Authorize upgrade
    case 5123: // ParachainSystem:Enact authorized upgrade
        return false;
    default:
        return true;
    }
}
