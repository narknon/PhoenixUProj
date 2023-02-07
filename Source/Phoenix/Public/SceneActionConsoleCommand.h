#pragma once
#include "CoreMinimal.h"
#include "SceneActionConsoleCommand.generated.h"

USTRUCT(BlueprintType)
struct FSceneActionConsoleCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Command;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ValueOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ValueOnExit;
    
    PHOENIX_API FSceneActionConsoleCommand();
};

