#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "Object_Direct.generated.h"

class UObject;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_Direct : public UObjectProvider {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Object;
    
    UObject_Direct();
};

