# Parallel  14.185.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Assets

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` admin <br/>`Balance` min_balance <br/> |
|Force create |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`bool` is_sufficient <br/>`Compactu128` min_balance <br/> |
|Destroy |    | :heavy_check_mark: |   | `Compactu32` id <br/>`DestroyWitness` witness <br/> |
|Mint |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` beneficiary <br/>`Compactu128` amount <br/> |
|Burn |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/>`Compactu128` amount <br/> |
|Transfer |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` target <br/>`Compactu128` amount <br/> |
|Transfer keep alive |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` target <br/>`Compactu128` amount <br/> |
|Force transfer |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`Compactu128` amount <br/> |
|Freeze |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/> |
|Thaw |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/> |
|Freeze asset |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Thaw asset |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Transfer ownership |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Set metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/> |
|Clear metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Force set metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/>`bool` is_frozen <br/> |
|Force clear metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Force asset status |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`Compactu128` min_balance <br/>`bool` is_sufficient <br/>`bool` is_frozen <br/> |
|Approve transfer |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` delegate <br/>`Compactu128` amount <br/> |
|Cancel approval |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` delegate <br/> |
|Force cancel approval |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` delegate <br/> |
|Transfer approved |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` destination <br/>`Compactu128` amount <br/> |
|Touch |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Refund |    | :heavy_check_mark: |   | `Compactu32` id <br/>`bool` allow_burn <br/> |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |
|Add proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxies |    | :heavy_check_mark: |   |  |
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|Kill anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> |
|Announce |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Remove announcement |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Reject announcement |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> |
|Proxy announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    | :heavy_check_mark: |   |  |
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountId` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> |
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Remove sub |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` sub <br/> |
|Quit sub |    | :heavy_check_mark: |   |  |

## Sudo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Sudo |    | :heavy_check_mark: |   | `Call` call <br/> |
|Sudo unchecked weight |    | :heavy_check_mark: |   | `Call` call <br/>`Weight` weight <br/> |
|Set key |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` new_ <br/> |
|Sudo as |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Call` call <br/> |

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`CompactBalance` amount <br/> |
|Second |    | :heavy_check_mark: |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> |
|Vote |    |   |   | `Compactu32` ref_index <br/>`AccountVote` vote <br/> |
|Emergency cancel |    | :heavy_check_mark: |   | `ReferendumIndex` ref_index <br/> |
|External propose |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |
|External propose majority |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |
|External propose default |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |
|Fast track |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> |
|Veto external |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |
|Cancel referendum |    | :heavy_check_mark: |   | `Compactu32` ref_index <br/> |
|Cancel queued |    | :heavy_check_mark: |   | `ReferendumIndex` which <br/> |
|Delegate |    | :heavy_check_mark: |   | `AccountId` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> |
|Undelegate |    | :heavy_check_mark: |   |  |
|Clear public proposals |    | :heavy_check_mark: |   |  |
|Note preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Note preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Reap preimage |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> |
|Unlock |    | :heavy_check_mark: |   | `AccountId` target <br/> |
|Remove vote |    | :heavy_check_mark: |   | `ReferendumIndex` index <br/> |
|Remove other vote |    | :heavy_check_mark: |   | `AccountId` target <br/>`ReferendumIndex` index <br/> |
|Enact proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> |
|Cancel proposal |    | :heavy_check_mark: |   | `Compactu32` prop_index <br/> |

## GeneralCouncil

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    | :heavy_check_mark: |   | `Vecu8` bytes <br/> |
|Unnote preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Request preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Unrequest preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |

## XcmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |
|Suspend xcm execution |    | :heavy_check_mark: |   |  |
|Resume xcm execution |    | :heavy_check_mark: |   |  |
|Update suspend threshold |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Update drop threshold |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Update resume threshold |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Update threshold weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> |
|Update weight restrict decay |    | :heavy_check_mark: |   | `Weight` new_ <br/> |
|Update xcmp max individual weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> |

## DmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |

## PolkadotXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> |
|Teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Execute |    |   |   | `BoxVersionedXcmTasSysConfigCall` message <br/>`Weight` max_weight <br/> |
|Force xcm version |    |   |   | `BoxMultiLocation` location <br/>`XcmVersion` xcm_version <br/> |
|Force default xcm version |    |   |   | `OptionXcmVersion` maybe_xcm_version <br/> |
|Force subscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Force unsubscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Limited reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |
|Limited teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |

## CumulusXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## CollatorSelection

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set invulnerables |    | :heavy_check_mark: |   | `VecAccountId` new_ <br/> |
|Set desired candidates |    | :heavy_check_mark: |   | `u32` max <br/> |
|Set candidacy bond |    | :heavy_check_mark: |   | `Balance` bond <br/> |
|Register as candidate |    | :heavy_check_mark: |   |  |
|Leave intent |    | :heavy_check_mark: |   |  |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Oracle

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Feed values |    |   |   | `VecTupleOracleKeyOracleValue` values <br/> |

