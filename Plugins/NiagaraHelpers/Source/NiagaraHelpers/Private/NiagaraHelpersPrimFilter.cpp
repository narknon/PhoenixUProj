#include "NiagaraHelpersPrimFilter.h"

FNiagaraHelpersPrimFilter::FNiagaraHelpersPrimFilter() {
    this->Rule = ENiagaraHelpersPrimRule::DoNotSpawn;
    this->MatchMode = ENiagaraHelpersPrimMatchMode::Exact;
}

