#include "llvm/Instructions.h"

#include "insttypefiinstselector.h"


namespace llfi {
bool InstTypeFIInstSelector::isInstFITarget(Instruction *inst) {
  unsigned opcode = inst->getOpcode();
  if (opcodelist->find(opcode) != opcodelist->end()) {
    return true;
  }
  return false;
}

}