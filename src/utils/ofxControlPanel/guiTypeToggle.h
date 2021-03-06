#pragma once

#include "guiBaseObject.h"
#include "guiColor.h"
#include "simpleColor.h"
#include "guiValue.h"

class guiTypeToggle : public guiBaseObject
{
    public:

        //------------------------------------------------
        void setup(string toggleName, bool defaultVal){
            value.addValue( (int)defaultVal, 0, 1);
            name = toggleName;
                        bShowText = false;
        }

        //-----------------------------------------------.
        void updateGui(float x, float y, bool firstHit, bool isRelative){
            if(!firstHit)return;

            if( state == SG_STATE_SELECTED){
                if( value.getValueI() == 0 ){
                    value.setValue(1, 0);
                }else{
                    value.setValue(0, 0);
                }
            }
        }

        //-----------------------------------------------.
        void render() {
            ofPushStyle();
                glPushMatrix();
                    guiBaseObject::renderText();

                    //draw the background
                    ofFill();
                    glColor4fv(bgColor.getColorF());
                    ofDrawRectangle(hitArea.x, hitArea.y, hitArea.width, hitArea.height);

                    //draw the outline
                    ofNoFill();
                    glColor4fv(outlineColor.getColorF());
                    ofDrawRectangle(hitArea.x, hitArea.y, hitArea.width, hitArea.height);

                    if( value.getValueI() == 1){
                        ofFill();
                    }else{
                        ofNoFill();
                    }

                    glColor4fv(fgColor.getColorF());
                    ofDrawRectangle(hitArea.x+3, hitArea.y+3, -6 + hitArea.width, -6 + hitArea.height);

                    glColor4fv(textColor.getColorF());
                    displayText.renderString(name, hitArea.x + 6 + hitArea.width,hitArea.y + hitArea.height -2);

                glPopMatrix();
            ofPopStyle();
        }
};
