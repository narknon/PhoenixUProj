#pragma once
#include "CoreMinimal.h"
#include "MapScreenBase.h"
#include "HogsmeadeMapScreen.generated.h"

class UMapHogsmeade;

UCLASS(Blueprintable, EditInlineNew)
class UHogsmeadeMapScreen : public UMapScreenBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapHogsmeade* HogsmeadeMap;
    
    UHogsmeadeMapScreen();
    UFUNCTION(BlueprintCallable)
    UMapHogsmeade* GetMap();
    
};

