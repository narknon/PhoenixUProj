#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapIconList.generated.h"

class UMapIconInstance;

UCLASS(Blueprintable)
class UMapIconList : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapIconInstance*> Icons;
    
public:
    UMapIconList();
};

