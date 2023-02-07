#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPFilmName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPFilmName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPFilmName();
};

