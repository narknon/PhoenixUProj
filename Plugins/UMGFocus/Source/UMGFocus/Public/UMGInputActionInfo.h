#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "EUMGInputAction.h"
#include "UMGInputActionInfo.generated.h"

USTRUCT(BlueprintType)
struct FUMGInputActionInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUMGInputAction InputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EInputEvent> InputEvent;
    
    UMGFOCUS_API FUMGInputActionInfo();
};
FORCEINLINE uint32 GetTypeHash(const FUMGInputActionInfo) { return 0; }

