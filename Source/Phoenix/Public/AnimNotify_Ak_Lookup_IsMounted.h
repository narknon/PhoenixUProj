#pragma once
#include "CoreMinimal.h"
#include "AnimNotify_AkEvent_Lookup.h"
#include "AnimNotify_Ak_Lookup_IsMounted.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class PHOENIX_API UAnimNotify_Ak_Lookup_IsMounted : public UAnimNotify_AkEvent_Lookup {
    GENERATED_BODY()
public:
    UAnimNotify_Ak_Lookup_IsMounted();
};

