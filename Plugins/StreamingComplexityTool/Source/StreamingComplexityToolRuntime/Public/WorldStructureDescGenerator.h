#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldStructureDescGenerator.generated.h"

class UWorld;

UCLASS(Blueprintable)
class STREAMINGCOMPLEXITYTOOLRUNTIME_API UWorldStructureDescGenerator : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWorld*> PendingParses;
    
public:
    UWorldStructureDescGenerator();
};

