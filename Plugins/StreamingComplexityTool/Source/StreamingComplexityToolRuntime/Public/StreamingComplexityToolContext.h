#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StreamingComplexityToolContext.generated.h"

class ULevel;

UCLASS(Blueprintable)
class STREAMINGCOMPLEXITYTOOLRUNTIME_API UStreamingComplexityToolContext : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, ULevel*> Levels;
    
public:
    UStreamingComplexityToolContext();
};

