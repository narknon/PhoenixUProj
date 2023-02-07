#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OverlapEffectsHandler.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandler : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProcessEvents;
    
public:
    UOverlapEffectsHandler();
};

