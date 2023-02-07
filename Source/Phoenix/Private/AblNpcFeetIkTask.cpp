#include "AblNpcFeetIkTask.h"

UAblNpcFeetIkTask::UAblNpcFeetIkTask() {
    this->IkOnTaskStartEvent = EAblNpcReactEventAction::Ignore;
    this->IkOnTaskEndEvent = EAblNpcReactEventAction::Ignore;
}