## XTokens

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer |    |   |   | `CurrencyId` currency_id <br/>`Balance` amount <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multiasset |    |   |   | `BoxVersionedMultiAsset` asset <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer with fee |    |   |   | `CurrencyId` currency_id <br/>`Balance` amount <br/>`Balance` fee <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multiasset with fee |    |   |   | `BoxVersionedMultiAsset` asset <br/>`BoxVersionedMultiAsset` fee <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multicurrencies |    |   |   | `VecTupleCurrencyIdBalance` currencies <br/>`u32` fee_item <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |
|Transfer multiassets |    |   |   | `BoxVersionedMultiAssets` assets <br/>`u32` fee_item <br/>`BoxVersionedMultiLocation` dest <br/>`Weight` dest_weight <br/> |

## OrmlXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send as sovereign |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   |  |
|Vested transfer |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`VestingScheduleOf` schedule <br/> |
|Update vesting schedules |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`VecVestingScheduleOf` vesting_schedules <br/> |
|Claim for |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/> |

## Loans

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add market |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`MarketBalanceOfT` market <br/> |
|Activate market |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/> |
|Update rate model |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`InterestRateModel` rate_model <br/> |
|Update market |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Ratio` collateral_factor <br/>`Ratio` liquidation_threshold <br/>`Ratio` reserve_factor <br/>`Ratio` close_factor <br/>`Ratio` liquidate_incentive_reserved_factor <br/>`Rate` liquidate_incentive <br/>`Compactu128` supply_cap <br/>`Compactu128` borrow_cap <br/> |
|Force update market |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`MarketBalanceOfT` market <br/> |
|Add reward |    | :heavy_check_mark: |   | `Balance` amount <br/> |
|Withdraw missing reward |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target_account <br/>`Balance` amount <br/> |
|Update market reward speed |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Balance` supply_reward_per_block <br/>`Balance` borrow_reward_per_block <br/> |
|Claim reward |    | :heavy_check_mark: |   |  |
|Claim reward for market |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/> |
|Mint |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Compactu128` mint_amount <br/> |
|Redeem |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Compactu128` redeem_amount <br/> |
|Redeem all |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/> |
|Borrow |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Compactu128` borrow_amount <br/> |
|Repay borrow |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Compactu128` repay_amount <br/> |
|Repay borrow all |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/> |
|Collateral asset |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`bool` enable <br/> |
|Liquidate borrow |    | :heavy_check_mark: |   | `AccountId` borrower <br/>`AssetIdOfT` liquidation_asset_id <br/>`Compactu128` repay_amount <br/>`AssetIdOfT` collateral_asset_id <br/> |
|Add reserves |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` payer <br/>`AssetIdOfT` asset_id <br/>`Compactu128` add_amount <br/> |
|Reduce reserves |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` receiver <br/>`AssetIdOfT` asset_id <br/>`Compactu128` reduce_amount <br/> |
|Reduce incentive reserves |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` receiver <br/>`AssetIdOfT` asset_id <br/>`Compactu128` redeem_amount <br/> |

## Prices

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set price |    | :heavy_check_mark: |   | `CurrencyId` asset_id <br/>`Price` price <br/> |
|Reset price |    | :heavy_check_mark: |   | `CurrencyId` asset_id <br/> |

## Crowdloans

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create vault |    |   |   | `ParaId` crowdloan <br/>`AssetIdOfT` ctoken <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/>`ContributionStrategy` contribution_strategy <br/>`Compactu128` cap <br/>`BlockNumber` end_block <br/> |
|Update vault |    |   |   | `ParaId` crowdloan <br/>`OptionBalanceOfT` cap <br/>`OptionBlockNumberForT` end_block <br/>`OptionContributionStrategy` contribution_strategy <br/> |
|Open |    |   |   | `ParaId` crowdloan <br/> |
|Contribute |    |   |   | `ParaId` crowdloan <br/>`Compactu128` amount <br/>`Vecu8` referral_code <br/> |
|Set vrf |    |   |   | `bool` flag <br/> |
|Close |    |   |   | `ParaId` crowdloan <br/> |
|Reopen |    |   |   | `ParaId` crowdloan <br/> |
|Auction succeeded |    |   |   | `ParaId` crowdloan <br/> |
|Auction failed |    |   |   | `ParaId` crowdloan <br/> |
|Claim |    |   |   | `ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/> |
|Claim for |    |   |   | `LookupasStaticLookupSource` dest <br/>`ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/> |
|Withdraw |    |   |   | `ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/> |
|Withdraw for |    |   |   | `LookupasStaticLookupSource` dest <br/>`ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/> |
|Redeem |    |   |   | `ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/>`Compactu128` amount <br/> |
|Slot expired |    |   |   | `ParaId` crowdloan <br/> |
|Migrate pending |    |   |   | `ParaId` crowdloan <br/> |
|Notification received |    |   |   | `QueryId` query_id <br/>`Response` response <br/> |
|Refund |    |   |   | `ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/> |
|Dissolve vault |    |   |   | `ParaId` crowdloan <br/>`LeasePeriod` lease_start <br/>`LeasePeriod` lease_end <br/> |

## LiquidStaking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Stake |    | :heavy_check_mark: |   | `Compactu128` amount <br/> |
|Unstake |    | :heavy_check_mark: |   | `Compactu128` liquid_amount <br/> |
|Update reserve factor |    | :heavy_check_mark: |   | `Ratio` reserve_factor <br/> |
|Update staking ledger cap |    | :heavy_check_mark: |   | `Compactu128` cap <br/> |
|Bond |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`Compactu128` amount <br/>`RewardDestination` payee <br/> |
|Bond extra |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`Compactu128` amount <br/> |
|Unbond |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`Compactu128` amount <br/> |
|Rebond |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`Compactu128` amount <br/> |
|Withdraw Unbonded |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`u32` num_slashing_spans <br/> |
|Nominate |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`VecAccountId` targets <br/> |
|Notification received |    |   |   | `QueryId` query_id <br/>`Response` response <br/> |
|Claim for |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/> |
|Force set era start block |    | :heavy_check_mark: |   | `BlockNumber` block_number <br/> |
|Force set current era |    | :heavy_check_mark: |   | `EraIndex` era <br/> |
|Force advance era |    | :heavy_check_mark: |   | `EraIndex` offset <br/> |
|Force matching |    | :heavy_check_mark: |   |  |
|Force set staking ledger |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`StakingLedgerAccountIdBalanceOfT` staking_ledger <br/> |
|Set current era |    | :heavy_check_mark: |   | `EraIndex` era <br/>`VecVecu8` proof <br/> |
|Set staking ledger |    | :heavy_check_mark: |   | `DerivativeIndex` derivative_index <br/>`StakingLedgerAccountIdBalanceOfT` staking_ledger <br/>`VecVecu8` proof <br/> |
|Reduce reserves |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` receiver <br/>`Compactu128` reduce_amount <br/> |

## GeneralCouncilMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## TechnicalCommitteeMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## OracleMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## LiquidStakingAgentsMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## BridgeMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## CrowdloansAutomatorsMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## AMM

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add liquidity |    | :heavy_check_mark: |   | `AssetIdOfAssetIdOf` pair <br/>`BalanceOfBalanceOf` desired_amounts <br/>`BalanceOfBalanceOf` minimum_amounts <br/> |
|Remove liquidity |    | :heavy_check_mark: |   | `AssetIdOfAssetIdOf` pair <br/>`Compactu128` liquidity <br/> |
|Create pool |    | :heavy_check_mark: |   | `AssetIdOfAssetIdOf` pair <br/>`BalanceOfBalanceOf` liquidity_amounts <br/>`AccountId` lptoken_receiver <br/>`AssetIdOf` lp_token_id <br/> |

## AMMRoute

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Swap exact tokens for tokens |    |   |   | `VecAssetIdOf` route <br/>`Compactu128` amount_in <br/>`Compactu128` min_amount_out <br/> |
|Swap tokens for exact tokens |    |   |   | `VecAssetIdOf` route <br/>`Compactu128` amount_out <br/>`Compactu128` max_amount_in <br/> |

## CurrencyAdapter

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force set lock |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AccountId` who <br/>`Compactu128` amount <br/> |
|Force remove lock |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AccountId` who <br/> |

## Bridge

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register chain |    |   |   | `ChainId` chain_id <br/> |
|Unregister chain |    |   |   | `ChainId` chain_id <br/> |
|Register bridge token |    |   |   | `AssetIdOfT` asset_id <br/>`BridgeToken` bridge_token <br/> |
|Unregister bridge token |    |   |   | `CurrencyId` bridge_token_id <br/> |
|Set bridge token fee |    |   |   | `CurrencyId` bridge_token_id <br/>`Balance` new_fee <br/> |
|Set bridge token status |    | :heavy_check_mark: |   | `CurrencyId` bridge_token_id <br/>`bool` enable <br/> |
|Set bridge token cap |    |   |   | `CurrencyId` bridge_token_id <br/>`BridgeType` bridge_type <br/>`Balance` new_cap <br/> |
|Clean cap accumulated value |    |   |   | `CurrencyId` bridge_token_id <br/>`BridgeType` bridge_type <br/> |
|Teleport |    |   |   | `ChainId` dest_id <br/>`CurrencyId` bridge_token_id <br/>`TeleAccount` to <br/>`Balance` amount <br/> |
|Materialize |    |   |   | `ChainId` src_id <br/>`ChainNonce` src_nonce <br/>`CurrencyId` bridge_token_id <br/>`AccountId` to <br/>`Balance` amount <br/>`bool` favour <br/> |

