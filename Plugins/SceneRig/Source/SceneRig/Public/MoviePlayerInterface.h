#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MoviePlayerInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UMoviePlayerInterface : public UInterface {
    GENERATED_BODY()
};

class IMoviePlayerInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetOpacity(float Opacity) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetForegroundOpacity(float Opacity) const;
    
};

