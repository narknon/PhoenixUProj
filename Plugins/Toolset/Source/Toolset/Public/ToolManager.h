#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ToolManager.generated.h"

class ATool;

UCLASS(Blueprintable)
class TOOLSET_API UToolManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ATool>> ToolList;
    
public:
    UToolManager();
};

