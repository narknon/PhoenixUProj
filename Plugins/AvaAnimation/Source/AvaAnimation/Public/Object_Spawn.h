#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "Object_Spawn.generated.h"

class UObject;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_Spawn : public UObjectProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ParentObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* ObjectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ObjectName;
    
    UObject_Spawn();
};

