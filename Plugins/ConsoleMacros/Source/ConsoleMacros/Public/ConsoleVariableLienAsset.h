#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConsoleVariableLienEntry.h"
#include "ConsoleVariableLienAsset.generated.h"

UCLASS(Blueprintable)
class CONSOLEMACROS_API UConsoleVariableLienAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleVariableLienEntry> ConsoleVariables;
    
    UConsoleVariableLienAsset();
};

