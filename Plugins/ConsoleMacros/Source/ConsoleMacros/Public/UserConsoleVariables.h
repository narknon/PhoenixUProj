#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UserConsoleVariableBool.h"
#include "UserConsoleVariableFloat.h"
#include "UserConsoleVariableInt.h"
#include "UserConsoleVariables.generated.h"

UCLASS(Blueprintable)
class CONSOLEMACROS_API UUserConsoleVariables : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUserConsoleVariableBool> Bools;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUserConsoleVariableFloat> Floats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUserConsoleVariableInt> Ints;
    
    UUserConsoleVariables();
};