## EmergencyShutdown

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Toggle pallet |    | :heavy_check_mark: |   | `u8` pallet_idx <br/> |
|Toggle call |    | :heavy_check_mark: |   | `u8` pallet_idx <br/>`u8` call_idx <br/> |

## Farming

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/>`BlockNumber` cool_down_duration <br/> |
|Set pool status |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/>`bool` is_active <br/> |
|Set pool cool down duration |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/>`BlockNumber` cool_down_duration <br/> |
|Reset pool unlock height |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/> |
|Deposit |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/>`Balance` amount <br/> |
|Withdraw |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/>`Balance` amount <br/> |
|Redeem |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/> |
|Claim |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/> |
|Dispatch reward |    | :heavy_check_mark: |   | `AssetIdOfT` asset <br/>`AssetIdOfT` reward_asset <br/>`BlockNumber` lock_duration <br/>`LookupasStaticLookupSource` payer <br/>`Balance` amount <br/>`BlockNumber` reward_duration <br/> |

## XcmHelper

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Update xcm weight fee |    |   |   | `XcmCall` xcm_call <br/>`XcmWeightFeeMiscWeightBalanceOfT` xcm_weight_fee_misc <br/> |
|Withdraw |    |   |   | `ParaId` para_id <br/>`AccountIdOfT` para_account_id <br/>`BoxCallIdOfT` notify <br/> |
|Contribute |    |   |   | `ParaId` para_id <br/>`Balance` amount <br/>`AccountIdOfT` who <br/>`BoxCallIdOfT` notify <br/> |
|Bond |    |   |   | `Balance` amount <br/>`RewardDestinationAccountIdOfT` payee <br/>`AccountIdOfT` stash <br/>`u16` index <br/>`BoxCallIdOfT` notify <br/> |
|Bond extra |    |   |   | `Balance` amount <br/>`AccountIdOfT` stash <br/>`u16` index <br/>`BoxCallIdOfT` notify <br/> |
|Unbond |    |   |   | `Balance` amount <br/>`u16` index <br/>`BoxCallIdOfT` notify <br/> |
|Rebond |    |   |   | `Balance` amount <br/>`u16` index <br/>`BoxCallIdOfT` notify <br/> |
|Withdraw Unbonded |    |   |   | `u32` num_slashing_spans <br/>`AccountIdOfT` para_account_id <br/>`u16` index <br/>`BoxCallIdOfT` notify <br/> |
|Nominate |    |   |   | `VecAccountIdOfT` targets <br/>`u16` index <br/>`BoxCallIdOfT` notify <br/> |
|Send as sovereign |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> |
|Ump transact |    |   |   | `DoubleEncodedTuple` call <br/>`Weight` weight <br/>`BoxMultiLocation` beneficiary <br/>`Balance` fees <br/> |
|Add proxy |    |   |   | `AccountId` delegate <br/>`OptionProxyType` proxy_type <br/>`BlockNumber` delay <br/>`BoxCallIdOfT` notify <br/> |
|Remove proxy |    |   |   | `AccountId` delegate <br/>`OptionProxyType` proxy_type <br/>`BlockNumber` delay <br/>`BoxCallIdOfT` notify <br/> |

## Streaming

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    |   |   | `AccountOfT` recipient <br/>`Balance` deposit <br/>`AssetIdOfT` asset_id <br/>`Timestamp` start_time <br/>`Timestamp` end_time <br/>`bool` cancellable <br/> |
|Cancel |    |   |   | `StreamId` stream_id <br/> |
|Withdraw |    |   |   | `StreamId` stream_id <br/>`Balance` amount <br/> |
|Set minimum deposit |    | :heavy_check_mark: |   | `AssetIdOfT` asset_id <br/>`Balance` minimum_deposit <br/> |

## AssetRegistry

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register asset |    |   |   | `AssetId` asset_id <br/>`AssetType` asset_type <br/> |
|Update asset units per second |    |   |   | `AssetType` asset_type <br/>`u128` units_per_second <br/> |
|Update asset type |    |   |   | `AssetId` asset_id <br/>`AssetType` new_asset_type <br/> |
|Remove fee payment asset |    |   |   | `AssetType` asset_type <br/> |
|Deregister asset |    |   |   | `AssetId` asset_id <br/> |

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation data |    |   |   | `ParachainInherentData` data <br/> |
|Sudo send upward message |    |   |   | `UpwardMessage` message <br/> |
|Authorize upgrade |    | :heavy_check_mark: |   | `Hash` code_hash <br/> |
|Enact authorized upgrade |    | :heavy_check_mark: |   | `Vecu8` code <br/> |

