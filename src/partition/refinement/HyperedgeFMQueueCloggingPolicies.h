/***************************************************************************
 *  Copyright (C) 2014 Sebastian Schlag <sebastian.schlag@kit.edu>
 **************************************************************************/

#ifndef SRC_PARTITION_REFINEMENT_HYPEREDGEFMQUEUECLOGGINGPOLICIES_H_
#define SRC_PARTITION_REFINEMENT_HYPEREDGEFMQUEUECLOGGINGPOLICIES_H_

namespace partition {
struct OnlyRemoveIfBothQueuesClogged {
  template <typename Queue>
  static bool removeCloggingQueueEntries(bool pq0_eligible, bool pq1_eligible,
  template <typename Queue>
  static bool removeCloggingQueueEntries(bool pq0_eligible, bool pq1_eligible,
                                         Queue& pq0, Queue& pq1) {
    if (!pq0_eligible && !pq1_eligible) {
      if (!pq0->empty()) {
        DBG(false, " Removing HE/HN " << pq0->max() << " from PQ 0");
        pq0->deleteMax();
      }
      if (!pq1->empty()) {
        DBG(false, " Removing HE/HN " << pq1->max() << " from PQ 1");
        pq1->deleteMax();
      }
      return true;
    }
    return false;
  }

  protected:
  ~OnlyRemoveIfBothQueuesClogged() { }
};

struct RemoveOnlyTheCloggingEntry {
  template <typename Queue>
  static bool removeCloggingQueueEntries(bool pq0_eligible, bool pq1_eligible,
  template <typename Queue>
  static bool removeCloggingQueueEntries(bool pq0_eligible, bool pq1_eligible,
                                         Queue& pq0, Queue& pq1) {
    if (!pq0_eligible && !pq0->empty()) {
      DBG(false, " Removing HE/HN " << pq0->max() << " from PQ 0");
      pq0->deleteMax();
      return true;
    }
    if (!pq1_eligible && !pq1->empty()) {
      DBG(false, " Removing HE/HN " << pq1->max() << " from PQ 1");
      pq1->deleteMax();
      return true;
    }
    return false;
  }

  protected:
  ~RemoveOnlyTheCloggingEntry() { }
};
} // namespace partition

#endif  // SRC_PARTITION_REFINEMENT_HYPEREDGEFMQUEUECLOGGINGPOLICIES_H_