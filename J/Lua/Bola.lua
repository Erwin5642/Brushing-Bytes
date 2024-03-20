--[[
    GD50 2018
    Pong Remake

    -- Bola Class --

    Author: Colton Ogden
    cogden@cs50.harvard.edu

    Represents a Bola which will bounce back and forth between jogadors
    and walls until it passes a left or right boundary of the screen,
    scoring a point for the opponent.
]]

Bola = Class{}

function Bola:init(x, y, largura, altura)
    self.x = x
    self.y = y
    self.largura = largura
    self.altura = altura

    -- these variables are for keeping track of our velocity on both the
    -- X and Y axis, since the Bola can move in two dimensions
    self.dy = 0
    self.dx = 0
end

--[[
    Expects a jogador as an argument and returns true or false, depending
    on whether their rectangles overlap.
]]
function Bola:collides(jogador)
    -- first, check to see if the left edge of either is farther to the right
    -- than the right edge of the other
    if self.x > jogador.x + jogador.largura or jogador.x > self.x + self.largura then
        return false
    end

    -- then check to see if the bottom edge of either is higher than the top
    -- edge of the other
    if self.y > jogador.y + jogador.altura or jogador.y > self.y + self.altura then
        return false
    end 

    -- if the above aren't true, they're overlapping
    return true
end

--[[
    Places the Bola in the middle of the screen, with no movement.
]]
function Bola:reset()
    self.x = LARGURA_JANELA / 2 - 2
    self.y = ALTURA_JANELA / 2 - 2
    self.dx = 0
    self.dy = 0
end

function Bola:update(dt)
    self.x = self.x + self.dx * dt
    self.y = self.y + self.dy * dt
end

function Bola:render()
    love.graphics.rectangle('fill', self.x, self.y, self.largura, self.altura)
end