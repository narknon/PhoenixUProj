#pragma once
#include "CoreMinimal.h"
#include "ModExtension.h"
#include "RPGModExtensionNotify.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGModExtensionNotify : public UModExtension {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ModAppliedMessage {"ModApplied"};
    
    URPGModExtensionNotify();
};

